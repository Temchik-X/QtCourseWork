#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

}
//методы для получения хранящихся значений
QVector<Agreement*> DataBase::get_Agreement()
{
    return AgreeList;
}

QVector<Subsidiary*> DataBase::get_Subsidiary()
{
    return SubsiList;
}

QVector<Client*> DataBase::get_Client()
{
    return ClientList;
}
//удаление договора
bool DataBase::remAgree(QString nAgr)
{
    if (AgreeList.size() == 0) return true;
    bool f = true;
    QString s;
    for (auto it = AgreeList.begin(); it != AgreeList.end(); ++it){
        if (nAgr == (*it)->numArg()){
            s = (*it)->numPass();
            f = false;
            AgreeList.erase(it);
            break;
        }
    }
    for (auto it = ClientList.begin(); it != ClientList.end(); ++it){
        if (s == (*it)->pass()){
            (*it)->setCount(((*it)->count())-1);
            break;
        }
    }
    emit notifyObservers();
    return f;
}
//проверка на уникальность номера договора
bool DataBase::checkAgree(QString str){
    for (auto it = AgreeList.begin(); it != AgreeList.end(); ++it){
        if (str == (*it)->numPass() || str == (*it)->Code()){
            return true;
            break;
        }
    }
    return false;
}
//удаление филиала
bool DataBase::remSubsid(QString code)
{
    if (SubsiList.size() == 0) return true;
    bool f = true;
    for (auto it = SubsiList.begin(); it != SubsiList.end(); ++it){
        if (code == (*it)->Code()){
            f= false;
            SubsiList.erase(it);
            break;
        }
    }
    emit notifyObservers();
    return f;
}
//удаление клиента
bool DataBase::remClient(QString nPass)
{
    if(ClientList.size() == 0) return true;
    bool f = true;
    for (auto it = ClientList.begin(); it != ClientList.end(); ++it){
        if (nPass == (*it)->pass()){
            f = false;
            ClientList.erase(it);
            break;
        }
    }
    emit notifyObservers();
    return f;
}
//методы для создания интерфейсов взаимодействия(паттерн медиатор)
AddSubInterface* DataBase::createAddSubI(){
    AddSubInterface* interface = new AddSubInterface(&SubsiList);
    return interface;
}
AddClInterface* DataBase::createAddClI(){
    AddClInterface* interface = new AddClInterface(&ClientList);
    return interface;
}
AddAgrInterface* DataBase::createAddAgrI(){
    AddAgrInterface* interface = new AddAgrInterface(&AgreeList, ClientList, SubsiList);
    return interface;
}
//добавление договора
void DataBase::pushAgree(Agreement *Agree)
{
    QString code, name;
    int cost;
    Facade::getData(Agree, &code, &name, &cost);
    Agree->setIns(code);
    Agree->setIName(name);
    Agree->setCost(cost);
    AgreeList.push_back(Agree);
    emit notifyObservers();
}
//добавление филиала
void DataBase::pushSubsid(Subsidiary *Subsid)
{
    SubsiList.push_back(Subsid);
    emit notifyObservers();
}
//добавление клиента
void DataBase::pushClient(Client *Clien)
{
    ClientList.push_back(Clien);
    emit notifyObservers();
}
//обновление количество договоров у клиента
void DataBase::updater(QString str)
{
    for (auto it = ClientList.begin(); it != ClientList.end(); ++it){
        if (str == (*it)->pass()){
            (*it)->setCount(((*it)->count())+1);
            break;
        }
    }
}
//конструктор
AddSubInterface::AddSubInterface(QVector<Subsidiary*>* list)
{
    sublist = list;
}
AddSubInterface::~AddSubInterface()
{

}
//метод добавления филиала в общую структуру данных
bool AddSubInterface::AddSubsidiary(Subsidiary* sub)
{
    for (auto it = sublist->begin(); it != sublist->end(); ++it){
        if(sub->Code() == (*it)->Code()) return true;
    }
    sublist->append(sub);
    return false;
}
//конструктор
AddClInterface::AddClInterface(QVector<Client*>* list)
{
    sublist = list;
}
AddClInterface::~AddClInterface()
{

}
//метод добавления клиента в общую структуру данных
bool AddClInterface::AddClient(Client* sub)
{
    for (auto it = sublist->begin(); it != sublist->end(); ++it){
        if(sub->pass() == (*it)->pass()) return true;
    }
    sublist->append(sub);
    return false;
}
//конструктор
AddAgrInterface::AddAgrInterface(QVector<Agreement*>* list, QVector<Client*> clist, QVector<Subsidiary*> sList)
{
    sublist = list;
    clList = clist;
    suList = sList;
}
AddAgrInterface::~AddAgrInterface()
{

}
//метод добавления договора в общую структуру данных
int AddAgrInterface::AddAgreement(Agreement* sub)
{
    int flag = 0;
    bool f = false;
    for (auto it = clList.begin(); it != clList.end(); ++it){
        if(sub->numPass() == (*it)->pass()) f = true;
    }
    if (!f) flag -=2;
    f = false;
    for (auto it = suList.begin(); it != suList.end(); ++it){
        if(sub->Code() == (*it)->Code()) f = true;
    }
    if (!f)flag +=1;
    f = false;
    for (auto it = sublist->begin(); it != sublist->end(); ++it){
        if(sub->numArg() == (*it)->numArg()) f = true;
    }
    if (f)flag = 100;
    if (flag) return flag;
    QString code, name;
    int cost;
    Facade::getData(sub, &code, &name, &cost);
    sub->setIns(code);
    sub->setIName(name);
    sub->setCost(cost);
    sublist->append(sub);
    return 0;
}
