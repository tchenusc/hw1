#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr dat;
    std::vector<std::string> content = {"sup", "er", "cal", "i", "frag", "il", "istic", "expi", "alo", "doc", "ious"};
    for (int i = 0; i <= 10; i++)
    {
        dat.push_back(content[i]);
    }
    dat.pop_back();
    cout << dat.get(9) << endl;
    
    
    return 0;
    string s1("1");
    string s2("2");
    string s3("3");
    string s4("4");
    string s5("5");
    string s6("6");
    string s7("7");
    string s8("8");
    string s9("9");
    string s10("10");
    string s11("11");
    string s12("12");
    dat.push_back(s1);
    dat.push_back(s2);
    dat.push_back(s3);
    dat.push_back(s4);
    dat.push_back(s5);
    dat.push_back(s6);
    dat.push_back(s7);
    dat.push_back(s8);
    dat.push_back(s9);
    dat.push_back(s10);
    dat.push_back(s11);
    dat.push_back(s12);
    
    for (int i = 0; i < 12; i++)
    {
        cout << dat.front() << " Popped" << endl;
        dat.pop_front();
    }
    
    cout << endl;
    cout << "size: " << dat.size() << endl;
    //cout << dat.get(0) << endl;
    
    //cout << dat.get(8) << " " << dat.get(9) << " " << dat.get(11) << endl;
}
