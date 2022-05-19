#include <QString>
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <stdio.h>
#include <stdlib.h>

#include "cookiesmanager.hxx"
#include "log.hxx"


CookiesManager::CookiesManager() : exists_cookies(false) {
    Log::info("CookiesManager is started");
}


CookiesManager::~CookiesManager() {
    Log::info("CookiesManager is finished");
}


const QString &CookiesManager::getCommand() {
    return command;
}


bool CookiesManager::isExistsCookie() {
    if(!exists_cookies || this->cookies.isEmpty() || !isValidCookie(this->cookies)) {
        if(!loadFromDisk()) {
            if(!restoreCookie()) {
                Log::critical("Cookie isn't created");
                exit(EXIT_FAILURE);
            }
        }
    }

    return true;
}


void CookiesManager::setCommand(const QString &newCommand) {
    command = newCommand;
}


// TODO test me
bool CookiesManager::restoreCookie() {
    Log::info("CookiesManager - restore cookies");

    QString temp_cookies = "";
    FILE *fpipe;
    char ch = 0;
    char last = 0;
    bool check = false;

    if(0 == (fpipe = (FILE*)popen(command.toStdString().c_str(), "r"))) {
        Log::critical("error execute command for cookies");
        exit(EXIT_FAILURE);
    }

    while(fread(&ch, sizeof(ch), 1, fpipe)) {
        if(check && ch != '\t') {
            temp_cookies.push_back(ch);
        }

        if(last == 'I' && ch == 'D') {
            check = true;
        }

        last = ch;
    }

    temp_cookies.chop(1);

    if(isValidCookie(temp_cookies)) {
        this->cookies = temp_cookies;
        this->exists_cookies = true;

        return true;
    }
    else {
        this->exists_cookies = false;

        return false;
    }
}


bool CookiesManager::writeToDisk() {
    QFile file(cookie_path);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        Log::info("not open cookie file");

        return false;
    }
    else {
        QTextStream text_stream(&file);
        text_stream << this->cookies;

        return true;
    }
}


bool CookiesManager::loadFromDisk() {
    QByteArray data;
    QFile file(cookie_path);

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        Log::critical("problem with cookie file");
        return false;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        data.append(in.readLine().toStdString());
    }

    file.close();

    if(isValidCookie(data)) {
        this->cookies = data;
        this->exists_cookies = true;

        return true;
    }
    else {
        return false;
    }
}


bool CookiesManager::isValidCookie(QString validation) {
    Log::info("Cookies for validation: " + validation);

    if(validation.size() != 32) {
        return false;
    }

    for(auto &item : validation) {
        if(!item.isLetterOrNumber()) {
            return false;
        }
    }

    return true;
}


QString CookiesManager::getCookie() {
    // TODO test me
    if(!exists_cookies || cookies.isEmpty() || !isValidCookie(this->cookies)) {
        if(!loadFromDisk()) {
            if(!restoreCookie()) {
                Log::critical("Cookie isn't created");
                exit(EXIT_FAILURE);
            }
        }
    }

    return this->cookies;
}







