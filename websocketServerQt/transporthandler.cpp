#include "transporthandler.h"

TransportHandler::TransportHandler(QWebSocket* socket):
 QWebChannelAbstractTransport(socket), m_socket(socket){

    connect(socket, &QWebSocket::textMessageReceived,
            this, &TransportHandler::textMessageReceived);
    m_log = Logger::getInstance();
}

void TransportHandler::sendMessage(const QJsonObject &message) {

    Q_UNUSED(message);
}

void TransportHandler::textMessageReceived(const QString &message) {

    m_log->addToLog("Msg recv: " + message, llInformation);
//    sendMessage();
}
