#ifndef TRANSPORTHANDLER_H
#define TRANSPORTHANDLER_H

#include <QWebChannelAbstractTransport>
#include <QWebSocket>
#include <QJsonObject>
#include "logger.h"

class TransportHandler : public QWebChannelAbstractTransport
{
    Q_OBJECT
public:
    TransportHandler(QWebSocket* socket);

public slots:
    void sendMessage(const QJsonObject &message) override;

private slots:
    void textMessageReceived(const QString &message);

signals:
    void disconnected();

private:
    QWebSocket* m_socket;
    Logger* m_log;
};

#endif // TRANSPORTHANDLER_H
