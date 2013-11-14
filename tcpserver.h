#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QIODevice>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);
    void run();

signals:
    
public slots:
    void newConnection();
    void readyRead();

private:
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // TCPSERVER_H
