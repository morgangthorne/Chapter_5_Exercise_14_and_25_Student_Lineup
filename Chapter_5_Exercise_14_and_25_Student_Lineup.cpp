/*
Filename: Chapter_5_Exercise_14_and_25_Student_Lineup.cpp
Programmer: Morgan Thorne
Date: April 2025
Requirements:
-Write a program that prompts the user to enter the number of students in the class, then loops to read that many names.
-Once all the names have been read, it reports which student would be at the front of the line and
-which one would be at the end of the line. You may assume that no two students have the same name.
-Input Validation: Do not accept a number less than 1 or greater than 25 for the number of students.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

//Function Prototypes
void Display_Welcome();
int Open_File_Display();
bool GetRepeatInfo();
int Sort_File_Names();



int main()
{
    bool User_Repeat;

    do {
        Display_Welcome();

        Open_File_Display();

        Sort_File_Names();
        
        User_Repeat = GetRepeatInfo();

    }

    while (User_Repeat); {
        cout << "Thank you for using the program";
        return 0;
    }

}

//Displays Welcome Message and Explains Programs Purpose
void Display_Welcome() {
    cout << "There are 8 students in line\n";
    cout << "****************************\n";
    cout << endl;
}

//Displays all the names in the txt file
int Open_File_Display() {
    
    string Student;

    ifstream inputFile;

    inputFile.open("LineUp (1).txt");

    if (!inputFile) {
        cout << "Unable to open file.\n";
        return 1;
    }

    while (getline(inputFile, Student)) {
        cout << "\t" << Student << endl;
    }
    
    cout << endl;
    cout << "****************************\n\n";

    inputFile.close();

    return 0;
}

//Sorts through names in file and displays who would be first and last in line.
int Sort_File_Names() {
    string Student;
    string first;
    string last;

    ifstream inputFile;


    inputFile.open("LineUp (1).txt");

    if (!inputFile) {
        cout << "Unable to open file.\n";
        return 1;
    }

    cout << "Their place in line is ordered" << endl;
    cout << "alphabetically\n";
    cout << "\n****************************\n\n";

    if (getline(inputFile, Student)) {
        first = Student;
        last = Student;
    }

    while (getline(inputFile, Student)) {
        if (first > Student) {
            first = Student;
        }
        if (last < Student) {
            last = Student;
        }
    }
    
    cout << "   First is: " << first << endl;
    cout << "   Last is: " << last << endl;
    cout << "\n****************************\n\n";
    
    

    inputFile.close();

    return 0;
}

//Allows user to choose whether they want to repeat program or end it
bool GetRepeatInfo() {
    char choice;
    cout << "" << "Would you like to repeat Y/N: ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}