package com.models;


import org.hibernate.annotations.DynamicUpdate;
import javax.persistence.*;
import java.time.LocalDate;


@Entity
@DynamicUpdate
public class EducationInternship {

    @Id
    @GeneratedValue(strategy= GenerationType.AUTO)
    private int id;

    @Column
    private String title;

    @Column
    private String description;

    @Column
    private LocalDate for_time_start, for_time_end;

    @Column
    private Education req_education;

    @Column
    private int req_experience;

    @Column
    private String option_condition;

    @Column
    private String city;

    @Column
    private String location;

    @Column
    private String phone;

    @Column
    private String email;

    @Column
    private String company;


    public boolean isNull() {
        if (title == null) {
            return true;
        }
        else {
            return false;
        }
    }


    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public LocalDate getFor_time_start() {
        return for_time_start;
    }

    public void setFor_time_start(LocalDate for_time_start) {
        this.for_time_start = for_time_start;
    }

    public LocalDate getFor_time_end() {
        return for_time_end;
    }

    public void setFor_time_end(LocalDate for_time_end) {
        this.for_time_end = for_time_end;
    }

    public Education getReq_education() {
        return req_education;
    }

    public void setReq_education(Education req_education) {
        this.req_education = req_education;
    }

    public int getReq_experience() {
        return req_experience;
    }

    public void setReq_experience(int req_experience) {
        this.req_experience = req_experience;
    }

    public String getOption_condition() {
        return option_condition;
    }

    public void setOption_condition(String option_condition) {
        this.option_condition = option_condition;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getCompany() {
        return company;
    }

    public void setCompany(String company) {
        this.company = company;
    }

    @Override
    public String toString() {
        return "EducationInternship{" +
                "id=" + id +
                ", title='" + title + '\'' +
                ", description='" + description + '\'' +
                ", for_time_start=" + for_time_start +
                ", for_time_end=" + for_time_end +
                ", req_education=" + req_education +
                ", req_experience=" + req_experience +
                ", option_condition='" + option_condition + '\'' +
                ", city='" + city + '\'' +
                ", location='" + location + '\'' +
                ", phone='" + phone + '\'' +
                ", email='" + email + '\'' +
                ", company='" + company + '\'' +
                '}';
    }
}
