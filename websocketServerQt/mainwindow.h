#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebChannel>
#include <QFileDialog>
#include "logger.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_setLogFile_clicked();

    void on_btn_startServ_clicked();

    void on_btn_stopServ_clicked();

private:
    Ui::MainWindow *ui;
    Logger* m_log;
};

#endif // MAINWINDOW_H
