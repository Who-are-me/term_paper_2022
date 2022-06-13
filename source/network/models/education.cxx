#include "education.hxx"


Education::Education() {

}


Education::Education(QString title, QString description, QString for_time_start, QString for_time_end, QString req_experience, QString option_condition, QString city, QString location, QString phone, QString email, QString company, int req_education, QString owner) {
    this->title = title;
    this->description = description;
    this->for_time_start = for_time_start;
    this->for_time_end = for_time_end;
    this->req_experience = req_experience;
    this->option_condition = option_condition;
    this->city = city;
    this->location = location;
    this->phone = phone;
    this->email = email;
    this->company = company;
    this->req_education = req_education;
    this->owner = owner;
}


QString Education::toString() {
    return "{id: " + QString::number(id) +
            ", title: " + title +
            ", description: " + description +
            ", for_time_start: " + for_time_start +
            ", for_time_end: " + for_time_end +
            ", req_experience: " + req_experience +
            ", option_condition: " + option_condition +
            ", city: " + city +
            ", location: " + location +
            ", phone: " + phone +
            ", email: " + email +
            ", company: " + company +
            ", req_education: " + QString::number(req_education) +
            ", owner: " + owner + "}";
}


int Education::getId() const {
    return id;
}


void Education::setId(int newId) {
    id = newId;
}


const QString &Education::getTitle() const {
    return title;
}


void Education::setTitle(const QString &newTitle) {
    title = newTitle;
}


const QString &Education::getDescription() const {
    return description;
}


void Education::setDescription(const QString &newDescription) {
    description = newDescription;
}


const QString &Education::getFor_time_start() const {
    return for_time_start;
}


void Education::setFor_time_start(const QString &newFor_time_start) {
    for_time_start = newFor_time_start;
}


const QString &Education::getFor_time_end() const {
    return for_time_end;
}


void Education::setFor_time_end(const QString &newFor_time_end) {
    for_time_end = newFor_time_end;
}


const QString &Education::getReq_experience() const {
    return req_experience;
}


void Education::setReq_experience(const QString &newReq_experience) {
    req_experience = newReq_experience;
}


const QString &Education::getOption_condition() const {
    return option_condition;
}


void Education::setOption_condition(const QString &newOption_condition) {
    option_condition = newOption_condition;
}


const QString &Education::getCity() const {
    return city;
}


void Education::setCity(const QString &newCity) {
    city = newCity;
}


const QString &Education::getLocation() const {
    return location;
}


void Education::setLocation(const QString &newLocation) {
    location = newLocation;
}


const QString &Education::getPhone() const {
    return phone;
}


void Education::setPhone(const QString &newPhone) {
    phone = newPhone;
}


const QString &Education::getEmail() const {
    return email;
}


void Education::setEmail(const QString &newEmail) {
    email = newEmail;
}


const QString &Education::getCompany() const {
    return company;
}


void Education::setCompany(const QString &newCompany) {
    company = newCompany;
}


int Education::getReq_education() const {
    return req_education;
}


void Education::setReq_education(int newReq_education) {
    req_education = newReq_education;
}


const QString &Education::getOwner() const {
    return owner;
}


void Education::setOwner(const QString &newOwner) {
    owner = newOwner;
}
