#include <iostream>
#include <string>
/* Guide to Scientific Computing in C++
 * Chapter 1 Exercise 1.5
 * Write code that invites the user to input seperately strings that 
 * store their given name and their family name.  Print the user's full 
 * name to screen */

int main()
{
    std::string forename;
    std::string surname;
    
    std::cout << "Please enter your forename: \n"; 
    std::getline(std::cin, forename);
    std::cout << "Now enter your surname: \n";
    std::getline(std::cin, surname);
    
    std::cout << "Your full name is " << forename << " " << surname << "\n";
    
    return 0;
}
