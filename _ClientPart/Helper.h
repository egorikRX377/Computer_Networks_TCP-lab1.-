#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;


const vector<char> someCorrectMathOperations = { '+', '-', '*', '/' };

template <class T>
T correctNumberInput(const string& message)
{
    T number = 0;
    while (true)
    {
        cout << message;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cerr << "Error: incorrect number input!" << endl;
        }
        else
        {
            break;
        }
    }
    return number;
}

char inputCorrectMathOperation();
