#include <iostream>
#include <fstream>
#include "Exception.hpp"
#include "OutOfRangeException.hpp"
#include "FileNotOpenException.hpp"

void ReadFile(const std::string& fileName, double x[],
              double y[])
{
    std::ifstream read_file(fileName.c_str());
    if (read_file.is_open() == false)
    {
        throw (FileNotOpenException("File can't be opened"));
    }
    for (int i=0; i<6; i++)
    {
        read_file >> x[i] >> y[i];
    }
    read_file.close();
    
    std::cout << fileName << " read successfully\n";
}

int main(int argc, char* argv[])
{
    double x[6], y[6];
    try
    {
        ReadFile("Output.dat", x, y);
    }
    catch (Exception& error)
    {
        error.PrintDebug();
        if(error.getType() == "FILENOTOPEN")
        {
            std::cout << "Couldn't open Output.dat\n";
            std::cout << "Give alternative location\n";
            std::string file_name;
            std::cin >>file_name;
            try
            {
                ReadFile(file_name, x, y);
            }
            catch (Exception& error)
            {
                if(error.getType() == "OUTOFRANGE")
                {
                    std::cout << "Tried to read an invalid value\n";
                }
                error.PrintDebug();
            }
        }
    }
}
