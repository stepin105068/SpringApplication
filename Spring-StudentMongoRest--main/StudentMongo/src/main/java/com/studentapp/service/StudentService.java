package com.studentapp.service;

import java.util.List;


import com.studentapp.exception.StudentNotFoundException;
import com.studentapp.model.Address;
import com.studentapp.model.Student;

public interface StudentService {
	
	
	Student addStudent(Student student);
	Student getStudentById(int studentId) throws StudentNotFoundException;
	boolean deleteStudent(int studentId) throws StudentNotFoundException;
	List<Student> getAllStudents();
	 
	List<Student> getStudentsByCity(String city) throws StudentNotFoundException;
	List<Student> getStudentsByDept(String dept) throws StudentNotFoundException;


}
