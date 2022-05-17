#include "account.hxx"


Account::Account() {

}


const QString &Account::getUsername() const
{
    return username;
}


void Account::setUsername(const QString &newUsername) {
    username = newUsername;
}


const QString &Account::getPassword() const {
    return password;
}


void Account::setPassword(const QString &newPassword) {
    password = newPassword;
}


bool Account::getEnabled() const {
    return enabled;
}


void Account::setEnabled(bool newEnabled) {
    enabled = newEnabled;
}



