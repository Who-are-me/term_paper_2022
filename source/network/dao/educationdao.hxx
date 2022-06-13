#pragma once

#include <QObject>
#include <QList>
#include <QString>
#include <QtNetwork/QtNetwork>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "models/education.hxx"
#include "networkdao.hxx"


class EducationDAO : public QObject, public NetworkDAO<Education, int> {
    Q_OBJECT

private:
    void init();
    QList<Education> readAll();
    QList<Education> readById(const int id);
    QList<Education> readWithPagination(const int page, const int item_in_page, const QString username = nullptr);
    bool initRequest(QString path) override;
    QNetworkReply* send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) override;

public:
    EducationDAO();
    EducationDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove);
    ~EducationDAO() override;

    bool init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) override;
    bool initAdditionalPaths(QString path_read_all, QString path_read_pag, QString path_read_pag_by_username);
    bool setCookie(QString cookie) override;

    bool create(const Education new_object) override;
    QList<Education> read(const int read_of = -1, int option = -1, QString filter = nullptr) override;
    bool update(const int update_of, const Education updated_object) override;
    bool remove(const int remove_of) override;
};

