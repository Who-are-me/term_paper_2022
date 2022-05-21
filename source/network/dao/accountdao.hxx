#pragma once

#include <QObject>
#include <QString>
#include <QList>
#include <QtNetwork/QtNetwork>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "models/account.hxx"
#include "networkdao.hxx"


class AccountDAO : public QObject, public NetworkDAO<Account, QString> {
    Q_OBJECT

private:
    void init();

public:
    AccountDAO();
    AccountDAO(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies);
    ~AccountDAO() override;

    bool init(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) override;

    bool create(const Account new_object) override;
    QList<Account> read(const QString read_of, QString option = "") override;
    bool update(const QString update_of, const Account updated_object) override;
    bool remove(const QString remove_of) override;

private slots:
    void onCreate(QNetworkReply *reply);
    void onRead(QNetworkReply *reply);
    void onUpdate(QNetworkReply *reply);
    void onRemove(QNetworkReply *reply);
};

