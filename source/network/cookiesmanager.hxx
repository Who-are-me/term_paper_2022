#pragma once

#include <QObject>
#include <QString>


class CookiesManager : QObject {
    Q_OBJECT

public:
    CookiesManager();
    ~CookiesManager();

private:
    static QString cookies;
    bool exists_cookies;

    bool restoreCookie();
    bool saveToDisk();
    bool getFromDisk();
    bool validCookie();

protected:
    QString getCookieData();
};

