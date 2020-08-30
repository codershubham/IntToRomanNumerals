/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
std::string FindRomanLitForInt(std::map<int,std::string> f_map, int number)
{
    auto it = f_map.lower_bound(number);
    auto previt = it;
    previt--;
    int value = 0;
    string l_strRomanLit;
    if(it->first == f_map.size())
    {
        while(value < number)
        {
            value += previt->first;
            l_strRomanLit += previt->second;
        }
        return l_strRomanLit;
    }

    if(it->first == number)
        return it->second;
    
    auto tempprev = previt;
    while(true)
    {
        if(it->first - tempprev->first == number)
            return tempprev->second + it->second;
        
        if(tempprev == f_map.begin())
            break;
            
        tempprev--;
    }
    
    
    l_strRomanLit.clear();
    while (true)
    {
        value += previt->first;
        if(value > number)
        {
            value -= previt->first;
            previt--;
            continue;
        }
        l_strRomanLit += previt->second;
        
        if(value == number)
            break;
    }
    return l_strRomanLit;
    
}
std::string IntToRoman(int A) {
    std::vector<int> numbers;
    std::map<int,std::string> mapRomanInteger;
    mapRomanInteger.insert({1, "I"});
    mapRomanInteger.insert({5, "V"});
    mapRomanInteger.insert({10, "X"});
    mapRomanInteger.insert({50, "L"});
    mapRomanInteger.insert({100, "C"});
    mapRomanInteger.insert({500, "D"});
    mapRomanInteger.insert({1000, "M"});
    
    int decimalPlace = 1;
    while(A)
    {
        int digit = A%10;
        digit *= decimalPlace;
        numbers.push_back(digit);
        decimalPlace *= 10;
        A /= 10;
    }
    std::string l_strRomanNumber;
    for(int i = numbers.size() - 1; i >= 0 ;i--)
    {
        if(numbers.at(i) == 0)
            continue;
            
        l_strRomanNumber += FindRomanLitForInt(mapRomanInteger,numbers.at(i));
    }
    
    return l_strRomanNumber;
}

int main()
{
    cout << IntToRoman(2014) << endl;

    return 0;
}
