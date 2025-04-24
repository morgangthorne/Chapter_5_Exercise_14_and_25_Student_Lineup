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
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

//Function Prototypes
void User_Inputs_Student_Names(string & first, string & last, int & Number_of_Students);
void Display_First_Last(string & first, string & last, int & Number_of_Students);
bool GetRepeatInfo();

int main()
{
    string Student;
    string first;
    string last;

    int Number_of_Students = 0;

    bool User_Repeat;
   
    do {
        User_Inputs_Student_Names(first, last, Number_of_Students);

        Display_First_Last(first, last, Number_of_Students);

        User_Repeat = GetRepeatInfo();
    }
    while (User_Repeat); {
        cout << "Thank you for using the program";
        return 0;
    }
}


//Function allows user to enter names and the number of students as well as evaluates the names to determine which are the first and last in line.
void User_Inputs_Student_Names(string & first, string & last, int & Number_of_Students){
    string Student;

    cout << setw(50) << right << "" << "Line Sorter V1\n";
    
    cout << setw(39) << right << "" << "How many students are in line: ";
    cin >> Number_of_Students;
    
    while (Number_of_Students <= 1 || Number_of_Students > 25) {
        cout << setw(35) << right << "" << "Please enter a number from 2 to 25.\n";
        cout << setw(35) << right << "" << "How many students are in line: ";
        cin >> Number_of_Students;
    }
    
    cin.ignore();

    cout << setw(40) << right << "" << "Enter the names of the students\n";
    cout << setw(40) << right << "" << "*******************************\n\n";
    
    for (int i = 1; i <= Number_of_Students; i++) {
        cout << setw(48) << right << "" << "Student " << i << ": ";
        getline(cin, Student);


        if (i == 1) {
            first = Student;
            last = Student;
        }
        else {
            if (Student < first) {
                first = Student;
            }
            if (Student > last) {
                last = Student;
            }
        }
    }
}


//Displays the first and last in line.
void Display_First_Last(string & first, string & last, int & Number_of_Students){
    cout << endl;
    cout<< setw(33) << right << "" << "***********************************************\n";
    cout << setw(33) << right << "" << "The students are ordered in alphabetical order.\n";
    cout << setw(44) << right << "" << "There are " << Number_of_Students << " students.\n";
    cout << setw(45) << right << "" << "First in line: " << first << endl;
    cout << setw(45) << right << "" << "Last in line:  " << last << endl;
}

//Allows user to choose whether they want to repeat program or end it
bool GetRepeatInfo() {
    char choice;
    cout << setw(37) << right << "" << "Would you like to repeat Y/N: ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}