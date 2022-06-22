#pragma once

#include <QString>


#define PATH_TO_COOKIE ".cache/cookie"


class CookiesManager {
public:
    CookiesManager();
    ~CookiesManager();

protected:
    static const QString &getCommand();
    bool isExistsCookie();
    bool tryConnect();
    static void setCommand(const QString &newCommand);
    QString getCookie();
    void clearCookie();

private:
    inline static QString 	cookies;
    inline static QString 	command;
    const QString 			cookie_path = PATH_TO_COOKIE;
    bool 					exists_cookies;

    bool restoreCookie();
    bool loadFromDisk();
    bool writeToDisk();
    bool isValidCookie(QString validation);
    bool updateCookie(QString new_cookie);
};

