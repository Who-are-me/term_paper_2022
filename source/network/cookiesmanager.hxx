#pragma once

#include <QObject>
#include <QString>


class CookiesManager : QObject {
    Q_OBJECT
private:
    inline static QString host;
    inline static QString command;

public:
    CookiesManager();
    ~CookiesManager();

    static const QString &getHost();
    static void setHost(const QString &newHost);

    static const QString &getCommand();
    static void setCommand(const QString &newCommand);

private:
    static QString cookies;
    bool exists_cookies;

    bool restoreCookie();
    bool saveToDisk();
    bool getFromDisk();
    bool validCookie();

protected:
    QString getCookie();
};

