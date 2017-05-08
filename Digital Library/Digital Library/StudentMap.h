#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

class StudentMap {
private:
	std::map<int, std::vector<std::string> > studentMap;
	int m_key;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_department;


	/*
public:
	
	StudentMap(int key, std::string firstName, std::string lastName, std::string department) :
		m_key(key), m_firstName(firstName), m_lastName(lastName), m_department(department) {
		std::cout << "Student is created."<<std::endl;
	}


	StudentMap() :
		m_key(), m_firstName(), m_lastName(), m_department() {
		std::cout << "Student map is created." << std::endl;
	}
	*/

public:

	 void insertStudent(int key, std::string firstName, std::string lastName, std::string department) {
		 std::map<int, std::vector<std::string>>::iterator itr = studentMap.find(key);
		 if(itr!=studentMap.end){
		 studentMap[key].push_back(firstName);
		 studentMap[key].push_back(lastName);
		 studentMap[key].push_back(department);
		 }
		 else
		 {
			 std::cout << "Student already exists" << std::endl;
		 }
	}

	 void showAllStudents() {
		 std::map<int, std::vector<std::string>>::iterator itr;
		 std::cout << "List of all students" << std::endl;
		 for (itr = studentMap.begin();itr != studentMap.end;itr++) {
			 std::cout << itr->first << ": ";
			 for (std::vector<std::string>::iterator it = itr->second.begin;it != itr->second.end();it++) {
				 std::cout << *it << ",";
			 }
		 }
	 }

	 void showSingleStudent(int studentId) {
		 std::map<int, std::vector<std::string>>::iterator itr= studentMap.find(studentId);
		 std::cout << "Student Details are:" << std::endl;
		 if (itr != studentMap.end) {
			 std::cout << itr->first << ": ";
			 for (std::vector<std::string>::iterator it = itr->second.begin;it != itr->second.end();it++) {
				 std::cout << *it << ",";
			 }
		 }
		 }
	 
	 void deleteStudent(int studentId) {
		 std::map<int, std::vector<std::string>>::iterator itr = studentMap.find(studentId);
		 if(itr!=studentMap.end)
		 studentMap.erase(itr);
	 }

    std::map<int, std::vector<std::string>> getAllStudentDetails() {
		 return studentMap;
	 }

	 std::vector<std::string> getSingleStudentDetails(int studentId) {
		 std::map<int, std::vector<std::string>>::iterator it = studentMap.find(studentId);
		 return it->second;
	 }

	 void editStudent(int studentId, std::string firstName, std::string lastName, std::string department) {
		 std::map<int, std::vector<std::string>>::iterator itr = studentMap.find(studentId);
		 itr->second.erase;
		 studentMap[studentId].push_back(firstName);
		 studentMap[studentId].push_back(lastName);
		 studentMap[studentId].push_back(department);
	 }

};