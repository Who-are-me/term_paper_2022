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


const QString &CookiesManager::getHost() {
    return host;
}


void CookiesManager::setHost(const QString &newHost) {
    host = newHost;
}


const QString &CookiesManager::getCommand() {
    return command;
}


void CookiesManager::setCommand(const QString &newCommand) {
    command = newCommand;
}


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

    if(isValidCookie(temp_cookies)) {
        this->cookies = temp_cookies;
    }

    return true;
}


bool CookiesManager::writeToDisk() {
    QFile file(cookie_path);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        Log::info("no open cookie file");
        return false;
    }

    QTextStream text_stream(&file);
    text_stream << cookies;

    return true;
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
        cookies = data;
    }
    else {
        return false;
    }

    return true;
}


bool CookiesManager::isValidCookie(QString validation) {
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
    if(cookies.isEmpty()) {
        if(loadFromDisk()) {
            restoreCookie();
        }
    }

    return this->cookies;
}







