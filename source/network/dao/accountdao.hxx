#pragma once

#include <QObject>
#include <QString>
#include <QList>

#include "models/account.hxx"
#include "networkdao.hxx"


class AccountDAO : public QObject, public NetworkDAO<Account, QString> {
    Q_OBJECT

public:
    AccountDAO();

    bool create(const Account new_object) override;
    QList<Account> read(const QString read_of, QString option = "") override;
    bool update(const QString update_of, const Account updated_object) override;
    bool remove(const QString remove_of) override;
};

