#include <iostream>
#include <string>
#include <memory>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/udp.hpp>
//#include "chatclient.hpp"
//#include <thread>

void showStudentMenu() {
	int in;
	std::cout << "Please choose from the menu below:" << std::endl;
	std::cout << "1. List of all students" << std::endl;
	std::cout << "2. Get student detail" << std::endl;
	std::cout << "3. Edit student" << std::endl;
	std::cout << "4. Delete student" << std::endl;
	std::cout << "5. Add new student" << std::endl;
	std::cout << "6. Press enter to return" << std::endl;

	std::cin >> in;

	switch (in) {
	case 1:
//ping server
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;

	}

}

void showAllStudents() {
	std::cout << "Details of all students:" << std::endl;


}

void showSingleStudent() {

}

void editStudent() {

}

int main(int argc, char *argv) {
	int role;
	std::cout << "Please choose you role:"<<std::endl<<"1. Press 1 for Admin"<<std::endl<<"2. Press 2 for student";

	std::cin >> role;

	switch (role) {
	case 1:
		showStudentMenu();
		break;

	case 2:
	//	showStudentMenu();
		break;
	
	}

	return 0;

}

