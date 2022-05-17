package com.models;


import org.hibernate.annotations.DynamicUpdate;
import javax.persistence.*;


@Entity
@DynamicUpdate
public class Resume {

    @Id
    @GeneratedValue(strategy= GenerationType.AUTO)
    private int id;

    @Column
    private String pip;

    @Column
    private String soft_skills;

    @Column
    private String hard_skills;

    @Column
    private String language;

    @Column
    private String hobbies;

    @Column
    private String phone;

    @Column
    private String email;

    @Column
    private String skype;

    @Column
    private String qualifications;

    @Column
    private String about_myself;


    public boolean isNull() {
        if (pip == null) {
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

    public String getPip() {
        return pip;
    }

    public void setPip(String pip) {
        this.pip = pip;
    }

    public String getSoft_skills() {
        return soft_skills;
    }

    public void setSoft_skills(String soft_skills) {
        this.soft_skills = soft_skills;
    }

    public String getHard_skills() {
        return hard_skills;
    }

    public void setHard_skills(String hard_skills) {
        this.hard_skills = hard_skills;
    }

    public String getLanguage() {
        return language;
    }

    public void setLanguage(String language) {
        this.language = language;
    }

    public String getHobbies() {
        return hobbies;
    }

    public void setHobbies(String hobbies) {
        this.hobbies = hobbies;
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

    public String getSkype() {
        return skype;
    }

    public void setSkype(String skype) {
        this.skype = skype;
    }

    public String getQualifications() {
        return qualifications;
    }

    public void setQualifications(String qualifications) {
        this.qualifications = qualifications;
    }

    public String getAbout_myself() {
        return about_myself;
    }

    public void setAbout_myself(String about_myself) {
        this.about_myself = about_myself;
    }


    @Override
    public String toString() {
        return "Resume{" +
                "id=" + id +
                ", pip='" + pip + '\'' +
                ", soft_skills='" + soft_skills + '\'' +
                ", hard_skills='" + hard_skills + '\'' +
                ", language='" + language + '\'' +
                ", hobbies='" + hobbies + '\'' +
                ", phone='" + phone + '\'' +
                ", email='" + email + '\'' +
                ", skype='" + skype + '\'' +
                ", qualifications='" + qualifications + '\'' +
                ", about_myself='" + about_myself + '\'' +
                '}';
    }
}
