package com.repository;


import com.models.Vacancy;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Repository;


@Component
@Repository
public interface VacancyRepository extends CrudRepository<Vacancy, Integer> {
    Vacancy findOneById(int id);
}
