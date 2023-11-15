// In the name of Allah, the most gracious, the most merciful
#include <bits/stdc++.h>
using namespace std;
// login status
bool isUserLoged = false;
bool isAdminLoged = false;
// create accounts
class User
{
public:
    string name;
    int id;
    string email;
    string password;

    User(const string &n, int i, const string &e, const string &p)
        : name(n), id(i), email(e), password(p) {}
};
// log in function
pair<int, string> logIn()
{
    pair<int, string> loginData;
    cout << "Fill the form to get library card :) \n";
    int id;
    string password;
    cout << "id: ";
    cin >> id;
    cout << "password: ";
    char p;
    cin >> p;
    cin >> password;
    password = p + password;
    loginData.first = id;
    loginData.second = password;
    return loginData;
}
// main class
class LMS
{
public:
    vector<User> users;
    // sign up function
    void signup()
    {
        cout << "Fill the form to get library card :) \n";
        cout << "Name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        int id;
        cout << "id: ";
        cin >> id;
        cout << "email: ";
        string email;
        cin.ignore();
        getline(cin, email);
        cout << "password: ";
        string password;
        char p;
        cin >> p;
        cin >> password;
        password = p + password;

        User newUser(name, id, email, password);
        users.push_back(newUser);
        cout << "Congrats! You have successfully created an account and got a library card :)\n";
    }

    // login
    bool login(int id, const string &password)
    {
        for (const auto &user : users)
        {
            if (user.id == id && user.password == password)
            {
                cout << "Congratulations! Login successful.\n";
                return true;
            }
        }
        cout << "Login failed. Invalid ID or password.\n";
        return false;
    }

    // about us
    void aboutUs()
    {
        cout << "\n===========================\n          About Us\n===========================\n\nBurhan Uddin Ashik => 223311161\nSohag Mia => 223311162\nAfia Akter => 223311163\n\n**************************\n*    LMS Console Project\n*      Developed by Varendra University       \n*           31st Batch E Section Students \n*           Subject: Software Engineering\n*      Teacher: Delwar Hossain\n*    Release: November 2023\n**************************\n";
    }
    // print all users
    void printAllUsers()
    {
        cout << "List of all users:\n";
        for (const auto &user : users)
        {
            cout << "Name: " << user.name << ", ID: " << user.id
                 << ", Email: " << user.email << ", Password: " << user.password << endl;
        }
    }
};

// main function
void mainFunc(LMS lms, function<void()> logedUserMenu)
{
    int menu;
    cout << "********************\nWelcome Big & Not Found Library :)\n********************\n\n1.SignUp\n2.LogIn\n3.Show All Books\n4.Show All Category\n5.Show All Publications\n6.Search by isbn or name\n7.About Us\n\nEnter your choice: ";
    cin >> menu;
    switch (menu)
    {
    case 1:
        lms.signup();

    case 2:
    {
        pair<int, string> loginDAta = logIn();
        isUserLoged = lms.login(loginDAta.first, loginDAta.second);
        if (isUserLoged)
            logedUserMenu();
    }

    default:
        cout << "invalid choice! please choose a valid choice :)\n";
    }
}
// sub main function
void logedUserMenu()
{
    int logedMenu;
    cout << "********************\nWelcome Big & Not Found Library :)\n********************\n\n1.Show All Books\n2.Show All Category\n3.Show All Publications\n4.Search by isbn or name\n5.About Us\n\nEnter your choice: ";
    cin >> logedMenu;
    switch (logedMenu)
    {
    case 1:
        cout << "wow\n";

    case 2:
    {
        cout << "wow good\n";
    }

    default:
        cout << "invalid choice! please choose a valid choice :)\n";
    }
}

int main()
{
    LMS lms;
    mainFunc(lms, logedUserMenu);
    return 0;
}