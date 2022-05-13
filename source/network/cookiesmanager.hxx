#pragma once

#include <QObject>
#include <QString>


class CookiesManager : QObject {
    Q_OBJECT

public:
    CookiesManager();
    ~CookiesManager();

    static const QString &getHost();
    static void setHost(const QString &newHost);

    static const QString &getCommand();
    static void setCommand(const QString &newCommand);

private:
    inline static QString cookies;
    inline static QString command;
    inline static QString host;
    const QString cookie_path = ".cache/cookie";
    bool exists_cookies;

    bool restoreCookie();
    bool loadFromDisk();
    bool writeToDisk();
    bool isValidCookie(QString validation);

protected:
    QString getCookie();
};

