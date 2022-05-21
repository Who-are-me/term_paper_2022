#pragma once

#include <QList>
#include <QString>


// this class implement crud pattern
// T1 working object
// T2 type of value for search
template<typename T1, typename T2>
class DAO {
public:
    virtual ~DAO() {};

    virtual bool init(QString create_url, QString read_url, QString update_url, QString remove_url, QString cookies) = 0;
    virtual bool create(T1 new_object) = 0;
    virtual QList<T1> read(T2 read_of, T2 option) = 0;
    virtual bool update(T2 update_of, T1 updated_object) = 0;
    virtual bool remove(T2 remove_of) = 0;
};


