#pragma once

#include <QString>
#include <QList>

#include "models/account.hxx"
#include "networkdao.hxx"


class AccountDAO : public NetworkDAO<Account, QString> {
public:
    AccountDAO();
    AccountDAO(QString url, QString cookies);

    bool init(QString url, QString cookies) override;

    bool create(const Account new_object) override;
    QList<Account> read(const QString read_of, QString option = "") override;
    bool update(const QString update_of, const Account updated_object) override;
    bool remove(const QString remove_of) override;
};

