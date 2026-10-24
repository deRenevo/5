
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

bool FindString(std::string string, std::string stringToFind)
{
    std::string TempString;
    
    for (char& i : string)
    {
        if (i >= 'A' && i <= 'Z')
        {
            i = i + 32;
        }
    }
    
    for (char& i : stringToFind)
    {
        if (i >= 'A' && i <= 'Z')
        {
            i = i + 32;
        }
    }
    
    std::stringstream StringStream(string);
    
    while (std::getline(StringStream, TempString, ' '))
    {
        while (TempString.back() == '.'|| TempString.back() == ',' || TempString.back() == '!' || TempString.back() == '?' || TempString.back() == ';')
        {
            TempString.erase(TempString.size() - 1);
        }
        
        if (TempString == stringToFind)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    std::string String = std::string();
    std::getline(std::cin, String, '\n');
    
    if (String.empty() || std::all_of(String.begin(), String.end(), isspace))
    {
        std::cout << "Error String is empty" << std::endl;
        return 0;
    }
    
    std::cout << String  << std::endl << std::endl;
    
    bool bIsNewWord = true;
    
    for (char& i : String)
    {
        if (i == ' ')
        {
            bIsNewWord = true;
            continue;
        }
        
        if (bIsNewWord)
        {
            if (i >= 'a' && i <= 'z')
            {
                i -= 32;
            }
            
            bIsNewWord = false;
        }
        else
        {
            if (i >= 'A' && i <= 'Z')
            {
                i += 32;
            }
        }
    }
    
    if (String.back() != '.')
    {
        String.push_back('.');
    }
    
    std::cout << String  << std::endl << std::endl;
    std::cout << FindString(std::string("eRRor sTring IS, eMpty"), std::string("is"));
    
    return 0;
}
