#include "library.h"
#include <algorithm>

// Constructor
Library::Library(const std::string& name) : name(name) {}

// Add books to the library
void Library::addBooks(const std::string& name, int ISBN, const std::string& author, const std::string& genre, int count) {
    const Book* book = checkBook(name, ISBN, author, genre);

    if (book) {
        books[*book] += count;
        std::cout << count << " copies of " << name << " added to the library.\n";
    } else {
        Book book = Book(name, ISBN, author, genre);
        books[book] = count;
        std::cout << "New book added: " << name << " with " << count << " copies.\n";
    }
}

const Book* Library::checkBook(std::string name, int ISBN, std::string author, std::string genre){
    for (auto& pair: books){
        if (pair.first.getName() == name && pair.first.getAuthor() == author && pair.first.getISBN() == ISBN){
            return &(pair.first);
        }
    }
    return nullptr;
}

// View all books in the library
std::vector<Book> Library::viewBooks(){
    std::vector<Book> books_possessed;
    if (books.empty()) {
        std::cout << "No books available in the library.\n";
        return books_possessed;
    }

    std::cout << "Books available in the library:\n";
    std::cout << std::string(50, '-') << std::endl;

    int index = 1;
    for (const auto& pair : books) {
        std::cout << index++ << ". " << pair.first.getName() << " (" << pair.second << " copies available)\n";
        books_possessed.push_back(pair.first);
    }

    std::cout << std::string(50, '-') << std::endl;
    return books_possessed;
}

// Give a book to a member
bool Library::giveBook(Member& member, const Book& book) {
    auto it = books.find(book);
    if (it == books.end() || it->second <= 0) {
        std::cout << "Book not available for borrowing.\n";
        return false;
    }

    if (member.addBorrowedBook(book)) {
        books[book]--;
        std::cout << book.getName() << " borrowed successfully by " << member.getName() << ".\n";
        return true;
    }

    return false;
}

// Return a book from a member
bool Library::returnBook(Member& member, const Book& book) {
    if (member.removeBorrowedBook(book)) {
        books[book]++;
        std::cout << member.getName() << " returned " << book.getName() << ".\n";
        return true;
    }

    return false;
}

// Add a new member to the library
void Library::addMember(const std::string& name, int age, const std::string& contact, const std::string& email) {
    members.emplace_back(name, age, contact, email);
    std::cout << "New member added: " << name << "\n";
}

// Display all members in the library
bool Library::displayMembers() const {
    if (members.empty()) {
        std::cout << "No members in the library.\n";
        return false;
    }

    std::cout << "Library Members:\n";
    std::cout << std::string(50, '-') << std::endl;

    for (size_t i = 0; i < members.size(); i++) {
        std::cout << i + 1 << ". " << members[i].getName() << std::endl;
    }

    std::cout << std::string(50, '-') << std::endl;
    return true;
}

// Get reference to members
std::vector<Member>& Library::getMembers() {
    return members;
}
