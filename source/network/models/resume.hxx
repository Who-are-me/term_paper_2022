#pragma once

#include <QString>


class Resume {
private:
    int		id;
    QString	pip;
    QString soft_skills;
    QString hard_skills;
    QString language;
    QString hobbies;
    QString phone;
    QString email;
    QString skype;
    QString qualification;
    QString about_myself;
    QString owner;

public:
    Resume();

    int getId() const;
    void setId(int newId);

    const QString &getPip() const;
    void setPip(const QString &newPip);

    const QString &getSoft_skills() const;
    void setSoft_skills(const QString &newSoft_skills);

    const QString &getHard_skills() const;
    void setHard_skills(const QString &newHard_skills);

    const QString &getLanguage() const;
    void setLanguage(const QString &newLanguage);

    const QString &getHobbies() const;
    void setHobbies(const QString &newHobbies);

    const QString &getPhone() const;
    void setPhone(const QString &newPhone);

    const QString &getEmail() const;
    void setEmail(const QString &newEmail);

    const QString &getSkype() const;
    void setSkype(const QString &newSkype);

    const QString &getQualification() const;
    void setQualification(const QString &newQualification);

    const QString &getAbout_myself() const;
    void setAbout_myself(const QString &newAbout_myself);

    const QString &getOwner() const;
    void setOwner(const QString &newOwner);
};

