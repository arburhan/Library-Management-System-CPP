// In the name of Allah, the most gracious, the most merciful
#include <bits/stdc++.h>
using namespace std;
// create account
void signUP()
{
    cout << "Fill the form to get library card :) \n";
    cout << "Name: ";
    cin.ignore();
    string name;
    getline(cin, name);
    int id, password;
    cout << "id: ";
    cin >> id;
    cout << "password: ";
    cin >> password;
    cout << "Congrats! You have successfully create an account get a library card :)";
}
// log in
void logIn()
{
    cout << "Fill the form to get library card :) \n";
    int id, password;
    cout << "id: ";
    cin >> id;
    cout << "password: ";
    cin >> password;
    cout << "log in successful";
}
// about us
void aboutUs()
{
    cout << "\n===========================\n          About Us\n===========================\n\nBurhan Uddin Ashik => 223311161\nSohag Mia => 223311162\nAfia Akter => 223311163\n\n**************************\n*    LMS Console Project\n*      Developed by Varendra University       \n*           31st Batch E Section Students \n*           Subject: Software Engineering\n*      Teacher: Delwar Hossain\n*    Release: November 2023\n**************************\n";
}
// main function
void mainFunc()
{
    cout << "********************\nWelcome Big & Not Found Library :)\n********************\n\n1.SignUp\n2.LogIn\n3.Show All Books\n4.Show Category\n5.About Us\n\nEnter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        signUP();
        break;
    case 2:
        logIn();
        break;
    case 5:
        aboutUs();
        break;

    default:
        mainFunc();
        break;
    }
}

int main()
{

    mainFunc();

    return 0;
}