#include "library.h"
#include <iostream>
#include <vector>
#include <string>

int main(){
    Library library = Library("Gbesh");
    while (true){
        std::cout <<("This is the menu. Choose the operation you want to perform") << std::endl;
        std::cout <<("0. Close the application") << std::endl;
        std::cout <<("1. Add a new book to the library") << std::endl;
        std::cout <<("2. Add a new member to the library") << std::endl;
        std::cout <<("3. Show all the books the library possesses") << std::endl;
        std::cout <<("4. Show the members of the library") << std::endl;
        std::cout <<("5. Borrow book") << std::endl;
        std::cout <<("6. Return book") << std::endl;

        int choice;
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 0) return 0;

        else if (choice == 1){
            std::cout << "Enter the name of the book: ";
            std::string name;
            std::getline(std::cin, name);
            std::cout <<("Enter the ISBN of the book: ");
            int ISBN;
            std::cin >> ISBN;
            std::cin.ignore();
            std::cout <<("Enter the author of the book: ");
            std::string author;
            std::getline(std::cin, author);
            std::cout <<("Enter the genre of the book: ");
            std::string genre;
            std::getline(std::cin, genre);
            std::cout << ("How many copies of the book are you adding: ");
            int count;
            std::cin >> count;
            std::cin.ignore();

            library.addBooks(name, ISBN, author, genre, count);
        }

        else if (choice == 2){
            std::cout << "Enter the name of the member: ";
            std::string name;
            std::getline(std::cin, name);
            std::cout <<("Enter the age of the member: ");
            int age;
            std::cin >> age;
            std::cin.ignore();
            std::cout <<("Enter the contact of the member: ");
            std::string contact;
            std::getline(std::cin, contact);
            std::cout <<("Enter the email of the member: ");
            std::string email;
            std::getline(std::cin, email);
            library.addMember(name, age, contact, email);
        }
        
        else if (choice == 3)
            library.viewBooks();

        else if (choice == 4){
            if (library.displayMembers()){
                std::cout << ("Do you want to get show a members borrowed books?") << std::endl;
                std::cout << ("If yes, write the person's index else write 0") << std::endl;
                int another;
                std::cin >> another;
                std::cin.ignore();

                if (another != 0){
                    std::vector<Member> members = library.getMembers();
                    Member member = members.at(another-1);
                    member.showBooks();
                }
            }
            else std::cout << ("There are no members in the library!") << std::endl;
        }
        else if (choice == 5){
            if (library.displayMembers()){
                std::cout << "Write the index of the member who is going to borrow the book: ";
                int another;
                std::cin >> another;
                std::cin.ignore();


                if (another != 0){
                    std::vector<Member> members = library.getMembers();
                    Member member = members.at(another-1);
                    int selection;
                    std::cin >> selection;
                    std::cin.ignore();

                    std::vector<Book> books = library.viewBooks();
                    Book book = books.at(selection-1);
                    library.giveBook(member, book);
                }
                else {
                    std::cout << ("There is no member with that index in the library");
                }
            }
            else std::cout << ("There are no members in the library!");
        
        }
        else if (choice == 6){
            if (library.displayMembers()) {
                std::cout << ("Write the index of the member who is going to return the book.") << std::endl;
                int another;
                std::cin >> another;
                std::cin.ignore();
                
                if (another != 0) {
                    std::vector<Member> members = library.getMembers();
                    Member member = members.at(another-1);
                    std::vector<Book> books = member.showBooks();
                    if (!books.empty()) {
                        int selection;
                        std::cin >> selection;
                        std::cin.ignore();
                        Book book = books.at(selection - 1);
                        library.returnBook(member, book);
                    }
                    else{
                        std::cout << (member.getName() + " hasn't borrowed any book!") << std::endl;
                    }
                } else {
                    std::cout << ("There is no member with that index in the library") << std::endl;
                }
            }
        }
    }
}