#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "book.h"
#include "member.h"

class Library {
private:
    std::string name;
    std::map<Book, int> books;  // Map to store books and their available counts
    std::vector<Member> members;

public:
    /// @brief This is the parameterized constructor of the library
    /// @param name This is the name of the library
    Library(const std::string& name);

    // Book-related methods


    /// @brief This function is to add books to the library
    /// @param name This is the name of the book
    /// @param ISBN This is the ISBN of the book
    /// @param author This is the author of the book
    /// @param genre This is the genre of the book
    /// @param count This is the number of copies of the book to be added
    void addBooks(const std::string& name, int ISBN, const std::string& author, const std::string& genre, int count);

    /// @brief This is to view all the books in the library
    /// @return Returns a vector of all the books
    std::vector<Book> viewBooks();


    /// @brief This checks if a book is present in the library
    /// @param name Name of book to check
    /// @param ISBN ISBN of book to check
    /// @param author Author of book to check
    /// @param genre Genre of book to check
    /// @return A pointer to the book if found else a null pointer
    const Book* checkBook(std::string name, int ISBN, std::string author, std::string genre);

    
    /// @brief This gives a book out to a member to borrow
    /// @param member This is the person borrowing
    /// @param book This is the book to be borrowed
    /// @return true if successful else false
    bool giveBook(Member& member, const Book& book);

    
    /// @brief This returns a borrowed book from a member
    /// @param member The member that is returning the book
    /// @param book The book that is being returned
    /// @return true if successful else false
    bool returnBook(Member& member, const Book& book);

    // Member-related methods


    /// @brief Adding a new member to the library
    /// @param name The name of the member to be added
    /// @param age The age of the member to be added
    /// @param contact The contact of the member to be added
    /// @param email The email of the member to be added
    void addMember(const std::string& name, int age, const std::string& contact, const std::string& email);

    
    /// @brief This shows all members of the library
    /// @return true if members exist else false
    bool displayMembers() const;


    /// @brief This gets all members that are present in the library
    /// @return Members of the library
    std::vector<Member>& getMembers();
};

#endif
