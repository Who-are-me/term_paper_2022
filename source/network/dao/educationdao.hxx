#pragma once

#include <QObject>
#include <QList>
#include <QString>

#include "models/education.hxx"
#include "networkdao.hxx"


class EducationDAO : public QObject, public NetworkDAO<Education, int> {
    Q_OBJECT

private:
    QList<Education> readAll();
    QList<Education> readById(const int id);
    QList<Education> readWithPagination(const int page, const int item_in_page);

public:
    EducationDAO();
    EducationDAO(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies);
    ~EducationDAO() override;

    bool init(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) override;

    bool create(const Education new_object) override;
    QList<Education> read(const int read_of = -1, int option = -1) override;
    bool update(const int update_of, const Education updated_object) override;
    bool remove(const int remove_of) override;
};

