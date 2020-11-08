#include "logger.h"
#include "generalfunctions.h"

Logger* Logger::m_instance = nullptr;

bool Logger::setLogFile(QString filePath) {
    if (m_logFile.isOpen())
        m_logFile.close();

    m_logFile.setFileName(filePath);
    if (!m_logFile.open(QFile::Append)) {
        qDebug() << "Cannot open file " + filePath + "! Check file and try again";
        return false;
    }
    return true;
}

//sets log widget sets QTextBrowser widget for log appending
bool Logger::setLogBrowser(QWidget* widget) {
    if (typeid(*widget) != typeid(QTextBrowser)) {
        qDebug() << "Invalid widget set! Try to set QTextBrowser";
        return false;
    }
    m_textWidget = (QTextBrowser*)widget;
    return true;
}
void Logger::addToLog(QString message, LogLevel logLvl) {
    addToFileLog(message, logLvl);

    switch (logLvl) {
    case llInformation:
        m_textWidget->append(message);
        break;
    case llDebug:
        qDebug() << "DEBUG:" + message;
        break;
    case llError:
        m_textWidget->append("<b><p style=\"color:red\">" + message + "</p></b>");
        break;
    case llSuccess:
        m_textWidget->append("<b><p style=\"color:green\">" + message + "</p></b>");
        break;
    default:
        break;
    }
}
void Logger::addToFileLog(QString message, LogLevel logLvl) {
    if (!m_logFile.isOpen()) {
        qDebug() << "File is not open; Please click \"Set log file\" and select proper log file";
        return;
    }
    QTextStream stream(&m_logFile);
    stream << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss") <<"[" << GeneralFunctions::logLevelToString(logLvl) << "]:" << message << "\n";
}

Logger::~Logger() {
    if (m_instance) delete m_instance;
    if (m_logFile.isOpen()) m_logFile.close();
}

Logger *Logger::getInstance() {
    if (m_instance == nullptr){
        m_instance = new Logger();
    }
    return m_instance;
}
