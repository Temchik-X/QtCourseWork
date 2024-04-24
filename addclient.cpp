#include "addclient.h"
#include "ui_addclient.h"

AddClient::AddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);
}

AddClient::~AddClient()
{
    delete ui;
}
//слот нажатия кнопки для добавления клиента.
void AddClient::on_pushButton_clicked()
{
    //проверка на пустые поля
    if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == ""){
        QMessageBox::warning(this, "Неуспех", "Некоторые поля формы остались пусты!");
        return;
    }
    if (interface == nullptr)
        return;
    Client* subsid = new Client(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), 0);

    bool f = interface->AddClient(subsid);
    if  (f){
        QMessageBox::warning(this, "Неуспех", "Клиент с таким паспортом уже зарегистрирован!");
    }
    else{
        emit notifyObservers();
        ui->lineEdit->setText(""); ui->lineEdit_2->setText(""); ui->lineEdit_3->setText("");
        close();
    }


}

