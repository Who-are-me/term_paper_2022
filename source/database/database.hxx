#pragma once


#include <QObject>


class Database : public QObject {
private:
    Q_OBJECT

public:
    Database();
    ~Database();
};

