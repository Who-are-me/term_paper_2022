package com.dao;

import com.models.Education;
import com.models.EducationInternship;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

@Component
public class EducationInternshipDAO implements Dao<EducationInternship> {
    private DataBase db;

    @Autowired
    public EducationInternshipDAO(DataBase db) {
        this.db = db;
    }


    public EducationInternshipDAO() {}


    // TODO test me and formatting me
    public List<EducationInternship> getPage(int page_number, int item_of_page) throws SQLException {
        page_number = (int)Integer.toUnsignedLong(page_number);
        item_of_page = (int)Integer.toUnsignedLong(item_of_page);
        Statement statement = db.getConnection().createStatement();

        List<EducationInternship> list = new ArrayList<>();
        EducationInternship ei;
        ResultSet resultSet = statement.executeQuery("WITH education_internship AS (SELECT education_internship.*, ROW_NUMBER() OVER (ORDER BY id) AS 'row' FROM education_internship) SELECT education_internship.* FROM education_internship WHERE row > " + (page_number * item_of_page - item_of_page) + " LIMIT " + item_of_page);

        while (resultSet.next()) {
            ei = new EducationInternship();
            ei.setId(resultSet.getInt("id"));
            ei.setTitle(resultSet.getString("title"));
            ei.setDescription(resultSet.getString("description"));
            ei.setFor_time_start(resultSet.getDate("for_time_start").toLocalDate());
            ei.setFor_time_end(resultSet.getDate("for_time_end").toLocalDate());
            ei.setReq_experience(resultSet.getInt("req_experience"));
            ei.setOption_condition(resultSet.getString("option_condition"));
            ei.setCity(resultSet.getString("city"));
            ei.setLocation(resultSet.getString("location"));
            ei.setPhone(resultSet.getString("phone"));
            ei.setEmail(resultSet.getString("email"));
            ei.setCompany(resultSet.getString("company"));
            ei.setReq_education(Education.values()[resultSet.getInt("req_education")]);
            ei.setOwner(resultSet.getString("owner"));

            list.add(ei);
        }

        return list;
    }


    // TODO test me and formatting me
    public List<EducationInternship> getPageByUsername(int page_number, int item_of_page, String username) throws SQLException {
        page_number = (int)Integer.toUnsignedLong(page_number);
        item_of_page = (int)Integer.toUnsignedLong(item_of_page);
        Statement statement = db.getConnection().createStatement();

        List<EducationInternship> list = new ArrayList<>();
        EducationInternship ei;
        ResultSet resultSet = statement.executeQuery("WITH education_internship AS (SELECT education_internship.*, ROW_NUMBER() OVER (ORDER BY id) AS 'row' FROM education_internship) SELECT education_internship.* FROM education_internship WHERE owner = '" + username + "' AND row > " + (page_number * item_of_page - item_of_page) + " LIMIT " + item_of_page);

        while (resultSet.next()) {
            ei = new EducationInternship();
            ei.setId(resultSet.getInt("id"));
            ei.setTitle(resultSet.getString("title"));
            ei.setDescription(resultSet.getString("description"));
            ei.setFor_time_start(resultSet.getDate("for_time_start").toLocalDate());
            ei.setFor_time_end(resultSet.getDate("for_time_end").toLocalDate());
            ei.setReq_experience(resultSet.getInt("req_experience"));
            ei.setOption_condition(resultSet.getString("option_condition"));
            ei.setCity(resultSet.getString("city"));
            ei.setLocation(resultSet.getString("location"));
            ei.setPhone(resultSet.getString("phone"));
            ei.setEmail(resultSet.getString("email"));
            ei.setCompany(resultSet.getString("company"));
            ei.setReq_education(Education.values()[resultSet.getInt("req_education")]);
            ei.setOwner(resultSet.getString("owner"));

            list.add(ei);
        }

        return list;
    }


    @Override
    public void save(EducationInternship data) throws SQLException {

    }


    @Override
    public EducationInternship get(String pattern) throws SQLException {
        return null;
    }


    @Override
    public void delete(String pattern) throws SQLException {

    }


    @Override
    public void update(EducationInternship data, String pattern) throws SQLException {

    }
}
