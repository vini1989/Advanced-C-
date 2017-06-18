#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <vector>
#include "Book.h"

class BookMap {
private:
	int m_bookId;
	//std::string  m_bookTitle, m_bookAuthor, m_bookISBN, m_bookType, m_bookAvailability;
	std::map<int, std::vector<std::string>> bookMap;
	int m_key;
	std::string  m_bookTitle, m_bookAuthor, m_bookISBN, m_bookType, m_bookAvailability;


public:
	BookMap():
		m_bookId()
		, m_bookTitle()
		, m_bookAuthor()
		, m_bookISBN()
		, m_bookType()
		, m_bookAvailability()
	{
		std::cout << "Book Default constructor called" << std::endl;
	};
	BookMap(BookMap &bookMap) {
		m_bookId = bookMap.m_bookId;
		m_bookTitle = bookMap.m_bookTitle;
		m_bookAuthor = bookMap.m_bookAuthor;
		m_bookISBN = bookMap.m_bookISBN;
		m_bookType = bookMap.m_bookType;
		m_bookAvailability = bookMap.m_bookAvailability;
	}
	BookMap(int bookId, std::string bookTitle, std::string bookAuthor, std::string bookISBN, std::string bookType, std::string bookAvailability) :
		m_bookId(bookId), m_bookTitle(bookTitle), m_bookAuthor(bookAuthor), m_bookISBN(bookISBN), m_bookType(bookType), m_bookAvailability(bookAvailability)
	{

	}
	~BookMap()
	{
		std::cout << "BookMap destroyed" << std::endl;
	}

	std::string insertBook(std::shared_ptr<Book> &book) {

		std::map<int, std::vector<std::string>>::iterator itr = bookMap.find(book->bookId());
		if (itr == bookMap.end()) {
			bookMap[book->bookId()].push_back(book->getbookTitle());
			bookMap[book->bookId()].push_back(book->getbookAuthor());
			bookMap[book->bookId()].push_back(book->getbookISBN());
			bookMap[book->bookId()].push_back(book->getbookType());
			bookMap[book->bookId()].push_back(book->getbookAvailability());
			return "Book Added Successfully";
		}
		else
		{
			return "Book already exists";
		}
	};

	bool deleteBook(int bookId) {
		bool isDelete;
		std::map<int, std::vector<std::string>>::iterator itr = bookMap.find(bookId);
		if (itr != bookMap.end()) {
			bookMap.erase(itr);
			return isDelete = true;
		}
		else isDelete = false;
	};

	std::map<int, std::vector<std::string>> getAllBookDetails() {
		return bookMap;
	};

	std::vector<std::string> getSingleBookDetails(int bookId) {
		try {
			std::vector<std::string> vec;
			std::map<int, std::vector<std::string>>::iterator it = bookMap.find(bookId);
			if (it != bookMap.end())
				return bookMap.at(bookId);
			else
				vec.push_back("Book Id not found");
		}
		catch (std::exception e) {
			//return book not found statement from here.
			std::cout << "Enter correct book Id. Requested book Id not found" << std::endl;
		}

	};

	std::vector<std::string> editBook(std::shared_ptr<Book> &book) {
		std::vector<std::string> vector;

		std::map<int, std::vector<std::string>>::iterator itr = bookMap.find(book->bookId());
		if (itr != bookMap.end()) {
			vector.push_back(book->getbookTitle());
			vector.push_back(book->getbookAuthor());
			vector.push_back(book->getbookISBN());
			vector.push_back(book->getbookType());
			vector.push_back(book->getbookAvailability());
			itr->second = vector;
			return vector;
		}
		else {
			vector.push_back("No book found with requested id. Please enter correct id");
			return vector;
		}
	};

	std::string BookMap::markBookBorrowed(int bookId, std::string bookAvailability) {
		try {
			std::vector<std::string> vec;
			std::map<int, std::vector<std::string>>::iterator it = bookMap.find(bookId);
			if (it != bookMap.end()) {
				it->second[4] = bookAvailability;
				return "Book borrowed succesfully";
			}
			else {
				return "Book ID not found";
			}
		}
		catch (std::exception e) {
			std::cout << "unable to borrow book";
		}
	}
	;
};