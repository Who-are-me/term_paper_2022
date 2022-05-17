package com.controllers;


import com.models.Vacancy;
import com.repository.VacancyRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.*;
import java.util.Optional;


@RestController
@RequestMapping("/vacancy")
public class VacancyController {
    
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
