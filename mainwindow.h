#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void nums_creation();
    void on_pushButton_pnt_clicked();
    void operations();
    void bin_operations();
    void on_pushButton_eq_clicked();
    void on_pushButton_c_clicked();
    void on_pushButton_bs_clicked();
};
#endif // MAINWINDOW_H
