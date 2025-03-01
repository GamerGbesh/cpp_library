#include "book.h"


Book::Book() : name(""), ISBN(0), author(""), genre("") {}


Book::Book(const std::string& name, int ISBN, const std::string& author, const std::string& genre)
    : name(name), ISBN(ISBN), author(author), genre(genre) {}

void Book::setName(const std::string& name) { this->name = name; }
void Book::setISBN(const int ISBN) { this->ISBN = ISBN; }
void Book::setAuthor(const std::string& author) { this->author = author; }
void Book::setGenre(const std::string& genre) { this->genre = genre; }

std::string Book::getName() const { return name; }
int Book::getISBN() const { return ISBN; }
std::string Book::getAuthor() const { return author; }
std::string Book::getGenre() const { return genre; }

// Overload == operator for comparisons
bool Book::operator==(const Book& other) const {
    return ISBN == other.ISBN;  // Compare books based on ISBN
}

// Overload < operator for comparisons
bool Book::operator<(const Book& other) const {
    return ISBN < other.ISBN;  //  Compare books based on ISBN
}
