#include "messageserver.h"

MessageServer::MessageServer(QWebSocketServer *server, QObject *parent) :
    QObject(parent), m_server(server) {

    m_log = Logger::getInstance();
    connect(m_server, &QWebSocketServer::newConnection,
            this, &MessageServer::handleNewConnection);
}

bool MessageServer::connectServer() {

    if (m_server->listen(QHostAddress::LocalHost, 1234)) {
        m_log->addToLog("Server started successfully!", llSuccess);
        return true;
    }
    m_log->addToLog("Server start failed!", llError);
    return false;
}

void MessageServer::stopServer() {

    m_server->close();
    closeAllConnections();
    m_log->addToLog("Server stopped successfully!", llSuccess);
}

QStringList MessageServer::getClientList() {

    QStringList result;
    for (QString key : m_clientList.keys())
        result.append(key);
    return result;
}

void MessageServer::handleNewConnection() {

    QWebSocket* tmpClientSocket = m_server->nextPendingConnection();
    connect(tmpClientSocket, &QWebSocket::disconnected,
            this, &MessageServer::handleDisconnect);

    m_clientList.insert(tmpClientSocket->peerAddress().toString(), new TransportHandler(tmpClientSocket));
    emit usersChanged();

    m_log->addToLog("New user connected: " + tmpClientSocket->peerAddress().toString(), llInformation);
}

void MessageServer::handleDisconnect() {

    QWebSocket* disconnUser = (QWebSocket*)sender();
    m_clientList.erase(m_clientList.find(disconnUser->peerAddress().toString()));
    emit usersChanged();

    m_log->addToLog("User disconnected: " + disconnUser->peerAddress().toString(), llInformation);
    disconnUser->deleteLater();
}

void MessageServer::closeAllConnections() {

    for (TransportHandler* transport : m_clientList.values())
        transport->deleteLater();
}
