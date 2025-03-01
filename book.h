#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    std::string name;
    int ISBN;
    std::string author;
    std::string genre;

public:

    /**
     * @brief The default constructor of a book class setting all values to ""
    */
    Book();

    
    /**
     * @brief the parameterized constructor of the book class
     * 
     * @param name This is the name of the book
     * @param ISBN This is the ISBN of the book
     * @param author This is the author of the book
     * @param genre This is the genre of the book
    */
    Book(const std::string& name, int ISBN, const std::string& author, const std::string& genre);

    void setName(const std::string& name);
    void setISBN(const int ISBN);
    void setAuthor(const std::string& author);
    void setGenre(const std::string& genre);

    std::string getName() const;
    int getISBN() const;
    std::string getAuthor() const;
    std::string getGenre() const;

    bool operator==(const Book& other) const;
    bool operator<(const Book& other) const;
};

#endif
