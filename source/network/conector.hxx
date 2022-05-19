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
        , public AccountDAO
        , public EducationDAO
        , public ResumeDAO
        , public VacancyDAO
{
    Q_OBJECT

private:
    QString					connect_host;
    QString					connect_port;
    QString					connect_path_to_login;

public:
    Conector();
    ~Conector();

    bool login(QString username, QString password);

    // host
    const QString &getConnectHost() const;
    void setConnectHost(const QString &new_connect_host);

    // path to login page
    const QString &getConnectPathToLogin() const;
    void setConnectPathToLogin(const QString &new_connect_path_to_login);

    // port
    const QString &getConnectPort() const;
    void setConnectPort(const QString &new_connect_port);

public slots:
    void loginInServer();
};

