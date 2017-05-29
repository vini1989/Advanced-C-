#include <iostream>
#include <string>
#include <memory>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/udp.hpp>
#include "UdpClient.h"
	
	UdpClient::UdpClient(std::string address, boost::asio::io_service &io_service):
	m_roleId(),
		m_taskId(),
		m_address(address),
		m_receiver_endpoint(
			boost::asio::ip::address_v4::from_string(address),
			2000),
	m_io_service(),
		m_sender_endpoint(),
		m_socket(io_service),
		recv_buf()
	{
		std::cout << "Welcome to the application" << std::endl;
		connectToServer();
		
	}


	void UdpClient::connectToServer() {

		std::string  send_buf = "R";

		m_socket.open(boost::asio::ip::udp::v4());

		m_socket.send_to(boost::asio::buffer(send_buf), m_receiver_endpoint);
		roleMenu();
	}

	void UdpClient::roleMenu() {

		std::cout << "Please choose you role:" << std::endl << "1. Press 1 for Admin" << std::endl << "2. Press 2 for student"<<std::endl;
		std::cin >> m_roleId;

		switch (m_roleId) {
		case 1:
			showStudentMenu();
			break;

		case 2:
			//	showStudentMenu();
			break;

		}
	}


	void UdpClient::showStudentMenu() {
		std::cout << "Please choose from the menu below:" << std::endl;
		std::cout << "1. List of all students" << std::endl;
		std::cout << "2. Get student detail" << std::endl;
		std::cout << "3. Edit student" << std::endl;
		std::cout << "4. Delete student" << std::endl;
		std::cout << "5. Add new student" << std::endl;
		std::cout << "6. Show list of books" << std::endl;
		std::cout << "7. Add new book" << std::endl;
		std::cout << "8. Modify book" << std::endl;
		std::cout << "9. Mark book as borrowed" << std::endl;
		std::cout << "10. Mark book as return" << std::endl;
		std::cout << "Press esc to return" << std::endl;

		std::cin >> m_taskId;

		switch (m_taskId) {
		case 1:
	getAllStudentDetail();
			break;
		case 2:
			getStudent();
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			addStudent();
			break;

		case 6:
			break;

		}

	}

	void UdpClient::addStudent() {
		std::string firstName,lastName,studentId,department;
		std::string  send_buf = "E";
		send_buf.append(","+std::to_string(m_roleId) + "," +std::to_string(m_taskId));
		//send_buf = ;

		std::cout << "Enter student id" << std::endl;
		std::cin >> studentId;

		std::cout << "Enter student firstName" << std::endl;
		std::cin >> firstName;

		std::cout << "Enter student lastName" << std::endl;
		std::cin >> lastName;

		std::cout << "Enter student department" << std::endl;
		std::cin >> department;

		send_buf = send_buf + ","+studentId+"," + firstName + "," + lastName + "," + department;


		//m_socket.open(boost::asio::ip::udp::v4());

		m_socket.send_to(boost::asio::buffer(send_buf), m_receiver_endpoint);

		size_t const len = m_socket.receive_from(
			boost::asio::buffer(recv_buf), m_sender_endpoint);

		std::string const received_message(recv_buf.data(), len);
		std::cout << "received from server: \"" << received_message << "\"" << std::endl;

	}


	void UdpClient::getStudent() {
		int studentId;
		
		//send_buf = ;

		std::cout << "Enter student id" << std::endl;
		std::cin >> studentId;

		std::string  send_buf = "E";
		send_buf.append("," + std::to_string(m_roleId) + "," + std::to_string(m_taskId)+ "," + std::to_string(studentId));
		m_socket.send_to(boost::asio::buffer(send_buf), m_receiver_endpoint);

		size_t const len = m_socket.receive_from(
			boost::asio::buffer(recv_buf), m_sender_endpoint);

		std::string const received_message(recv_buf.data(), len);
		std::cout << "received from server: \"" << received_message << "\"" << std::endl;

	}


	void UdpClient::getAllStudentDetail(){
		std::string const send_buf = std::to_string(m_roleId)+","+std::to_string(m_taskId);
		
		m_socket.send_to(boost::asio::buffer(send_buf), m_receiver_endpoint);

		size_t const len = m_socket.receive_from(
			boost::asio::buffer(recv_buf), m_sender_endpoint);

		std::string const received_message(recv_buf.data(), len);
		std::cout << "received from server: \"" << received_message << "\"" << std::endl;

	}
	