#include <iostream>
#include <string>

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
