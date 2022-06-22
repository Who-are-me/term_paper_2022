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
    bool initRequest(QString path) override;
    QNetworkReply* send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) override;

    QList<Account> readAll();

public:
    AccountDAO();
    AccountDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove);
    ~AccountDAO() override;

    bool init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) override;
    bool setCookie(QString cookie) override;

    bool create(const Account new_object) override;
    QList<Account> read(const QString read_of = "", QString option = nullptr, QString filter = nullptr) override;
    bool update(const QString update_of, const Account updated_object) override;
    bool remove(const QString remove_of) override;

private slots:
    void onCreate(QNetworkReply *reply);
    void onRead(QNetworkReply *reply);
    void onUpdate(QNetworkReply *reply);
    void onRemove(QNetworkReply *reply);
};

