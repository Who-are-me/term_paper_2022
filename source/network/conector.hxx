#pragma once


#include <QObject>
#include <QtNetwork/QtNetwork>

#include "cookiesmanager.hxx"
#include "dao/accountdao.hxx"
#include "dao/educationdao.hxx"
#include "dao/resumedao.hxx"
#include "dao/vacancydao.hxx"


// TODO make internet connector
class Conector
        : public QObject
        , public CookiesManager
{
    Q_OBJECT

private:
    // path values
    QString					connect_host;
    QString					connect_port;
    QString					connect_path_to_login;
    QString					logged_user;
    QString					account_path_to_get;
    QString					account_path_to_test_user_connect;
    // end path values
    QNetworkAccessManager	*net_manager;
    QNetworkRequest			net_request;
    bool					is_admin;
    bool					is_logged;

    bool checkIsAdmin();
    bool initRequest(QString host, QString port, QString path);
    QNetworkReply* send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data);

public:
    Conector();
    ~Conector();

    AccountDAO 		account;
    EducationDAO 	education;
    ResumeDAO		resume;
    VacancyDAO		vacancy;

    bool login(QString username, QString password);
    bool checkIfEnableLoggedUser();
    void deleteCookie();
    bool isLogged();

    // host
    const QString &getConnectHost() const;
    void setConnectHost(const QString &new_connect_host);

    // path to login page
    const QString &getConnectPathToLogin() const;
    void setConnectPathToLogin(const QString &new_connect_path_to_login);

    // port
    const QString &getConnectPort() const;
    void setConnectPort(const QString &new_connect_port);

    // logged user
    const QString &getLoggedUser() const;
    void setLoggedUser(const QString &new_logged_user);

    // is logged
    const QString &getIsLoggedUser() const;
    void setIsLoggedUser(const QString &new_data);

    // is admin
    const bool &getIsAdmin() const;
    void setIsAdmin(bool &new_data);

    // path to account get
    const QString &getAccountPathToGet() const;
    void setAccountPathToGet(const QString &new_account_path_to_get);

    // path to account test page
    const QString &getAccountPathToTestUserConnect() const;
    void setAccountPathToTestUserConnect(const QString &new_account_path_to_test_user_connect);

public slots:
    void loginInServer();

private slots:
    void onCheckIfEnableLoggedUser(QNetworkReply *reply);
};

