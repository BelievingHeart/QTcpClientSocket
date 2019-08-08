//
// Created by rocke on 2019/8/8.
//

#include "TcpClientSocket.h"
#include <QDebug>

bool TcpClientSocket::connectToHost(const QHostAddress& address, quint16 port) {
    _socket->connectToHost(address, port);

    bool connectSuccessfully = true;
    if (_socket->waitForConnected(3000)) {
        qDebug() << "Connect to server successfully";
    }else{
        connectSuccessfully = false;
        qDebug() << "Failed to connect to server";
    }

    return connectSuccessfully;
}

QByteArray TcpClientSocket::query(const char * input) {
    qDebug() << "Writing" << input << "to server...";

    _socket->write(input);
    _socket->waitForBytesWritten(3000);

    QByteArray output;
    if (_socket->waitForReadyRead(3000)) {
        output = _socket->readAll();
    }else{
        output = "Invalid query to server";
    }

    return output;
}

TcpClientSocket::TcpClientSocket(QObject *parent) : QObject(parent), _socket(new QTcpSocket(this)) {
}
