#include "addfilial.h"
#include "ui_addfilial.h"

addFilial::addFilial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addFilial)
{
    ui->setupUi(this);


}

addFilial::~addFilial()
{
    delete ui;
    if (interface != nullptr){
        delete interface;
    }
}
//слот нажатия кнопки для добавления филиала.
void addFilial::on_pushButton_clicked()
{
    //проверка на пустые поля
    if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == "" || ui->lineEdit_4->text() == ""){
        QMessageBox::warning(this, "Неуспех", "Некоторые поля формы остались пусты!");
        return;
    }
    if (interface == nullptr)
        return;
    Subsidiary* subsid = new Subsidiary(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(),ui->lineEdit_4->text());

    bool f = interface->AddSubsidiary(subsid);
    if (f){
        QMessageBox::warning(this, "Неуспех", "Филиал с таким кодом уже зарегистрирован!");
    }
    else{
        emit notifyObservers();
        ui->lineEdit->setText(""); ui->lineEdit_2->setText(""); ui->lineEdit_3->setText(""); ui->lineEdit_4->setText("");
        hide();
    }


}


