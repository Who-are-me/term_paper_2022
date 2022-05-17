#pragma once

#include <QObject>
#include <QString>


class Account : public QObject {
    Q_OBJECT

private:
    QString username;
    QString password;
    bool	enabled;

public:
    Account();

    const QString &getUsername() const;
    void setUsername(const QString &newUsername);

    const QString &getPassword() const;
    void setPassword(const QString &newPassword);

    bool getEnabled() const;
    void setEnabled(bool newEnabled);
};

