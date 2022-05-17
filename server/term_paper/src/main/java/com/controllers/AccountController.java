package com.controllers;


import com.dao.AccountDAO;
import com.models.Account;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.*;
import java.sql.SQLException;


@RestController
@RequestMapping("/account")
public class AccountController {

    @Autowired
    private AccountDAO accountDAO;

    @PostMapping("/create")
    @ResponseBody
    @ResponseStatus(HttpStatus.CREATED)
    public void create(@RequestBody Account account) throws SQLException {
        this.accountDAO.save(account);
    }


    @GetMapping(value = "/get/{request_data}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    @ResponseStatus(HttpStatus.FOUND)
    public Account get(@PathVariable("request_data") String requestData) throws SQLException {
        return accountDAO.get(requestData);
    }


    @PatchMapping("/update/{request_data}")
    @ResponseBody
    @ResponseStatus(HttpStatus.OK)
    public void update(@PathVariable("request_data") String requestData, @RequestBody Account account) throws SQLException {
        accountDAO.update(account, requestData);
    }


    @DeleteMapping("/delete/{request_data}")
    @ResponseStatus(HttpStatus.OK)
    public void delete(@PathVariable("request_data") String requestData) throws SQLException {
        accountDAO.delete(requestData);
    }
}
