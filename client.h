#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

//класс клиента
class Client : public QObject
{
public:
    Client();
    Client(QString Name, QString Pass, QString Phone, int Count);
    explicit Client(QObject *parent = nullptr);
    QString name();
    QString pass();
    QString phone();
    int count();
    void setCount(int n);
private:
    QString cName;
    QString cPass;
    QString cPhone;
    int cCount;
};

#endif // CLIENT_H
