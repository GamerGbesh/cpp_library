#include "member.h"
#include <algorithm>

Member::Member(const std::string& name, int age, const std::string& contact, const std::string& email)
    : name(name), age(age), contact(contact), email(email), debt(0) {}

std::vector<Book> Member::showBooks() const {
    std::cout << "Books borrowed by " << name << ":" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    for (size_t i = 0; i < books_possessed.size(); i++) {
        std::cout << i + 1 << ". " << books_possessed[i].getName() << std::endl;
    }

    std::cout << std::string(50, '-') << std::endl;
    return books_possessed;
}

bool Member::addBorrowedBook(const Book& book) {
    if (books_possessed.size() >= 2) {
        std::cout << name << " has already borrowed the maximum number of books!" << std::endl;
        return false;
    }

    auto it = std::find(books_possessed.begin(), books_possessed.end(), book);
    if (it == books_possessed.end()) {
        books_possessed.push_back(book);
        return true;
    } else {
        std::cout << name << " has already borrowed this book!" << std::endl;
        return false;
    }
}

bool Member::removeBorrowedBook(const Book& book) {
    if (books_possessed.empty()) {
        std::cout << name << " has not borrowed any books!" << std::endl;
        return false;
    }

    auto it = std::find(books_possessed.begin(), books_possessed.end(), book);
    if (it != books_possessed.end()) {
        books_possessed.erase(it);
        return true;
    } else {
        std::cout << book.getName() << " has not been borrowed by " << name << std::endl;
        return false;
    }
}

void Member::addDebt(float amount) {
    if (amount < 0) {
        std::cout << "The amount to be added cannot be negative!" << std::endl;
    } else {
        debt += amount;
    }
}

void Member::payDebt(float amount) {
    if (amount < 0) {
        std::cout << "The amount to be paid cannot be negative!" << std::endl;
    } else if (amount > debt) {
        std::cout << "The amount to be paid cannot be more than the debt owed!\n";
        std::cout << "Total debt owed: " << debt << " | Amount being paid: " << amount << std::endl;
    } else {
        debt -= amount;
    }
}

std::string Member::getName() const {
    return name;
}
