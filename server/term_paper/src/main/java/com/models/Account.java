package com.models;


import org.codehaus.jackson.JsonNode;
import org.codehaus.jackson.map.*;
import org.codehaus.jackson.map.type.*;
import org.codehaus.jackson.type.JavaType;


public class Account implements Deserializers {
    private int     id;
    private String  pip;
    private String  city;
    private String  location;
    private String  phone;
    private String  email;
    private String  company;
    private String  description;
    private String  login_name;
    private String  login_password;
    private String  role;


    public Account() {

    }


    public Account(int id, String pip, String city, String location,
                   String phone, String email, String company, String description,
                   String login_name, String login_password, String role) {
        this.id = id;
        this.pip = pip;
        this.city = city;
        this.location = location;
        this.phone = phone;
        this.email = email;
        this.company = company;
        this.description = description;
        this.login_name = login_name;
        this.login_password = login_password;
        this.role = role;
    }


    public void setData(int id, String pip, String city, String location,
                        String phone, String email, String company, String description,
                        String login_name, String login_password, String role) {
        this.id = id;
        this.pip = pip;
        this.city = city;
        this.location = location;
        this.phone = phone;
        this.email = email;
        this.company = company;
        this.description = description;
        this.login_name = login_name;
        this.login_password = login_password;
        this.role = role;
    }


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

    public String getPip() {
        return pip;
    }

    public String getCity() {
        return city;
    }

    public String getLocation() {
        return location;
    }

    public String getPhone() {
        return phone;
    }

    public String getEmail() {
        return email;
    }

    public String getCompany() {
        return company;
    }

    public String getDescription() {
        return description;
    }

    public String getLogin_name() {
        return login_name;
    }

    public String getLogin_password() {
        return login_password;
    }

    public String getRole() {
        return role;
    }


    @Override
    public JsonDeserializer<?> findArrayDeserializer(ArrayType type, DeserializationConfig config, DeserializerProvider provider, BeanProperty property, TypeDeserializer elementTypeDeserializer, JsonDeserializer<?> elementDeserializer) throws JsonMappingException {
        return null;
    }


    @Override
    public JsonDeserializer<?> findCollectionDeserializer(CollectionType type, DeserializationConfig config, DeserializerProvider provider, BeanDescription beanDesc, BeanProperty property, TypeDeserializer elementTypeDeserializer, JsonDeserializer<?> elementDeserializer) throws JsonMappingException {
        return null;
    }


    @Override
    public JsonDeserializer<?> findCollectionLikeDeserializer(CollectionLikeType type, DeserializationConfig config, DeserializerProvider provider, BeanDescription beanDesc, BeanProperty property, TypeDeserializer elementTypeDeserializer, JsonDeserializer<?> elementDeserializer) throws JsonMappingException {
        return null;
    }


    @Override
    public JsonDeserializer<?> findEnumDeserializer(Class<?> type, DeserializationConfig config, BeanDescription beanDesc, BeanProperty property) throws JsonMappingException {
        return null;
    }


    @Override
    public JsonDeserializer<?> findMapDeserializer(MapType type, DeserializationConfig config, DeserializerProvider provider, BeanDescription beanDesc, BeanProperty property, KeyDeserializer keyDeserializer, TypeDeserializer elementTypeDeserializer, JsonDeserializer<?> elementDeserializer) throws JsonMappingException {
        return null;
    }


    @Override
    public JsonDeserializer<?> findMapLikeDeserializer(MapLikeType type, DeserializationConfig config, DeserializerProvider provider, BeanDescription beanDesc, BeanProperty property, KeyDeserializer keyDeserializer, TypeDeserializer elementTypeDeserializer, JsonDeserializer<?> elementDeserializer) throws JsonMappingException {
        return null;
    }


    @Override
    public JsonDeserializer<?> findTreeNodeDeserializer(Class<? extends JsonNode> nodeType, DeserializationConfig config, BeanProperty property) throws JsonMappingException {
        return null;
    }


    @Override
    public JsonDeserializer<?> findBeanDeserializer(JavaType type, DeserializationConfig config, DeserializerProvider provider, BeanDescription beanDesc, BeanProperty property) throws JsonMappingException {
        return null;
    }


    @Override
    public String toString() {
        return "Account{" +
                "id=" + id +
                ", pip='" + pip + '\'' +
                ", city='" + city + '\'' +
                ", location='" + location + '\'' +
                ", phone='" + phone + '\'' +
                ", email='" + email + '\'' +
                ", company='" + company + '\'' +
                ", description='" + description + '\'' +
                ", login_name='" + login_name + '\'' +
                ", login_password='" + login_password + '\'' +
                ", role='" + role + '\'' +
                '}';
    }
}
