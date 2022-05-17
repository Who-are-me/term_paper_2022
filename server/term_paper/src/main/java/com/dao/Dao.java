package com.dao;


import java.sql.SQLException;


public interface Dao<T> {
    void save(T data) throws SQLException;

    T get(String pattern) throws SQLException;

    void delete(String pattern) throws SQLException;

    void update(T data, String pattern) throws SQLException;
}
