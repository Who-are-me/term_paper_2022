#include <QDebug>
#include <cassert>

#include "log.hxx"


Log::Log() {

}


void Log::info(QString str) {
#ifndef NDEBUG
    qDebug() << "Log: " << str;
#endif
}


void Log::warning(QString str) {
#ifndef NDEBUG
    qWarning() << "Warning: " << str;
#endif
}


void Log::critical(QString str) {
#ifndef NDEBUG
    qCritical() << "Critical: " << str;
#endif
}


void Log::massert(bool exp, QString msg) {
#ifndef NDEBUG
    critical("massert is not true");
    assert(((void)msg, exp));
#endif
}
