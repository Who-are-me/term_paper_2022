#include <QString>
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
            this->cookies.push_back(ch);
        }

        if(last == 'I' && ch == 'D') {
            check = true;
        }

        last = ch;
    }

    return true;
}


bool CookiesManager::saveToDisk() {

    return true;
}


bool CookiesManager::getFromDisk() {

    return true;
}


bool CookiesManager::validCookie() {

    return true;
}


QString CookiesManager::getCookie() {
    return this->cookies;
}







