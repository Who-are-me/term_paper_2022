#pragma once

#include <QString>


class Account {
private:
    QString pip;
    QString city;
    QString location;
    QString phone;
    QString email;
    QString company;
    QString description;
    QString role;
    QString username;
    QString password;
    bool	enabled;

public:
    Account();
    QString toString();

    const QString &getUsername() const;
    void setUsername(const QString &newUsername);

    const QString &getPassword() const;
    void setPassword(const QString &newPassword);

    bool getEnabled() const;
    void setEnabled(bool newEnabled);

    const QString &getPip() const;
    void setPip(const QString &newPip);

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

    const QString &getDescription() const;
    void setDescription(const QString &newDescription);

    const QString &getRole() const;
    void setRole(const QString &newRole);
};

