package com.controllers;


import com.dao.ResumeDAO;
import com.models.Resume;
import com.repository.ResumeRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.*;

import java.sql.SQLException;
import java.util.List;
import java.util.Optional;


// TODO add route with pagination
@RestController
@RequestMapping("/resume")
public class ResumeController {

    @Autowired
    private ResumeDAO dao;
    @Autowired
    private ResumeRepository repository;

    @PostMapping("/create")
    @ResponseBody
    @ResponseStatus(HttpStatus.CREATED)
    public void create(@RequestBody Resume resume) {
        repository.save(resume);
    }


    @GetMapping(value = "/{request_data}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public Optional<Resume> getById(@PathVariable("request_data") int requestData) {
        return repository.findById(requestData);
    }


    @GetMapping(value = "/p/{page}/{item_of_page}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public List<Resume> getPage(@PathVariable("page") int page, @PathVariable("item_of_page") int item_of_page) throws SQLException {
        return dao.getPage(page, item_of_page);
    }


    @GetMapping(value = "/p/{page}/{item_of_page}/{username}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public List<Resume> getPageByUsername(@PathVariable("page") int page, @PathVariable("item_of_page") int item_of_page, @PathVariable("username") String username) throws SQLException {
        return dao.getPageByUsername(page, item_of_page, username);
    }


    @GetMapping(value = "", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public Iterable<Resume> getAll() {
        return repository.findAll();
    }


    @PatchMapping("/{request_data}")
    @ResponseBody
    @ResponseStatus(HttpStatus.OK)
    public void updateById(@PathVariable("request_data") int requestData, @RequestBody Resume resume) {
        Resume res = repository.findOneById(requestData);

        if (res.getId() != 0) {
            res = resume;
            res.setId(requestData);
            repository.save(res);
        }
        else {
            repository.save(resume);
        }
    }


    @DeleteMapping("/{request_data}")
    @ResponseBody
    @ResponseStatus(HttpStatus.OK)
    public void deleteById(@PathVariable("request_data") int requestData) {
        repository.deleteById(requestData);
    }
}
