#ifndef INSURANCE_H
#define INSURANCE_H

#include <QObject>
#include "agreement.h"

//базывой класс
class Insurance
{
public:
    virtual int getCostInsurance(Agreement* value) = 0;
    virtual QString getNameInsurance() = 0;
    virtual QString getCodeInsurance() = 0;
};

//производные классы
class InsCar: public Insurance
{
public:
    int getCostInsurance(Agreement* value) override{
        return 10000 + 10000 * 6/value->Time();
    }
    QString getNameInsurance() override{return iName;}
    QString getCodeInsurance() override{return iCode;}
private:
    QString iCode = "001";
    QString iName = "Страхование транспорта";
};
class InsLife: public Insurance
{
public:
    int getCostInsurance(Agreement* value) override{
        return 40000 + 15000 * 6/value->Time();
    }
    QString getNameInsurance() override{return iName;}
    QString getCodeInsurance() override{return iCode;}
private:
    QString iCode = "005";
    QString iName = "Страхование Транспорта";
};
class InsHome: public Insurance
{
public:
    int getCostInsurance(Agreement* value) override{
        return 30000 + 12000 * 6/value->Time();
    }
    QString getNameInsurance() override{return iName;}
    QString getCodeInsurance() override{return iCode;}
private:
    QString iCode = "016";
    QString iName = "Страхование жилья";
};
class InsLiability: public Insurance
{
public:
    int getCostInsurance(Agreement* value) override{
        return 50000 + 30000 * 6/value->Time();
    }
    QString getNameInsurance() override{return iName;}
    QString getCodeInsurance() override{return iCode;}
private:
    QString iCode = "065";
    QString iName = "Страхование ответственности";
};

//фабричный метод
class InsuranceFactory{
public:
    static Insurance* construct(Agreement* value);
};

#endif // INSURANCE_H
