#pragma once

#include <QString>


class Vacancy {
private:
    int		id;
    QString title;
    QString description;
    int 	salary;
    int		education;
    int		experience;
    QString city;
    QString location;
    QString phone;
    QString email;
    QString company;
    QString owner;

public:
    Vacancy();

    int getId() const;
    void setId(int newId);

    const QString &getTitle() const;
    void setTitle(const QString &newTitle);

    const QString &getDescription() const;
    void setDescription(const QString &newDescription);

    const int &getSalary() const;
    void setSalary(const int &newSalary);

    int getEducation() const;
    void setEducation(int newEducation);

    int getExperience() const;
    void setExperience(int newExperience);

    const QString &getCity() const;
    void setCity(const QString &newCity);

    const QString &getLocation() const;
    void setLocation(const QString &newLocation);

    const QString &getPhone() const;
    void setPhone(const QString &newPhone);

    const QString &getEmail() const;
    void setEmail(const QString &newEmail);

    const QString &getCompany() const;
    void setCompany(const QString &newCompany);
    const QString &getOwner() const;
    void setOwner(const QString &newOwner);
};

