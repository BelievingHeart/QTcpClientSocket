//
// This is an auxiliary program to https://github.com/BelievingHeart/QMultithreadedTCPServer
//

#include <QHostAddress>
#include "TcpClientSocket.h"

int main(int argc, char *argv[]) {
    TcpClientSocket socket;
    QString address = "127.0.0.1";
    if(!socket.connectToHost(QHostAddress(address), 1234)){
        return 1;
    }
    QByteArray response = socket.query("hello");

    qDebug() << "Accept:" << response << "from server";

    return 0;
}