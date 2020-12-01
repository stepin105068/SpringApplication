package com.studentapp.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.studentapp.exception.StudentNotFoundException;
import com.studentapp.model.Address;
import com.studentapp.model.Student;
import com.studentapp.service.StudentService;


@RestController
@RequestMapping("/student-api")
public class StudentResponseController {
	
	@Autowired
	StudentService studentService;
	
	 @PostMapping("/students")
	    ResponseEntity<Student> addStudent(@RequestBody Student student) {
	        Student nstudent = studentService.addStudent(student);
	        return ResponseEntity.ok(nstudent);
	    }
	    @DeleteMapping("/students/delete-one/{studentId}")
	    ResponseEntity<Void> deleteStudent(@PathVariable("studentId")Integer studentId) throws StudentNotFoundException{
	        studentService.deleteStudent(studentId);
	        return ResponseEntity.status(HttpStatus.OK).build();
	    }
	    @GetMapping("/students/get-one/{studentId}")
	    ResponseEntity<Student> getStudentById(@PathVariable("studentId")Integer studentId) throws StudentNotFoundException{
	        Student nstudent = studentService.getStudentById(studentId);
	        HttpHeaders header = new HttpHeaders();
	        header.add("desc", "Getting student by Id");
	        header.add("title", "One Student");
	        return ResponseEntity.status(HttpStatus.OK)
	                .headers(header).body(nstudent);
	    }
	    
	    @GetMapping("/students")
	    ResponseEntity<List<Student>> getAllStudents(){
	        List<Student> studentList =  studentService.getAllStudents();
	        return ResponseEntity.ok(studentList);
	    }
	    @GetMapping("/students/city/{city}")
	    ResponseEntity<List<Student>> getStudentbyCity(@PathVariable("city")String city) throws StudentNotFoundException{
	        List<Student> studentList =   studentService.getStudentsByCity(city);
	        return ResponseEntity.ok(studentList);
	    }
	    @GetMapping("/students/department/{department}")
	    ResponseEntity<List<Student>> getStudentbycategory(@PathVariable("dept")String dept)throws StudentNotFoundException{
	        List<Student> studentList = studentService.getStudentsByDept(dept);    
	        return ResponseEntity.ok(studentList);
	    }
	    

}
