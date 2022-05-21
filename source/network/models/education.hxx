#pragma once

#include <QString>


class Education {
private:
    int 	id;
    QString	title;
    QString description;
    QString for_time_start;
    QString for_time_end;
    QString req_experience;
    QString option_condition;
    QString city;
    QString location;
    QString phone;
    QString email;
    QString company;
    int 	req_education;

public:
    Education();

    int getId() const;
    void setId(int newId);

    const QString &getTitle() const;
    void setTitle(const QString &newTitle);

    const QString &getDescription() const;
    void setDescription(const QString &newDescription);

    const QString &getFor_time_start() const;
    void setFor_time_start(const QString &newFor_time_start);

    const QString &getFor_time_end() const;
    void setFor_time_end(const QString &newFor_time_end);

    const QString &getReq_experience() const;
    void setReq_experience(const QString &newReq_experience);

    const QString &getOption_condition() const;
    void setOption_condition(const QString &newOption_condition);

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

    int getReq_education() const;
    void setReq_education(int newReq_education);
};

