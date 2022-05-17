package com.controllers;


import com.models.Resume;
import com.repository.ResumeRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.*;
import java.util.Optional;


@RestController
@RequestMapping("/resume")
public class ResumeController {

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
