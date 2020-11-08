#ifndef MESSAGESERVER_H
#define MESSAGESERVER_H

#include <QObject>
#include <QtWebSockets>
#include <QList>

class MessageServer : public QObject
{
    Q_OBJECT
public:
    explicit MessageServer(QObject *parent = 0);

private:
    QList<QWebSocket*> m_clientList;
signals:

public slots:
};

#endif // MESSAGESERVER_H
