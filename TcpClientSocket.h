//
// Created by rocke on 2019/8/8.
//

#ifndef QTCPCLIENTSOCKET_TCPCLIENTSOCKET_H
#define QTCPCLIENTSOCKET_TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>

class TcpClientSocket : public QObject{
    Q_OBJECT

    QTcpSocket* _socket;

public:
    bool connectToHost(const QHostAddress& address, quint16 port);

    explicit TcpClientSocket(QObject *parent = nullptr);

    QByteArray query(const char *);


};


#endif //QTCPCLIENTSOCKET_TCPCLIENTSOCKET_H
