#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   myphone;
    
    Contact a("Mike", "Le Blanc", "Mimii", "0123456789", "Doesnt like white");
    Contact b("Allibbabbabba", "Les 40 voleurs", "Aladin", "09 87 65 43 21", "Likes Money");
    Contact c("Please", "add", "Me", "07 69 41 56 19", "I lied...");
    myphone.ft_add_contact(a);
    myphone.ft_add_contact(b);
    myphone.ft_add_contact(c);

    std::string input;
    while (input != "EXIT" && input != "exit")
    {
        std::cout << C_035 << "Please enter your choice:" << RESET << std::endl;
        std::cout << C_044 << "\tADD, SEARCH, DELETE, EXIT." << RESET << std::endl;
        
        if (!std::getline(std::cin, input))
            return 0;
        std::cout << CLEAR << std::endl;
        if ((input == "SEARCH" || input == "search") && !myphone.ft_search_contact())
            return 0;
        else if ((input == "ADD" || input == "add") && !myphone.ft_add_contact())
            return 0;
        else if (input == "DELETE" || input == "delete")
            myphone.ft_empty();
    }
    return 0;
}