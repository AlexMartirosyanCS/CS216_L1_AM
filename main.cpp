// Alex Martirosyan
// Lab #1

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


void SortFunction(int divisibleFive[], int divisibleNine[], int leftoverNumbers[], int& count5, int& count9, int& countLeftover);
void BubbleSort(int arr[], int count);
double SumFunction(int arr[], int count);
double AverageFunction(int arr[], int count);
double MedianFunction(int arr[], int count);
void printArrayWithStats(const char *title, int arr[], int count);
void printArraySorted(const char *title, int arr[], int count);
void outputFileFunction(int divisibleFive[], int count5, int divisibleNine[], int count9, int leftoverNumbers[], int countLeftover);


int main() {
    int divisibleFive[100];
    int divisibleNine[100];
    int leftoverNumbers[100];
    int count5 = 0, count9 = 0, countLeftover = 0;
    SortFunction(divisibleFive, divisibleNine, leftoverNumbers, count5, count9, countLeftover);

int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Print arrays with statistics\n";
        cout << "2. Print arrays sorted in ascending order\n";
        cout << "3. Quit and write arrays and their stats into output file\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
            printArrayWithStats("Divisible by 5", divisibleFive, count5);
            printArrayWithStats("Divisible by 9", divisibleNine, count9);
            printArrayWithStats("Leftover Numbers", leftoverNumbers, countLeftover);
            break;
            case 2:
printArraySorted("Divisible by 5", divisibleFive, count5);
            printArraySorted("divisible by 9", divisibleNine, count9);
            printArraySorted("Leftover Numbers", leftoverNumbers, countLeftover);
            break;
            case 3:
outputFileFunction(divisibleFive, count5, divisibleNine, count9, leftoverNumbers, countLeftover);
                break;
        }
    }while (choice != 3);



    return 0;
};



//reads the file and sorts//
void SortFunction(int divisibleFive[], int divisibleNine[], int leftoverNumbers[], int& count5, int& count9, int& countLeftover){

    ifstream dataNumbers;
    dataNumbers.open("numbers.txt");

    if (!dataNumbers) {
        cout<<"Could not open the input file, Terminating program\n";
        exit (1);
    }
    int five=0,nine=0,leftover=0;
int placeholder;
    while (dataNumbers>>placeholder) {
        if (placeholder % 5 ==0) {
divisibleFive[five++] = placeholder;
        } else if(placeholder % 9==0) {
            divisibleNine[nine++] = placeholder;;
        }else {
            leftoverNumbers[leftover++] = placeholder;
        }
    }
    dataNumbers.close();

    count5 = five;
    count9 = nine;
    countLeftover = leftover;

    BubbleSort(divisibleFive, count5);
    BubbleSort(divisibleNine, count9);
    BubbleSort(leftoverNumbers, countLeftover);
}
//sorts numbers//
void BubbleSort(int arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
//calculates sum//
double SumFunction(int arr[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    return sum;
}
//calculates average//
double AverageFunction(int arr[], int count) {
    if (count == 0)
        return 0;
    return SumFunction(arr, count) / count;
}
//calculates median//
double MedianFunction(int arr[], int count) {
    if (count == 0)
        return 0;

    if (count % 2 != 0)
        return arr[count / 2];
    else
        return (arr[count / 2 - 1] + arr[count / 2]) / 2.0;
}
//prints the arrays with sum average and median//
void printArrayWithStats(const char *title, int arr[], int count) {
    cout << "\n" << title << ":\n";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nSum: " << SumFunction(arr, count);
    cout << "\nAverage: " << AverageFunction(arr, count);
    cout << "\nMedian: " << MedianFunction(arr, count) << "\n";
}
//prints sorted arrays//
void printArraySorted(const char *title, int arr[], int count) {
    cout << "\n" << title << ":\n";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
}
//handles case 3//
void outputFileFunction(int divisibleFive[], int count5, int divisibleNine[], int count9, int leftoverNumbers[], int countLeftover) {
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cout<<"Could not open the output file, Terminating program\n";
        return;
    }
    outputFile << "Divisible by 5:\n";
    for (int i = 0; i < count5; i++) {
        outputFile << divisibleFive[i] << " ";
    }
    outputFile << "\nSum: " << SumFunction(divisibleFive, count5);
    outputFile << "\nAverage: " << AverageFunction(divisibleFive, count5);
    outputFile << "\nMedian: " << MedianFunction(divisibleFive, count5) << "\n\n";

    outputFile << "Divisible by 9:\n";
    for (int i = 0; i < count9; i++) {
        outputFile << divisibleNine[i] << " ";
    }
    outputFile << "\nSum: " << SumFunction(divisibleNine, count9);
    outputFile << "\nAverage: " << AverageFunction(divisibleNine, count9);
    outputFile << "\nMedian: " << MedianFunction(divisibleNine, count9) << "\n\n";

    outputFile << "Leftover Numbers:\n";
    for (int i = 0; i < countLeftover; i++) {
        outputFile << leftoverNumbers[i] << " ";
    }
    outputFile << "\nSum: " << SumFunction(leftoverNumbers, countLeftover);
    outputFile << "\nAverage: " << AverageFunction(leftoverNumbers, countLeftover);
    outputFile << "\nMedian: " << MedianFunction(leftoverNumbers, countLeftover) << "\n";
    outputFile.close();
    cout<<"Output file written!\n";
}


/*

*/