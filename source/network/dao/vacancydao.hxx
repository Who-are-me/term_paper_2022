#pragma once

#include <QObject>
#include <QList>
#include <QString>

#include "models/vacancy.hxx"
#include "networkdao.hxx"


class VacancyDAO : public QObject, public NetworkDAO<Vacancy, int> {
    Q_OBJECT

private:
    QList<Vacancy> readAll();
    QList<Vacancy> readById(const int id);
    QList<Vacancy> readWithPagination(const int page, const int item_in_page);

public:
    VacancyDAO();
    VacancyDAO(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies);

    bool init(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) override;

    bool create(const Vacancy new_object) override;
    QList<Vacancy> read(const int read_of = -1, int option = -1) override;
    bool update(const int update_of, const Vacancy updated_object) override;
    bool remove(const int remove_of) override;
};

