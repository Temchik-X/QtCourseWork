#include "subsidiary.h"

Subsidiary Subsidiary::clone()
{
    return Subsidiary(this->fCode, this->fName, this->fAdress, this->fPhone);
}

//методы для получения значений полей
QString Subsidiary::Code()
{
    return fCode;
}

QString Subsidiary::Name()
{
    return fName;
}

QString Subsidiary::Adress()
{
    return fAdress;
}

QString Subsidiary::Phone()
{
    return fPhone;
}
//конструктор объекта филиал
Subsidiary::Subsidiary(QString Code, QString Name, QString Adress, QString Phone){
    fCode = Code;
    fName = Name;
    fAdress = Adress;
    fPhone = Phone;
}

