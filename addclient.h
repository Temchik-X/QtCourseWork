#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include "database.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AddClient;
}
//класс формы добавления клиента
class AddClient : public QDialog
{
    Q_OBJECT

public:
    explicit AddClient(QWidget *parent = nullptr);
    ~AddClient();
    AddClInterface* interface;
signals:
    void notifyObservers();
private slots:
    void on_pushButton_clicked();

private:
    Ui::AddClient *ui;
};

#endif // ADDCLIENT_H
