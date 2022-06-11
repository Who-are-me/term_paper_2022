#pragma once

#include <QObject>
#include <QList>
#include <QString>
#include <QtNetwork/QtNetwork>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "models/resume.hxx"
#include "networkdao.hxx"


class ResumeDAO : public QObject, public NetworkDAO<Resume, int> {
    Q_OBJECT

private:
    void init();
    QList<Resume> readAll();
    QList<Resume> readById(const int id);
    QList<Resume> readWithPagination(const int page, const int item_in_page);
    bool initRequest(QString path) override;
    QNetworkReply* send(QString method, QNetworkAccessManager *manager, QNetworkRequest &request, QByteArray send_data) override;

public:
    ResumeDAO();
    ResumeDAO(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove);
    ~ResumeDAO() override;

    bool init(QString host, QString port, QString path_create, QString path_read, QString path_update, QString path_remove) override;
    bool setCookie(QString cookie) override;

    bool create(const Resume new_object) override;
    QList<Resume> read(const int read_of = -1, int option = -1) override;
    bool update(const int update_of, const Resume updated_object) override;
    bool remove(const int remove_of) override;
};

