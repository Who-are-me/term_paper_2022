#pragma once

#include <QObject>
#include <QList>
#include <QString>
#include <QtNetwork/QtNetwork>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "models/vacancy.hxx"
#include "networkdao.hxx"


class VacancyDAO : public QObject, public NetworkDAO<Vacancy, int> {
    Q_OBJECT

private:
    void init();
    QList<Vacancy> readAll();
    QList<Vacancy> readById(const int id);
    QList<Vacancy> readWithPagination(const int page, const int item_in_page);
    bool initRequest(QString path) override;
    QNetworkReply* send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) override;

public:
    VacancyDAO();
    VacancyDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove);
    ~VacancyDAO() override;

    bool init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) override;
    bool setCookie(QString cookie) override;

    bool create(const Vacancy new_object) override;
    QList<Vacancy> read(const int read_of = -1, int option = -1) override;
    bool update(const int update_of, const Vacancy updated_object) override;
    bool remove(const int remove_of) override;
};

