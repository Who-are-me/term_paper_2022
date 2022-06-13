#include "vacancy.hxx"


Vacancy::Vacancy() {

}


int Vacancy::getId() const {
    return id;
}


void Vacancy::setId(int newId) {
    id = newId;
}


const QString &Vacancy::getTitle() const {
    return title;
}


void Vacancy::setTitle(const QString &newTitle) {
    title = newTitle;
}


const QString &Vacancy::getDescription() const {
    return description;
}


void Vacancy::setDescription(const QString &newDescription) {
    description = newDescription;
}


const QString &Vacancy::getSalary() const {
    return salary;
}


void Vacancy::setSalary(const QString &newSalary) {
    salary = newSalary;
}


int Vacancy::getEducation() const {
    return education;
}


void Vacancy::setEducation(int newEducation) {
    education = newEducation;
}


int Vacancy::getExperience() const {
    return experience;
}


void Vacancy::setExperience(int newExperience) {
    experience = newExperience;
}


const QString &Vacancy::getCity() const {
    return city;
}


void Vacancy::setCity(const QString &newCity) {
    city = newCity;
}


const QString &Vacancy::getLocation() const {
    return location;
}


void Vacancy::setLocation(const QString &newLocation) {
    location = newLocation;
}


const QString &Vacancy::getPhone() const {
    return phone;
}


void Vacancy::setPhone(const QString &newPhone) {
    phone = newPhone;
}


const QString &Vacancy::getEmail() const {
    return email;
}


void Vacancy::setEmail(const QString &newEmail) {
    email = newEmail;
}


const QString &Vacancy::getCompany() const {
    return company;
}


void Vacancy::setCompany(const QString &newCompany) {
    company = newCompany;
}


const QString &Vacancy::getOwner() const
{
    return owner;
}

void Vacancy::setOwner(const QString &newOwner)
{
    owner = newOwner;
}
