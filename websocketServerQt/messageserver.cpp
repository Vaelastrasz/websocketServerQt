#include "messageserver.h"

MessageServer::MessageServer(QWebSocketServer *server, QObject *parent) :
    QObject(parent), m_server(server) {

    connect(m_server, &QWebSocketServer::newConnection,
            this, &MessageServer::handleNewConnection);
}

void MessageServer::handleNewConnection() {

    m_clientList.append(new TransportHandler(m_server->nextPendingConnection()));
}
