package com.controllers;


import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;


@RestController
public class MainController {

    @GetMapping("/")
    @ResponseStatus(HttpStatus.OK)
    public void all() {
        System.out.println("ALL");
    }


    @GetMapping("/user")
    @ResponseStatus(HttpStatus.ACCEPTED)
    public void user() {
        System.out.println("USER");
    }


    @GetMapping("/admin")
    @ResponseStatus(HttpStatus.ACCEPTED)
    public void admin() {
        System.out.println("ADMIN");
    }
}
