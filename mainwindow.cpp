#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtMath>


double prev_num;
int plus = 0;
int minus = 0;
int dil = 0;
int mult = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_n0, SIGNAL(clicked()), this, SLOT(nums_creation()));
    connect(ui->pushButton_n1, SIGNAL(clicked()), this, SLOT(nums_creation()));
    connect(ui->pushButton_n2, SIGNAL(clicked()), this, SLOT(nums_creation()));
    connect(ui->pushButton_n3, SIGNAL(clicked()), this, SLOT(nums_creation()));
    connect(ui->pushButton_n4, SIGNAL(clicked()), this, SLOT(nums_creation()));
    connect(ui->pushButton_n5, SIGNAL(clicked()), this, SLOT(nums_creation()));
    connect(ui->pushButton_n6, SIGNAL(clicked()), this, SLOT(nums_creation()));
    connect(ui->pushButton_n7, SIGNAL(clicked()), this, SLOT(nums_creation()));
    connect(ui->pushButton_n8, SIGNAL(clicked()), this, SLOT(nums_creation()));
    connect(ui->pushButton_n9, SIGNAL(clicked()), this, SLOT(nums_creation()));
    connect(ui->pushButton_pm, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_p, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_r, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_square, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_reverse, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(bin_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(bin_operations()));
    connect(ui->pushButton_m, SIGNAL(clicked()), this, SLOT(bin_operations()));
    connect(ui->pushButton_d, SIGNAL(clicked()), this, SLOT(bin_operations()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(operations()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nums_creation()
{


    QPushButton *ptr = (QPushButton *)sender();
    if(!((ui->label->text().contains('.'))&&(ptr->text()=="0")))
    {
    double num;
    QString a;

    //a = ui->label->text() + ptr->text();
    num = (ui->label->text() + ptr->text()).toDouble();
    a = QString::number(num, 'g', 10);
    ui->label->setText(a);
    }
    if(ui->label->text().contains('.'))
    {
        if((ptr->text())=='0'){
        ui->label->setText(ui->label->text() + ptr->text());
    }
}
}

void MainWindow::on_pushButton_pnt_clicked()
{
    if(!(ui->label->text().contains('.')))
    {
        ui->label->setText(ui->label->text() + '.');
    }
}

void MainWindow::operations()
{
    MainWindow::on_pushButton_eq_clicked();
    QPushButton *ptr = (QPushButton *)sender();
    double num;
    QString a;

    if(ptr->text()=="+/-")
    {
        num = (ui->label->text()).toDouble();
        num = num*(-1);
        a = QString::number(num, 'g', 10);
        ui->label->setText(a);
    }
    else if(ptr->text()=="%")
    {
        num = (ui->label->text()).toDouble();
        num = num*0.01;
        a = QString::number(num, 'g', 10);
        ui->label->setText(a);
    }
    else if(ptr->text()=="√")
    {

        num = (ui->label->text()).toDouble();
        if(num<0){
        QMessageBox:: about(this, "Помилка", "You cannot do it");
        ui->label->setText("0");
        }
        else{
        num = sqrt(num);
        a = QString::number(num, 'g', 10);
        ui->label->setText(a);
        }
    }
    else if(ptr->text()=="^2")
    {
        num = (ui->label->text()).toDouble();
        num = num*num;
        a = QString::number(num, 'g', 10);
        ui->label->setText(a);
    }
    else if(ptr->text()=="1/x")
    {
        if(ui->label->text()!="0"){
        num = (ui->label->text()).toDouble();
        num = 1/num;;
        a = QString::number(num, 'g', 10);
        ui->label->setText(a);}
        else{
            QMessageBox:: about(this, "Помилка", "You cannot do it");
            ui->label->setText("0");
        }
    }
    else if(ptr->text() == "sin")
    {
        num = (ui->label->text()).toDouble();


        num = qSin(num);
        a = QString::number(num, 'g', 10);
        ui->label->setText(a);
        /*
        else
        {
            QMessageBox:: about(this, "Помилка", "You cannot do it");
            ui->label->setText("0");

         }*/
    }

}
void MainWindow::bin_operations()
{
    MainWindow::on_pushButton_eq_clicked();


    QPushButton *ptr = (QPushButton *)sender();
    prev_num = ui->label->text().toDouble();
    ptr->setChecked(true);
    ui->label->setText("0");
    if(ptr->text() == "+")
    {
        plus = 1;
    }
    else if(ptr->text() == "-")
    {
        minus = 1;
    }
    else if(ptr->text() == "÷")
    {
        dil = 1;
    }
    else if(ptr->text() == "x")
    {
        mult = 1;
    }

}


void MainWindow::on_pushButton_eq_clicked()
{
    double num2, res;
    QString a;
    num2 = ui->label->text().toDouble();

    if(minus)
    {
        res = prev_num - num2;
        a = QString::number(res, 'g', 10);
        ui->label->setText(a);
        minus = 0;
        prev_num = res;
    }

    else if(plus)
    {
        res = prev_num + num2;
        a = QString::number(res, 'g', 10);
        ui->label->setText(a);
        plus = 0;
        prev_num = res;
    }

    else if(mult)
    {
        res = prev_num*num2;
        a = QString::number(res, 'g', 10);
        ui->label->setText(a);
        mult = 0;
        prev_num = res;
    }

    else if(dil)
    {
        if(ui->label->text()=="0")
        {

            QMessageBox:: about(this, "Помилка", "You cannot do it");
            ui->label->setText("0");
            dil = 0;
        }
        else{
        res = prev_num / num2;
        a = QString::number(res, 'g', 10);
        ui->label->setText(a);
        dil = 0;
        prev_num = res;}
    }
}

void MainWindow::on_pushButton_c_clicked()
{
    ui->label->setText("0");
}


void MainWindow::on_pushButton_bs_clicked()
{
    QString a;
    a = ui->label->text();
    if(a.contains('e'))
    {
        MainWindow::on_pushButton_c_clicked();
    }
    else{
    if(a.length()>1)
    {
        a.remove(a.length()-1, 1);
        ui->label->setText(a);
    }
    else{
        ui->label->setText("0");
    }

}}

