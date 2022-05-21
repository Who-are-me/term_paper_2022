#pragma once

#include <QObject>
#include <QList>
#include <QString>

#include "models/resume.hxx"
#include "networkdao.hxx"


class ResumeDAO : public QObject, public NetworkDAO<Resume, int> {
    Q_OBJECT

private:
    QList<Resume> readAll();
    QList<Resume> readById(const int id);
    QList<Resume> readWithPagination(const int page, const int item_in_page);

public:
    ResumeDAO();
    ResumeDAO(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies);

    bool init(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) override;

    bool create(const Resume new_object) override;
    QList<Resume> read(const int read_of = -1, int option = -1) override;
    bool update(const int update_of, const Resume updated_object) override;
    bool remove(const int remove_of) override;
};

