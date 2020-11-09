#ifndef MESSAGESERVER_H
#define MESSAGESERVER_H

#include <QObject>
#include <QtWebSockets>
#include <QWebSocketServer>
#include <QList>
#include <QMap>
#include "transporthandler.h"

class MessageServer : public QObject
{
    Q_OBJECT
public:
    MessageServer(QWebSocketServer *server, QObject *parent = 0);

private:
    QList<TransportHandler*> m_clientList;
    QWebSocketServer* m_server;

signals:
    void clientConnected(TransportHandler* clientTransport);

private slots:
    void handleNewConnection();
};

#endif // MESSAGESERVER_H
