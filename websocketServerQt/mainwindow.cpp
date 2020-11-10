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

    m_msgServer = new MessageServer(new QWebSocketServer(QStringLiteral("WebSocket message server"), QWebSocketServer::NonSecureMode));
    connect(m_msgServer, &MessageServer::usersChanged,
            this, &MainWindow::usersListUpdate);
}

MainWindow::~MainWindow() {
    delete m_msgServer;
    delete ui;
}

void MainWindow::on_btn_setLogFile_clicked() {

    QString logFilePath = QFileDialog::getOpenFileName(this, QStringLiteral("Select log file"), QDir::currentPath());
    m_log->setLogFile(logFilePath);
}

void MainWindow::on_btn_startServ_clicked() {

    if (!m_msgServer->connectServer()) return;

    ui->btn_stopServ->setEnabled(true);
    ui->btn_startServ->setEnabled(false);
    ui->lbl_serverStatus->setText("Server_active");
}

void MainWindow::on_btn_stopServ_clicked() {

    m_msgServer->stopServer();
    ui->text_connBrowser->clear();

    ui->lbl_serverStatus->setText("Server_stopped");
    ui->btn_startServ->setEnabled(true);
    ui->btn_stopServ->setEnabled(false);
}

void MainWindow::usersListUpdate() {

    ui->text_connBrowser->clear();
    for (QString userIP : m_msgServer->getClientList())
        ui->text_connBrowser->append(userIP);
}
