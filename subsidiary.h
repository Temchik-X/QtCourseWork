#ifndef SUBSIDIARY_H
#define SUBSIDIARY_H

#include <QObject>
//класс филиала
class Subsidiary : public QObject
{
public:
    Subsidiary(QString Code, QString Name, QString Adress, QString Phone);
    explicit Subsidiary(QObject *parent = nullptr);
    Subsidiary clone();
    QString Code();
    QString Name();
    QString Adress();
    QString Phone();
private:
    QString fCode;
    QString fName;
    QString fAdress;
    QString fPhone;
};

#endif // SUBSIDIARY_H
