#include "client.h"

Client::Client()
{

}
//методы для получения полей
QString Client::name()
{
    return cName;
}

QString Client::pass()
{
    return cPass;
}

QString Client::phone()
{
    return cPhone;
}

int Client::count()
{
    return cCount;
}
//метод для задания значений определенному полю
void Client::setCount(int n)
{
    cCount = n;
}
//конструктор объекта клиент
Client::Client(QString Name, QString Pass, QString Phone, int Count)
{
    cName = Name;
    cPass = Pass;
    cPhone = Phone;
    cCount = Count;
}
