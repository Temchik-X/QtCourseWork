#ifndef DATABASE_H
#define DATABASE_H

#include "subsidiary.h"
#include "client.h"
#include "facade.h"

//классы посредников(паттерн медиатор)
class AddSubInterface;
class AddClInterface;
class AddAgrInterface;

//класс взаимодействия с сущностями
class DataBase:public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    QVector<Agreement*> get_Agreement();
    QVector<Subsidiary*> get_Subsidiary();
    QVector<Client*> get_Client();

    AddSubInterface* createAddSubI();
    AddClInterface* createAddClI();
    AddAgrInterface* createAddAgrI();
    bool checkAgree(QString str);
    bool remAgree(QString nAgr);
    bool remSubsid(QString code);
    bool remClient(QString nPass);

    void pushAgree(Agreement* Agree);
    void pushSubsid(Subsidiary* Subsid);
    void pushClient(Client* Clien);
signals:
    void notifyObservers();
private slots:
    void updater(QString str);
private:
    QVector<Agreement*> AgreeList;
    QVector<Subsidiary*> SubsiList;
    QVector<Client*> ClientList;
};

class AddSubInterface
{
public:
    AddSubInterface(QVector<Subsidiary*>* list);
    ~AddSubInterface();
    bool AddSubsidiary(Subsidiary* sub);

private:

    QVector<Subsidiary*>* sublist;
};

class AddClInterface
{
public:
    AddClInterface(QVector<Client*>* list);
    ~AddClInterface();
    bool AddClient(Client* sub);

private:

    QVector<Client*>* sublist;
};

class AddAgrInterface
{
public:
    AddAgrInterface(QVector<Agreement*>* list, QVector<Client*> clList, QVector<Subsidiary*> subList);
    ~AddAgrInterface();
    int AddAgreement(Agreement* sub);

private:

    QVector<Agreement*>* sublist;
    QVector<Client*> clList;
    QVector<Subsidiary*> suList;
};

#endif // DATABASE_H
