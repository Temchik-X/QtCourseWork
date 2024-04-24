#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    Base(this)
{
    //инициализация объектов форм
    ui->setupUi(this);
    f1 = new AddClient(this);
    f2 = new addFilial(this);
    f3 = new AddAgree(this);

    //конекты для сигналов
    connect(&Base, SIGNAL(notifyObservers()), this, SLOT(update()));
    connect(this, SIGNAL(notifyObservers()), this, SLOT(update()));
    connect(f1, SIGNAL(notifyObservers()), this, SLOT(update()));
    connect(f2, SIGNAL(notifyObservers()), this, SLOT(update()));
    connect(f3, SIGNAL(notifyObservers()), this, SLOT(update()));
    connect(f3, SIGNAL(notifyObserversAdd(QString)), &Base, SLOT(updater(QString)));
    connect(ui->pushBAddFilial, SIGNAL(clicked()), this, SLOT(onButtonSendSubsidiary()));
    connect(ui->pushBAddClient, SIGNAL(clicked()), this, SLOT(onButtonSendClient()));
    connect(ui->pushBAddAgr, SIGNAL(clicked()), this, SLOT(onButtonSendAgreement()));
    emit notifyObservers();

}

MainWindow::~MainWindow()
{
    delete ui;
}
//метод для обновления данных в таблице
void MainWindow::update(){
    ui->tableFilials->setRowCount(0);
    ui->tableFilials->setShowGrid(true);
    ui->tableFilials->horizontalHeader()->setStretchLastSection(true);
    ui->tableFilials->setEditTriggers(QTableWidget::NoEditTriggers);
    for(int i = 0; i < Base.get_Subsidiary().size(); i++){
        ui->tableFilials->insertRow(i);
        ui->tableFilials->setItem(i,0, new QTableWidgetItem( Base.get_Subsidiary().at(i)->Code()));
        ui->tableFilials->setItem(i,1, new QTableWidgetItem(Base.get_Subsidiary().at(i)->Name()));
        ui->tableFilials->setItem(i,2, new QTableWidgetItem(Base.get_Subsidiary().at(i)->Adress()));
        ui->tableFilials->setItem(i,3, new QTableWidgetItem(Base.get_Subsidiary().at(i)->Phone()));
    }

    ui->tableClient->setRowCount(0);
    ui->tableClient->setShowGrid(true);
    ui->tableClient->horizontalHeader()->setStretchLastSection(true);
    ui->tableClient->setEditTriggers(QTableWidget::NoEditTriggers);
    for(int i = 0; i < Base.get_Client().size(); i++){
        ui->tableClient->insertRow(i);
        ui->tableClient->setItem(i,0, new QTableWidgetItem( Base.get_Client().at(i)->name()));
        ui->tableClient->setItem(i,1, new QTableWidgetItem(Base.get_Client().at(i)->pass()));
        ui->tableClient->setItem(i,2, new QTableWidgetItem(Base.get_Client().at(i)->phone()));
        ui->tableClient->setItem(i,3, new QTableWidgetItem(QString::number(Base.get_Client().at(i)->count())));
    }
    ui->tableAgr->setRowCount(0);
    ui->tableAgr->setShowGrid(true);
    ui->tableAgr->horizontalHeader()->setStretchLastSection(true);
    ui->tableAgr->setEditTriggers(QTableWidget::NoEditTriggers);
    for(int i = 0; i < Base.get_Agreement().size(); i++){
        ui->tableAgr->insertRow(i);
        ui->tableAgr->setItem(i,0, new QTableWidgetItem(Base.get_Agreement().at(i)->numArg()));
        ui->tableAgr->setItem(i,1, new QTableWidgetItem(Base.get_Agreement().at(i)->numPass()));
        ui->tableAgr->setItem(i,2, new QTableWidgetItem(Base.get_Agreement().at(i)->Code()));
        ui->tableAgr->setItem(i,3, new QTableWidgetItem(Base.get_Agreement().at(i)->Date()));
        ui->tableAgr->setItem(i,4, new QTableWidgetItem(Base.get_Agreement().at(i)->Ins()));
        ui->tableAgr->setItem(i,5, new QTableWidgetItem(Base.get_Agreement().at(i)->IName()));
        ui->tableAgr->setItem(i,6, new QTableWidgetItem(QString::number(Base.get_Agreement().at(i)->Time())));
        ui->tableAgr->setItem(i,7, new QTableWidgetItem(QString::number(Base.get_Agreement().at(i)->Cost())));
    }
}
//методы для вызовов доп. форм и интерфейсов взаимодействия
void MainWindow::onButtonSendSubsidiary()
{

    f2->interface = Base.createAddSubI();
    f2->show();

}

void MainWindow::onButtonSendClient()
{

    f1->interface = Base.createAddClI();
    f1->show();

}

void MainWindow::onButtonSendAgreement()
{

    f3->interface = Base.createAddAgrI();
    f3->show();

}

//методы для удаления данных
void MainWindow::on_pushBDelClients_clicked()
{
    bool f = false;
    if (!Base.checkAgree(ui->lineEdit->text())){
        f = Base.remClient(ui->lineEdit->text());
    }
    else{
        QMessageBox::warning(this, "Неуспех", "На этого клиента оформлен договор, удаление невозможно!");
    }
    if (f){
        QMessageBox::warning(this, "Неуспех", "Нет клиента с таким номером паспорта!");
    }
    ui->lineEdit->setText("");
}


void MainWindow::on_pushBDelFilial_clicked()
{
    bool f = false;
    if (!Base.checkAgree(ui->lineEdit_2->text())){
    f = Base.remSubsid(ui->lineEdit_2->text());
    }
    else{
        QMessageBox::warning(this, "Неуспех", "В этом филиале оформлен договор, удаление невозможно!");
    }
    if (f){
        QMessageBox::warning(this, "Неуспех", "Нет филиала с таким кодом!");
    }
    ui->lineEdit_2->setText("");
}


void MainWindow::on_pushBDelAgr_clicked()
{
    bool f = false;
    f = Base.remAgree(ui->lineEdit_3->text());
    if (f){
        QMessageBox::warning(this, "Неуспех", "Нет договора с таким номером!");
    }
    ui->lineEdit_3->setText("");
}

