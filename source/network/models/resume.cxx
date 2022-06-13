#include "resume.hxx"


Resume::Resume() {

}


int Resume::getId() const {
    return id;
}


void Resume::setId(int newId) {
    id = newId;
}


const QString &Resume::getPip() const {
    return pip;
}


void Resume::setPip(const QString &newPip) {
    pip = newPip;
}


const QString &Resume::getSoft_skills() const {
    return soft_skills;
}


void Resume::setSoft_skills(const QString &newSoft_skills) {
    soft_skills = newSoft_skills;
}


const QString &Resume::getHard_skills() const {
    return hard_skills;
}


void Resume::setHard_skills(const QString &newHard_skills) {
    hard_skills = newHard_skills;
}


const QString &Resume::getLanguage() const {
    return language;
}


void Resume::setLanguage(const QString &newLanguage) {
    language = newLanguage;
}


const QString &Resume::getHobbies() const {
    return hobbies;
}


void Resume::setHobbies(const QString &newHobbies) {
    hobbies = newHobbies;
}


const QString &Resume::getPhone() const {
    return phone;
}


void Resume::setPhone(const QString &newPhone) {
    phone = newPhone;
}


const QString &Resume::getEmail() const {
    return email;
}


void Resume::setEmail(const QString &newEmail) {
    email = newEmail;
}


const QString &Resume::getSkype() const {
    return skype;
}


void Resume::setSkype(const QString &newSkype) {
    skype = newSkype;
}


const QString &Resume::getQualification() const {
    return qualification;
}


void Resume::setQualification(const QString &newQualification) {
    qualification = newQualification;
}


const QString &Resume::getAbout_myself() const {
    return about_myself;
}


void Resume::setAbout_myself(const QString &newAbout_myself) {
    about_myself = newAbout_myself;
}


const QString &Resume::getOwner() const {
    return owner;
}


void Resume::setOwner(const QString &newOwner) {
    owner = newOwner;
}
