#include "agreement.h"

//конструктор объекта договора
Agreement::Agreement(QString NAgr, QString NPass, QString Code, InsuranceType Type, QString Date, int Time)
{
    aNAgr = NAgr;
    aNPass = NPass;
    aCode = Code;
    aDate = Date;
    aTime = Time;
    aType = Type;

}
//методы для получения полей
QString Agreement::numArg()
{
    return aNAgr;
}

QString Agreement::numPass()
{
    return aNPass;
}

QString Agreement::Code()
{
    return aCode;
}

QString Agreement::Date()
{
    return aDate;
}

QString Agreement::Ins()
{
    return aIns;
}

QString Agreement::IName()
{
    return aIName;
}

Agreement::InsuranceType Agreement::Type()
{
    return aType;
}

int Agreement::Time()
{
    return aTime;
}

int Agreement::Cost()
{
    return aCost;
}
//методы для задания значений некоторым полям
void Agreement::setIns(QString s)
{
    aIns = s;
}

void Agreement::setIName(QString s)
{
    aIName = s;
}

void Agreement::setCost(int n)
{
    aCost = n;
}
