#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent) :
    QObject(parent)
{
}

void TcpServer::run()
{
    server = new QTcpServer;

    socket = new QTcpSocket;

    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!server->listen(QHostAddress::LocalHost, 4444))
    {
        qDebug() << "ERROR: " << server->errorString();
    }
    else
    {
        qDebug() << "Server started.\nListening...";
    }

}

void TcpServer::newConnection()
{
    socket = server->nextPendingConnection();

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    qDebug() << "Get connected";

    /*socket->write("Hello client!");
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
*/

}

void TcpServer::readyRead()
{
    qDebug() << "Got read-signal," << socket->bytesAvailable() << "bytes.";
    QByteArray input = socket->readAll();
    qDebug() << "Input:" << input << "\nReturning...";
    socket->write(input);
    socket->close();
    qDebug() << "Returned.\nListening...";
}

