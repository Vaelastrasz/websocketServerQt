#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->setWindowTitle("Websocket Server for VisualCraft");

    m_log = Logger::getInstance();
    m_log->setLogBrowser(ui->text_messageBrowser);
    m_log->setLogFile(QDir::currentPath() + "\\..\\websocketServerQt\\logs\\log.txt");
    m_log->addToLog("New log session started!", llDebug);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_setLogFile_clicked() {

    QString logFilePath = QFileDialog::getOpenFileName(this, QStringLiteral("Select log file"), QDir::currentPath());
    if (!m_log->setLogFile(logFilePath))
        m_log->setLogFile(QDir::currentPath() + "\\..\\websocketServerQt\\logs\\log.txt");
}

void MainWindow::on_btn_startServ_clicked() {
    ui->btn_stopServ->setEnabled(true);
    ui->btn_startServ->setEnabled(false);
}

void MainWindow::on_btn_stopServ_clicked() {
    ui->btn_startServ->setEnabled(true);
    ui->btn_stopServ->setEnabled(false);
}
