package com.dao;


import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


@Component
public class DataBase {
    @Value("${spring.datasource.url}")
    private String url;

    @Value("${spring.datasource.username}")
    private String user;

    @Value("${spring.datasource.password}")
    private String password;

    @PostConstruct
    private void postConstructor() {
        System.out.println("Database [INFO]: Connected successful!");
    }


    @PreDestroy
    private void preDestroy() {
        System.out.println("Database [INFO]: Connect was close!");
    }


    public Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, user, password);
    }


    public String getUrl() {
        return url;
    }


    public String getUser() {
        return user;
    }


    public String getPassword() {
        return password;
    }
}
