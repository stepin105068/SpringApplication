package com.studentapp.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


import com.studentapp.dao.StudentRepository;
import com.studentapp.exception.StudentNotFoundException;
import com.studentapp.model.Address;
import com.studentapp.model.Student;

@Service
public class StudentServiceImpl implements StudentService {
	
	@Autowired
	StudentRepository studentRepository;

	@Override
	public Student addStudent(Student student) {
		Student newStudent = studentRepository.save(student);
		return newStudent;
	}

	@Override
	public Student getStudentById(int studentId) throws StudentNotFoundException {
		// TODO Auto-generated method stub
		return studentRepository.findById(studentId)
				.orElseThrow(()-> new StudentNotFoundException("Id not available"));
	}

	@Override
	public boolean deleteStudent(int studentId) throws StudentNotFoundException {
		studentRepository.deleteById(studentId);
		return true;
	}

	@Override
	public List<Student> getStudentsByCity(String city) throws StudentNotFoundException {
		// TODO Auto-generated method stub
		return studentRepository.findByAddressCity(city);
	}

	@Override
	public List<Student> getStudentsByDept(String dept)throws StudentNotFoundException {
		// TODO Auto-generated method stub
		return studentRepository.findByDept(dept);
	}

	@Override
	public List<Student> getAllStudents() {
		// TODO Auto-generated method stub
		return studentRepository.findAll();
	}

	


}
