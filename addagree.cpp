#include "addagree.h"
#include "ui_addagree.h"

AddAgree::AddAgree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAgree)
{
    ui->setupUi(this);
    ui->lineEdit_6->setValidator(new QIntValidator(this));
}

AddAgree::~AddAgree()
{
    delete ui;
}
//слот нажатия кнопки для добавления договора.
void AddAgree::on_pushButton_clicked()
{
    //проверка на пустые поля
    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == "" || ui->lineEdit_5->text() == "" || ui->lineEdit_6->text() == ""){
        QMessageBox::warning(this, "Неуспех", "Некоторые поля формы остались пусты!");
        return;
    }
    if (interface == nullptr)
        return;
    Agreement* subsid = new Agreement(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), static_cast<Agreement::InsuranceType>(ui->comboBox->currentIndex()),ui->lineEdit_5->text(), ui->lineEdit_6->text().toInt());
    //проверка на корректность ввода данных
    int flag = interface->AddAgreement(subsid);
    if(flag == 100){
        QMessageBox::warning(this, "Неуспех", "Такой номер договора уже зарегистрирован!");
    }
    else if (flag > 0){
        QMessageBox::warning(this, "Неуспех", "Нет филиала с таким кодом!");
        //filial
    }
    else if(flag == -1){
        QMessageBox::warning(this, "Неуспех", "Нет клиента с таким номером паспорта и нет филиала с таким кодом!");
    }
    else if(flag < 0){
        QMessageBox::warning(this, "Неуспех", "Нет клиента с таким номером паспорта!");
    }
    else{
        QString s = "Договор успешно заключен, сумма договора составила: " + QString::number(subsid->Cost()) + "руб/месяц";
        QMessageBox::information(this, "Успех", s);
        emit notifyObserversAdd(subsid->numPass());
        emit notifyObservers();
        ui->lineEdit->setText(""); ui->lineEdit_2->setText(""); ui->lineEdit_3->setText(""); ui->lineEdit_5->setText(""); ui->lineEdit_6->setText(""); ui->comboBox->setCurrentIndex(0);
        close();
    }

}

