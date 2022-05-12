#pragma once

#include <QString>


class Log {
public:
    Log();

    static void info(QString str);
    static void warning(QString str);
    static void critical(QString str);
    static void massert(bool exp, QString msg);
};

