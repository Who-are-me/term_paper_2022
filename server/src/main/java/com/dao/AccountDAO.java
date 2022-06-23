package com.dao;


import com.models.Account;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Component;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;


@Component
public class AccountDAO implements Dao<Account> {
    private DataBase db;

    private BCryptPasswordEncoder en = new BCryptPasswordEncoder();

    @Autowired
    public AccountDAO(DataBase db) {
        this.db = db;
    }

    public AccountDAO() {}

    @Override
    public void save(Account account) throws SQLException {
        Statement statement = db.getConnection().createStatement();

        ResultSet resultSetCheck = statement.executeQuery("SELECT count(*) as number FROM accounts WHERE login_name = '" + account.getLogin_name() + "'");

        while (resultSetCheck.next()) {
            if (resultSetCheck.getInt("number") != 0) {
                System.out.println("Database [INFO]: User does not exist!");
                throw new SQLException("Username does exist!");
            }
        }

        statement.executeUpdate("INSERT INTO accounts " +
                " (pip, city, location, phone, email, company, description, login_name, login_password, role) " +
                " VALUES ('" +
                account.getPip() + "','" +
                account.getCity() + "','" +
                account.getLocation() + "','" +
                account.getPhone() + "','" +
                account.getEmail() + "','" +
                account.getCompany() + "','" +
                account.getDescription() + "','" +
                account.getLogin_name() + "','" +
                en.encode(account.getLogin_password()) + "','" +
                account.getRole() + "')");

        statement.executeUpdate("INSERT INTO users " +
                " (username, password, enabled)" +
                " VALUES ('" +
                account.getLogin_name() + "','" +
                en.encode(account.getLogin_password()) + "','" +
                1 + "') ");

        statement.executeUpdate("INSERT INTO authorities " +
                " (username, authority) VALUES ('" +
                account.getLogin_name() + "','" +
                account.getRole() + "') ");
    }


    @Override
    public Account get(String loginName) throws SQLException {
        Statement statement = db.getConnection().createStatement();

        Account account = new Account();

        ResultSet resultSetCheck = statement.executeQuery("SELECT count(*) as number FROM accounts WHERE login_name = '" + loginName + "'");

        while (resultSetCheck.next()) {
            if (resultSetCheck.getInt("number") == 0) {
                System.out.println("Database [INFO]: User does not exist!");
                return account;
            }
        }

        ResultSet resultSet = statement.executeQuery("SELECT * FROM accounts WHERE login_name = '" + loginName + "'");

        while (resultSet.next()) {
            account.setData(
                    resultSet.getInt("id"),
                    resultSet.getString("pip"),
                    resultSet.getString("city"),
                    resultSet.getString("location"),
                    resultSet.getString("phone"),
                    resultSet.getString("email"),
                    resultSet.getString("company"),
                    resultSet.getString("description"),
                    resultSet.getString("login_name"),
                    resultSet.getString("login_password"),
                    resultSet.getString("role")
            );
        }

        return account;
    }


    public List<Account> getAll() throws SQLException {
        Statement statement = db.getConnection().createStatement();

        List<Account> accounts = new ArrayList<>();
        Account account = new Account();

        ResultSet resultSetCheck = statement.executeQuery("SELECT count(*) as number FROM accounts");

        while (resultSetCheck.next()) {
            if (resultSetCheck.getInt("number") == 0) {
                System.out.println("Database [INFO]: User does not exist!");
                return accounts;
            }
        }

        ResultSet resultSet = statement.executeQuery("SELECT * FROM accounts");

        while (resultSet.next()) {
            account = new Account();
            account.setData(
                    resultSet.getInt("id"),
                    resultSet.getString("pip"),
                    resultSet.getString("city"),
                    resultSet.getString("location"),
                    resultSet.getString("phone"),
                    resultSet.getString("email"),
                    resultSet.getString("company"),
                    resultSet.getString("description"),
                    resultSet.getString("login_name"),
                    resultSet.getString("login_password"),
                    resultSet.getString("role")
            );

            accounts.add(account);
        }

        return accounts;
    }


    @Override
    public void delete(String loginName) throws SQLException {
        Statement statement = db.getConnection().createStatement();

        ResultSet resultSet = statement.executeQuery("SELECT * FROM accounts WHERE login_name = '" + loginName + "'");

        if (resultSet.next() == false) {
            System.out.println("Database [INFO]: Username does not exist!");
            throw new SQLException("Username does not exist!");
        }

        statement.executeUpdate("DELETE FROM accounts WHERE login_name = '" + loginName + "'");
        statement.executeUpdate("DELETE FROM authorities WHERE username = '" + loginName + "'");
        statement.executeUpdate("DELETE FROM users WHERE username = '" + loginName + "'");
    }


    @Override
    public void update(Account account, String loginName) throws SQLException {
        Statement statement = db.getConnection().createStatement();

        ResultSet resultSet = statement.executeQuery("SELECT count(*) as number FROM accounts WHERE login_name = '" + loginName + "'");

        while (resultSet.next()) {
            if (resultSet.getInt("number") == 0) {
                System.out.println("Database [INFO]: Username does not exist!");
                throw new SQLException("Username does not exist!");
            }
        }

        statement.executeUpdate("UPDATE accounts " +
                " SET " +
                " pip = '" +                account.getPip() + "'" +
                ", city = '" +              account.getCity() + "'" +
                ", location = '" +          account.getLocation() + "'" +
                ", phone = '" +             account.getPhone() + "'" +
                ", email = '" +             account.getEmail() + "'" +
                ", company = '" +           account.getCompany() + "'" +
                ", description = '" +       account.getDescription() + "'" +
                ", login_name = '" +        account.getLogin_name() + "'" +
                ", login_password = '" +    en.encode(account.getLogin_password()) + "'" +
                ", role = '" +              account.getRole() + "'" +
                " WHERE " +
                " login_name ='" +          loginName + "'" );

        statement.executeQuery("SET FOREIGN_KEY_CHECKS=0");

        statement.executeUpdate("UPDATE authorities " +
                " SET " +
                " username = '" +           account.getLogin_name() + "'" +
                ", authority ='" +          account.getRole() + "'" +
                " WHERE " +
                " username ='" +            loginName + "'");

        statement.executeUpdate("UPDATE users " +
                " SET " +
                " username = '" +           account.getLogin_name() + "'" +
                ", password = '" +          en.encode(account.getLogin_password()) + "'" +
                ", enabled = 1" +
                " WHERE " +
                "username = '" + loginName + "'");

        statement.executeQuery("SET FOREIGN_KEY_CHECKS=1");
    }
}
