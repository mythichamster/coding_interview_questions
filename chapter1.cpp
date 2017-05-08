#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <algorithm>

bool problem1_1allUniqueCharactersHashMap(const std::string& a_str)
{
    std::map<char, bool> count;
    for(char c : a_str)
    {
        if (count[c]) { return false; }
        count[c] = true;
    }
    
    return true;
}

bool problem1_1_allUniqueCharactersSort(std::string a_str)
{
    std::sort(a_str.begin(), a_str.end());

    for (unsigned int i = 0; i < a_str.length() - 1; ++i)
    {
        if (a_str[i] == a_str[i + 1]) { return false; }    
    }
    
    return true;
}

void problem1_1()
{
    // Hashmap version
    std::cout << allUniqueCharactersHashMap("heldo") << std::endl;
    std::cout << allUniqueCharactersHashMap("hello world") << std::endl;
    // Sort version
    std::cout << allUniqueCharactersSort("heldo") << std::endl;
    std::cout << allUniqueCharactersSort("hello world") << std::endl;
}

int main()
{

}
