#ifndef ADDFILIAL_H
#define ADDFILIAL_H

#include <QDialog>
#include <QMessageBox>
#include "database.h"


namespace Ui {
class addFilial;
}
//класс формы добавления филиала
class addFilial : public QDialog
{
    Q_OBJECT

public:
    explicit addFilial(QWidget *parent = nullptr);
    ~addFilial();

    AddSubInterface* interface;
signals:
    void notifyObservers();
private slots:
    void on_pushButton_clicked();

private:
    Ui::addFilial *ui;
};

#endif // ADDFILIAL_H
