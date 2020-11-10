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
    bool connectServer();
    void stopServer();
    QStringList getClientList();

signals:
    void clientConnected(TransportHandler* clientTransport);
    void usersChanged();

private slots:
    void handleNewConnection();
    void handleDisconnect();

private:
    void closeAllConnections();

    QMap<QString, TransportHandler*> m_clientList;
    QWebSocketServer* m_server;
    Logger* m_log;
};

#endif // MESSAGESERVER_H
