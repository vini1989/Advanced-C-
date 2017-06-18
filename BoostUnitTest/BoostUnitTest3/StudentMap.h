#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <vector>
#include "Student.h"

class StudentMap {
private:
	int m_studentId;
	std::map<int, std::vector<std::string>> studentMap;
	int m_key;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_department;


public:
	StudentMap() :
		m_studentId()
		, m_firstName()
		, m_lastName()
		, m_department()
	{
		std::cout << "Default constructor called" << std::endl;
	}

	StudentMap(StudentMap &studentM) {
		m_studentId = studentM.m_studentId;
		m_firstName = studentM.m_firstName;
		m_lastName = studentM.m_lastName;
		m_department = studentM.m_department;
	}

	StudentMap(int studentId, std::string firstName, std::string lastName, std::string department) :
		m_studentId(studentId), m_firstName(firstName), m_lastName(lastName), m_department(department)
	{

	}

	~StudentMap()
	{
		//std::cout << "StudentMap destroyed" << std::endl;
	}

	std::string insertStudent(std::shared_ptr<Student> &student);

	void showAllStudents();

	void showSingleStudent(int studentId);

	bool StudentMap::deleteStudent(int studentId) {
		bool isDelete;
		std::map<int, std::vector<std::string>>::iterator itr = studentMap.find(studentId);
		if (itr != studentMap.end()) {
			studentMap.erase(itr);
			return isDelete = true;
		}
		else isDelete = false;
	};

	std::map<int, std::vector<std::string>> getAllStudentDetails();
	std::vector<std::string> getSingleStudentDetails(int studentId);

	std::vector<std::string> editStudent(std::shared_ptr<Student> &student);

};