#include "accountdao.hxx"


AccountDAO::AccountDAO() {

}


bool AccountDAO::create(const Account new_object) {
    return true;
}


QList<Account> AccountDAO::read(const QString read_of, QString option) {
    return QList<Account>();
}


bool AccountDAO::update(const QString update_of, const Account updated_object) {
    return true;
}


bool AccountDAO::remove(const QString remove_of) {
    return true;
}
