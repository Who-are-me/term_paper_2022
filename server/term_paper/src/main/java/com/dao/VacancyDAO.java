package com.dao;

import com.models.Education;
import com.models.Vacancy;
import org.springframework.beans.factory.annotation.Autowired;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;


// TODO make me
public class VacancyDAO  implements Dao<Vacancy> {
    private DataBase db;

    @Autowired
    public VacancyDAO(DataBase db) {
        this.db = db;
    }

    public VacancyDAO() {}

    // TODO this function getPage isn't rests
    public List<Vacancy> getPage(int page_number, int item_of_page) throws SQLException {
        page_number = (int)Integer.toUnsignedLong(page_number);
        item_of_page = (int)Integer.toUnsignedLong(item_of_page);
        Statement statement = db.getConnection().createStatement();

        List<Vacancy> list = new ArrayList<>();
        Vacancy ei;
        ResultSet resultSet = statement.executeQuery("WITH vacancy AS (SELECT vacancy.*, ROW_NUMBER() OVER (ORDER BY id) AS 'row' FROM vacancy) SELECT vacancy.* FROM vacancy WHERE row > " + (page_number * item_of_page - item_of_page) + " LIMIT " + item_of_page);

        while (resultSet.next()) {
            ei = new Vacancy();
            ei.setId(resultSet.getInt("id"));
            ei.setTitle(resultSet.getString("title"));
            ei.setDescription(resultSet.getString("description"));
            ei.setSalary(resultSet.getInt("salary"));
            ei.setEducation(Education.values()[resultSet.getInt("education")]);
            ei.setExperience(resultSet.getInt("experience"));
            ei.setCity(resultSet.getString("city"));
            ei.setLocation(resultSet.getString("location"));
            ei.setPhone(resultSet.getString("phone"));
            ei.setEmail(resultSet.getString("email"));
            ei.setCompany(resultSet.getString("company"));

            list.add(ei);
        }

        return list;
    }

    @Override
    public void save(Vacancy data) throws SQLException {

    }

    @Override
    public Vacancy get(String pattern) throws SQLException {
        return null;
    }

    @Override
    public void delete(String pattern) throws SQLException {

    }

    @Override
    public void update(Vacancy data, String pattern) throws SQLException {

    }
}
