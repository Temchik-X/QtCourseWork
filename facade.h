#ifndef FACADE_H
#define FACADE_H

#include <QObject>
#include "agreement.h"
#include "insurance.h"

//класс паттерна фасад
class Facade
{
public:
    explicit Facade(QObject *parent = nullptr);
    static void getData(Agreement *value, QString *code, QString *name, int *cost);
};

#endif // FACADE_H
