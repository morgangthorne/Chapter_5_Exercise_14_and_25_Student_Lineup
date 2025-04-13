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

using namespace std;

//Function Prototypes
void User_Inputs_Student_Names(string & first, string & last, int & Number_of_Students);
void Display_First_Last(string & first, string & last, int & Number_of_Students);

int main()
{
    string Student;
    string first;
    string last;

    int Number_of_Students = 0;
    

    User_Inputs_Student_Names(first, last, Number_of_Students);

    Display_First_Last(first, last, Number_of_Students);
     
    return 0;

}

void User_Inputs_Student_Names(string & first, string & last, int & Number_of_Students){
    string Student;

    cout << "How many students are in line: ";
    cin >> Number_of_Students;
    
    while (Number_of_Students < 0 || Number_of_Students > 25) {
        cout << "Please enter a number between 0 and 25.\n";
        cout << "How many students are in line: ";
        cin >> Number_of_Students;
    }
    
    cin.ignore();
    
    for (int i = 1; i <= Number_of_Students; i++) {
        cout << "Name of student " << i << ": ";
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

void Display_First_Last(string & first, string & last, int & Number_of_Students){
    cout << "The students are ordered in alphabetical order.\n";
    cout << "There are " << Number_of_Students << " students in this line!\n";
    cout << "The first in line is " << first << endl;
    cout << "Last in line is  " << last;
}