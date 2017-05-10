#include <iostream>
#include <string>
#include <memory>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/udp.hpp>
#include "Admin.h"
#include "AdminMap.h"
#include "Student.h"
#include "StudentMap.h"

class Server{
private:
	Admin m_admin;
	AdminMap m_adminMap;
	Student m_student;
	StudentMap m_studentMap;


	Server(Admin admin, AdminMap adminMap, Student student, StudentMap studentMap) :
		m_admin(admin),
		m_adminMap(adminMap),
		m_student(student),
		m_studentMap(studentMap)
	{

	}


void getAllStudents() {
	m_studentMap.getAllStudentDetails();
}

void parseMessage() {
	// message will have a roleId and task id
	int roleId;
	int taskId;

	if (roleId == 1) {
		switch (taskId) {
		case 1:
			getAllStudents();
			break;
		}
	}
	else
	{
		switch (taskId) {
		case 1:
			break;
		}
	}
}
};