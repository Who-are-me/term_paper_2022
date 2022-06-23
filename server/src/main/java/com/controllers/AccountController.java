package com.controllers;


import com.dao.AccountDAO;
import com.models.Account;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.web.bind.annotation.*;
import javax.servlet.http.HttpServletResponse;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

// status code decode
// ok => 200
// created => 201
// accepted => 202
// found => 302
// not accepted => 403
// not found => 404

@RestController
@RequestMapping("/account")
public class AccountController {

    @Autowired
    private AccountDAO accountDAO;

    @PostMapping("/create")
    @ResponseBody
    public void create(@RequestBody Account account, HttpServletResponse response) throws SQLException {
        System.out.println("account/create" + "\nJSON: " + account.toString());

        try {
            this.accountDAO.save(account);
            response.setStatus(HttpServletResponse.SC_CREATED);
        }
        catch (Exception e) {
            response.setStatus(HttpServletResponse.SC_NOT_FOUND);
        }
    }


    @GetMapping(value = "/get/{request_data}", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public Account get(@PathVariable("request_data") String requestData, HttpServletResponse response) throws SQLException {
        System.out.println("account/get/" + requestData);

        Account acc = this.accountDAO.get(requestData);

        if(acc.isNull()) {
            response.setStatus(HttpServletResponse.SC_NOT_FOUND);
            return new Account();
        }
        else {
            response.setStatus(HttpServletResponse.SC_FOUND);
            return acc;
        }
    }

    @GetMapping(value = "/get/", produces = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public List<Account> getAll(HttpServletResponse response) throws SQLException {
        System.out.println("account/get/");

        List<Account> acc = this.accountDAO.getAll();

        if(acc.isEmpty()) {
            response.setStatus(HttpServletResponse.SC_NOT_FOUND);
            return new ArrayList<>();
        }
        else {
            response.setStatus(HttpServletResponse.SC_FOUND);
            return acc;
        }
    }


    @PatchMapping("/update/{request_data}")
    @ResponseBody
    public void update(@PathVariable("request_data") String requestData, @RequestBody Account account, HttpServletResponse response) throws SQLException {
        System.out.println("account/update/" + requestData + "\nJSON: " + account.toString());

        try {
            this.accountDAO.update(account, requestData);
            response.setStatus(HttpServletResponse.SC_OK);
        }
        catch (Exception e) {
            response.setStatus(HttpServletResponse.SC_NOT_FOUND);
        }
    }


    @DeleteMapping("/delete/{request_data}")
    public void delete(@PathVariable("request_data") String requestData, HttpServletResponse response) throws SQLException {
        System.out.println("account/delete/" + requestData);

        try {
            this.accountDAO.delete(requestData);
            response.setStatus(HttpServletResponse.SC_OK);
        }
        catch (Exception e) {
            response.setStatus(HttpServletResponse.SC_NOT_FOUND);
        }
    }
}
