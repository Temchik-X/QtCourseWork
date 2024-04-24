#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addagree.h"
#include "addclient.h"
#include "addfilial.h"
#include "database.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onButtonSendSubsidiary();
    void onButtonSendAgreement();
    void onButtonSendClient();

    void on_pushBDelClients_clicked();

    void on_pushBDelFilial_clicked();

    void on_pushBDelAgr_clicked();
    void update();
signals:
    void notifyObservers();
private:
    Ui::MainWindow *ui;
    AddClient *f1;
    addFilial *f2;
    AddAgree *f3;
    DataBase Base;
};
#endif // MAINWINDOW_H
