#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <vector>
#include <string>
#include "book.h"

class Member {
private:
    std::string name;
    int age;
    std::string contact;
    std::string email;
    float debt;
    std::vector<Book> books_possessed;

public:

    /**
     * @brief parametrized constructor for the member class
     * 
     * @param name This is the name of the member
     * @param age This is the age of the member
     * @param contact This is the contact of the member
     * @param email This is the email of the member
     */
    Member(const std::string& name, int age, const std::string& contact, const std::string& email);

    /**
     * @brief This shows all the books borrowed by the member
     * 
     * @return Vector of books borrowed by member
     */
    std::vector<Book> showBooks() const;

    /**
     * @brief This is to borrow a book
     * 
     * @param book This is the book to be borrowed
     * @return true if possible else false
     */
    bool addBorrowedBook(const Book& book);

    /**
     * @brief This is used to return a borrowed book
     * 
     * @param book this is the book that is going to be returned
     * @return true if successful else false
     */
    bool removeBorrowedBook(const Book& book);

    /**
     * @brief Adds debt to a member
     * 
     * @param amount This is the amount of debt to be added
     */
    void addDebt(float amount);

    /**
     * @brief Pays debt of a member
     * 
     * @param amount This is the amount the member is paying
     */
    void payDebt(float amount);

    std::string getName() const;
};

#endif
