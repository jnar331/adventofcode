#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream myfile("InputDay1");

    std::vector<int> allNumbers;
    int currentNumber = 0;
    int previousNumber = 0;
    int increaseCounter = 0;
    int lineCount = 0;

    while(myfile >> currentNumber){
        allNumbers.emplace_back(currentNumber);
        if(lineCount > 0){
            if(currentNumber > previousNumber){
                increaseCounter++;
            }
        }

        lineCount++;
        previousNumber = currentNumber;

    }

    int currentSum = 0;
    int previousSum = 0;
    int SumIncrease = 0;
    for (int i = 0; i<allNumbers.size(); i++){

        if(i == allNumbers.size() - 2){
            break;
        }
        currentSum = allNumbers[i] + allNumbers[i+1] + allNumbers[i+2];
        if(i > 0){
            if(currentSum > previousSum){
                SumIncrease++;
            }
        }
        previousSum = currentSum;
    }

    cout << "All numbers counted: " << allNumbers.size() << endl;
    cout << "Increase Sum Count: " << SumIncrease << endl;
    cout << "Increase Count: " << increaseCounter << endl;
    return 0;
}
