package com.controllers;


import com.dao.Dao;
import com.dao.EducationInternshipDAO;
import com.repository.EducationInternshipRepository;
import com.models.EducationInternship;
import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.*;

import java.sql.SQLException;
import java.util.List;
import java.util.Optional;


@RestController
@RequestMapping("/edu")
public class EducationInternshipController {

    private static SessionFactory sessionFactory;

    @Autowired
    private EducationInternshipDAO dao;

    @Autowired
    private EducationInternshipRepository repository;

    @PostMapping("/create")
    @ResponseBody
    @ResponseStatus(HttpStatus.CREATED)
    public void create(@RequestBody EducationInternship educationInternship) {
        System.out.println("edu/create `POST`\nJSON: " + educationInternship.toString());
        repository.save(educationInternship);
    }


    @GetMapping(value = "/{request_data}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public Optional<EducationInternship> getById(@PathVariable("request_data") int requestData) {
        System.out.println("edu/" + requestData + " `GET`");
        return repository.findById(requestData);
    }


    @GetMapping(value = "/p/{page}/{item_of_page}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public List<EducationInternship> getPage(@PathVariable("page") int page, @PathVariable("item_of_page") int item_of_page) throws SQLException {
        System.out.println("edu/p/" + page + "/" + item_of_page);
        return dao.getPage(page, item_of_page);
    }


    @GetMapping(value = "/p/{page}/{item_of_page}/{username}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public List<EducationInternship> getPageByUsername(@PathVariable("page") int page, @PathVariable("item_of_page") int item_of_page, @PathVariable("username") String username) throws SQLException {
        System.out.println("edu/p/" + page + "/" + item_of_page + "/" + username);
        return dao.getPageByUsername(page, item_of_page, username);
    }


    @GetMapping(value = "", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public Iterable<EducationInternship> getAll() {
        System.out.println("edu/ `GET`");
        return repository.findAll();
    }


    @PatchMapping("/{request_data}")
    @ResponseBody
    @ResponseStatus(HttpStatus.OK)
    public void updateById(@PathVariable("request_data") int requestData, @RequestBody EducationInternship educationInternship) {
        System.out.println("edu/" + requestData + " `PATCH`");
        EducationInternship edu = repository.findOneById(requestData);

        if (edu.getId() != 0) {
            edu = educationInternship;
            edu.setId(requestData);
            repository.save(edu);
        }
        else {
            repository.save(educationInternship);
        }
    }


    @DeleteMapping("/{request_data}")
    @ResponseBody
    @ResponseStatus(HttpStatus.OK)
    public void deleteById(@PathVariable("request_data") int requestData) {
        System.out.println("edu/" + requestData + " `DELETE`");
        repository.deleteById(requestData);
    }
}
