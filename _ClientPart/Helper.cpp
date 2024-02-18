#include "Helper.h"

using namespace std;

char inputCorrectMathOperation()
{
    char operation;
    while (true)
    {
        cout << "Enter the math operation please: ";
        cin >> operation;

        auto it = find(someCorrectMathOperations.begin(), someCorrectMathOperations.end(), operation);
        if (it == someCorrectMathOperations.end())
        {
            cerr << "Error: incorrect math operation!" << endl;
        }
        else
        {
            break;
        }
    }

    return operation;
}