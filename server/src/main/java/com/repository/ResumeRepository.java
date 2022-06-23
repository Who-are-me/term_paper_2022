package com.repository;


import com.models.Resume;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Repository;


@Component
@Repository
public interface ResumeRepository extends CrudRepository<Resume, Integer> {
    Resume findOneById(int id);
}
