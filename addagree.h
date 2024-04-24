#ifndef ADDAGREE_H
#define ADDAGREE_H

#include "database.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AddAgree;
}
//класс формы добавления договора
class AddAgree : public QDialog
{
    Q_OBJECT

public:
    explicit AddAgree(QWidget *parent = nullptr);
    ~AddAgree();
    AddAgrInterface* interface;
signals:
    void notifyObservers();
    void notifyObserversAdd(QString str);
private slots:
    void on_pushButton_clicked();

private:
    Ui::AddAgree *ui;
};

#endif // ADDAGREE_H
