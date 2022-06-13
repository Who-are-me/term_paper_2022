#include "account.hxx"


Account::Account() {

}


Account::Account(QString pip, QString city, QString location, QString phone, QString email, QString company, QString description, QString role, QString username, QString password, bool enabled) {
    this->pip = pip;
    this->city = city;
    this->location = location;
    this->phone = phone;
    this->email = email;
    this->company = company;
    this->description = description;
    this->role = role;
    this->username = username;
    this->password = password;
    this->enabled = enabled;
}


QString Account::toString() {
    return "{pip: " + pip +
            ", city: " + city +
            ", location: " + location +
            ", phone: " + phone +
            ", email: " + email +
            ", company: " + company +
            ", description: " + description +
            ", role: " + role +
            ", login_name: " + username +
            ", login_password: " + password +
            ", enablad: " + (enabled ? "true" : "false") + "}";
}


const QString &Account::getPip() const {
    return pip;
}


void Account::setPip(const QString &newPip) {
    pip = newPip;
}


const QString &Account::getCity() const {
    return city;
}


void Account::setCity(const QString &newCity) {
    city = newCity;
}


const QString &Account::getLocation() const {
    return location;
}


void Account::setLocation(const QString &newLocation) {
    location = newLocation;
}


const QString &Account::getPhone() const {
    return phone;
}


void Account::setPhone(const QString &newPhone) {
    phone = newPhone;
}


const QString &Account::getEmail() const {
    return email;
}


void Account::setEmail(const QString &newEmail) {
    email = newEmail;
}


const QString &Account::getCompany() const {
    return company;
}


void Account::setCompany(const QString &newCompany) {
    company = newCompany;
}


const QString &Account::getDescription() const {
    return description;
}


void Account::setDescription(const QString &newDescription) {
    description = newDescription;
}


const QString &Account::getRole() const {
    return role;
}


void Account::setRole(const QString &newRole) {
    role = newRole;
}


const QString &Account::getUsername() const {
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



