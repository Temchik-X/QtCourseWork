#ifndef AGREEMENT_H
#define AGREEMENT_H

#include <QObject>
//класс договора
class Agreement : public QObject
{
public:
    enum InsuranceType{
        Car,
        Life,
        Home,
        Liability
    };
    explicit Agreement(QObject *parent = nullptr);
    Agreement(QString NAgr, QString NPass, QString Code, InsuranceType Type, QString Date, int Time);
    QString numArg();
    QString numPass();
    QString Code();
    QString Date();
    QString Ins();
    QString IName();
    InsuranceType Type();
    int Time();
    int Cost();
    void setIns(QString s);
    void setIName(QString s);
    void setCost(int n);
private:
    QString aNAgr;
    QString aNPass;
    InsuranceType aType;
    QString aCode;
    QString aDate;
    QString aIns;
    QString aIName;
    int aTime;
    int aCost;
};

#endif // AGREEMENT_H
