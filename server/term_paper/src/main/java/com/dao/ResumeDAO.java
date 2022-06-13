package com.dao;

import com.models.Resume;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;


// TODO test me
@Component
public class ResumeDAO implements Dao<Resume> {
    private DataBase db;

    @Autowired
    public ResumeDAO(DataBase db) {
        this.db = db;
    }

    public ResumeDAO() {}


    // TODO test me and formatting me
    // TODO this function getPage isn't rests
    public List<Resume> getPage(int page_number, int item_of_page) throws SQLException {
        page_number = (int)Integer.toUnsignedLong(page_number);
        item_of_page = (int)Integer.toUnsignedLong(item_of_page);
        Statement statement = db.getConnection().createStatement();

        List<Resume> list = new ArrayList<>();
        Resume ei;
        ResultSet resultSet = statement.executeQuery("WITH resume AS (SELECT resume.*, ROW_NUMBER() OVER (ORDER BY id) AS 'row' FROM resume) SELECT resume.* FROM resume WHERE row > " + (page_number * item_of_page - item_of_page) + " LIMIT " + item_of_page);

        while (resultSet.next()) {
            ei = new Resume();
            ei.setId(resultSet.getInt("id"));
            ei.setPip(resultSet.getString("pip"));
            ei.setSoft_skills(resultSet.getString("soft_skills"));
            ei.setHard_skills(resultSet.getString("hard_skills"));
            ei.setLanguage(resultSet.getString("language"));
            ei.setHobbies(resultSet.getString("hobbies"));
            ei.setPhone(resultSet.getString("phone"));
            ei.setEmail(resultSet.getString("email"));
            ei.setSkype(resultSet.getString("skype"));
            ei.setQualifications(resultSet.getString("qualification"));
            ei.setAbout_myself(resultSet.getString("about_myself"));
            ei.setOwner(resultSet.getString("owner"));

            list.add(ei);
        }

        return list;
    }


    // TODO test me and formatting me
    // TODO this function getPage isn't rests
    public List<Resume> getPageByUsername(int page_number, int item_of_page, String username) throws SQLException {
        page_number = (int)Integer.toUnsignedLong(page_number);
        item_of_page = (int)Integer.toUnsignedLong(item_of_page);
        Statement statement = db.getConnection().createStatement();

        List<Resume> list = new ArrayList<>();
        Resume ei;
        ResultSet resultSet = statement.executeQuery("WITH resume AS (SELECT resume.*, ROW_NUMBER() OVER (ORDER BY id) AS 'row' FROM resume) SELECT resume.* FROM resume WHERE owner = '" + username + "' AND row > " + (page_number * item_of_page - item_of_page) + " LIMIT " + item_of_page);

        while (resultSet.next()) {
            ei = new Resume();
            ei.setId(resultSet.getInt("id"));
            ei.setPip(resultSet.getString("pip"));
            ei.setSoft_skills(resultSet.getString("soft_skills"));
            ei.setHard_skills(resultSet.getString("hard_skills"));
            ei.setLanguage(resultSet.getString("language"));
            ei.setHobbies(resultSet.getString("hobbies"));
            ei.setPhone(resultSet.getString("phone"));
            ei.setEmail(resultSet.getString("email"));
            ei.setSkype(resultSet.getString("skype"));
            ei.setQualifications(resultSet.getString("qualification"));
            ei.setAbout_myself(resultSet.getString("about_myself"));
            ei.setOwner(resultSet.getString("owner"));

            list.add(ei);
        }

        return list;
    }

    @Override
    public void save(Resume data) throws SQLException {

    }

    @Override
    public Resume get(String pattern) throws SQLException {
        return null;
    }

    @Override
    public void delete(String pattern) throws SQLException {

    }

    @Override
    public void update(Resume data, String pattern) throws SQLException {

    }
}
