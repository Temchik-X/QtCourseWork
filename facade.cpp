#include "facade.h"

Facade::Facade(QObject *parent)
{

}

//метод для получения данных
void Facade::getData(Agreement *value, QString *code, QString *name, int *cost)
{
    *cost = 0;
    //создаем указатель на объект базового класса и присваиваем ему экземпляр нужного нам объекта
    Insurance* calculator = InsuranceFactory::construct(value);
    //если объект существует
    if (calculator != nullptr){
        *cost = calculator->getCostInsurance(value);
        *code = calculator->getCodeInsurance();
        *name = calculator->getNameInsurance();
        delete calculator;
        return;
    }
    //если нужного объекта не существует
    delete calculator;
    return;


}
