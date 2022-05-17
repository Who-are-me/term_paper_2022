#include "education.hxx"


Education::Education() {

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
