package com.controllers;


import com.dao.VacancyDAO;
import com.models.Vacancy;
import com.repository.VacancyRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.*;

import java.sql.SQLException;
import java.util.List;
import java.util.Optional;


// TODO add route with pagination
@RestController
@RequestMapping("/vacancy")
public class VacancyController {

    @Autowired
    private VacancyDAO dao;
    @Autowired
    private VacancyRepository repository;

    @PostMapping("/create")
    @ResponseBody
    @ResponseStatus(HttpStatus.CREATED)
    public void create(@RequestBody Vacancy vacancy) {
        repository.save(vacancy);
    }


    @GetMapping(value = "/{request_data}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public Optional<Vacancy> getById(@PathVariable("request_data") int requestData) {
        return repository.findById(requestData);
    }


    @GetMapping(value = "/p/{page}/{item_of_page}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public List<Vacancy> getPage(@PathVariable("page") int page, @PathVariable("item_of_page") int item_of_page) throws SQLException {
        return dao.getPage(page, item_of_page);
    }


    @GetMapping(value = "/p/{page}/{item_of_page}/{username}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public List<Vacancy> getPageByUsername(@PathVariable("page") int page, @PathVariable("item_of_page") int item_of_page, @PathVariable("username") String username) throws SQLException {
        return dao.getPageByUsername(page, item_of_page, username);
    }


    @GetMapping(value = "", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public Iterable<Vacancy> getAll() {
        return repository.findAll();
    }


    @PatchMapping("/{request_data}")
    @ResponseBody
    @ResponseStatus(HttpStatus.OK)
    public void updateById(@PathVariable("request_data") int requestData, @RequestBody Vacancy vacancy) {
        Vacancy vac = repository.findOneById(requestData);

        if (vac.getId() != 0) {
            vac = vacancy;
            vac.setId(requestData);
            repository.save(vac);
        }
        else {
            repository.save(vacancy);
        }
    }


    @DeleteMapping("/{request_data}")
    @ResponseBody
    @ResponseStatus(HttpStatus.OK)
    public void deleteById(@PathVariable("request_data") int requestData) {
        repository.deleteById(requestData);
    }
}
