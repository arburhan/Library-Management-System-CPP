// In the name of Allah, the most gracious, the most merciful
#include <bits/stdc++.h>
using namespace std;
// login status
bool isUserLoged = false;
bool isAdminLoged = false;
// user class
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
// book class
class Book
{
public:
    string name, isbn, category, publication, author;
    int stock;

    Book(const string &n, const string &i, const string &c, const string &p, const string &a, int s)
        : name(n), isbn(i), category(c), publication(p), author(a), stock(s) {}
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
    vector<Book> books;
    // add books constructor
    LMS()
    {
        books.push_back(Book("Paradoxical Sajid", "9780140237504", "Slap atheism", "Gurdian", "Arif Azad", 5));
        books.push_back(Book("Paradoxical Sajid 2", "9780061120084", "Slap atheism", "Samakalin", "Arif Azad", 8));
        books.push_back(Book("Akasher Opare Akash", "9780451524935", "Modesty", "Ilm House", "Lost Modesty", 13));
        books.push_back(Book("Onuvobe Allah'r Name Boichitro", "9780451524936", "Islamic", "Riddho", "Yasir Qadhi :> Ali Ahmad Mabrur", 13));
        books.push_back(Book("Story Of Beginning", "9780451524939", "Islamic", "Gurdian", "Omar Suleiman :> Ali Ahmad Mabrur", 13));
    }

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
        // admin
        if (id == 223311161 && password == "admin")
        {
            User adminUser(name, id, email, password);
            users.push_back(adminUser);
            cout << "Congrats! Admin user added successfully.\n";
        }
        // normal people
        else
        {
            User newUser(name, id, email, password);
            users.push_back(newUser);
            cout << "Congrats! You have successfully created an account and got a library card :)\n";
        }
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
    // show all books
    void showBooks()
    {
        int listCount = 1;
        for (const auto &book : books)
        {
            cout << listCount << ". " << book.name << "\n";
            listCount++;
        }
    }
    // show all category
    void showCategory()
    {
        int listCount = 1;
        for (const auto &book : books)
        {
            cout << listCount << ". " << book.category << "\n";
            listCount++;
        }
    }
    // show all publications
    void showPublications()
    {
        int listCount = 1;
        for (const auto &book : books)
        {
            cout << listCount << ". " << book.publication << "\n";
            listCount++;
        }
    }
    // add book (admin)
    void addBook()
    {
        cout << "Enter book details:\n";
        cout << "Name: ";
        string name;
        cin.ignore();
        getline(cin, name);

        cout << "ISBN: ";
        string isbn;
        cin >> isbn;

        cout << "Category: ";
        string category;
        cin.ignore();
        getline(cin, category);

        cout << "Publication: ";
        string publication;
        cin.ignore();
        getline(cin, publication);

        cout << "Author: ";
        string author;
        cin.ignore();
        getline(cin, author);
        cout << "Stock: ";
        int stock;
        cin >> stock;

        // Create a new Book object
        Book newBook(name, isbn, category, publication, author, stock);

        // Add the new book to the vector
        books.push_back(newBook);

        cout << "Book added successfully.\n";
    }
    // search isbn or name
    void searchBook()
    {
        cout << "\nenter isbn or name: ";
        string item;
        cin >> item;
        for (const auto &book : books)
        {
            if (book.isbn == item || book.name == item)
            {
                cout << book.name << "\n";
                break;
            }
        }
        cout << "books not found!\n";
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
void mainFunc(LMS lms, function<void(LMS lms)> logedUserMenu)
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
            logedUserMenu(lms);
        break;
    }
    case 3:
    {
        cout << "\nall books in our library: \n";
        lms.showBooks();
        break;
    }
    case 4:
    {
        cout << "\nall books in our Category: \n";
        lms.showCategory();
        break;
    }
    case 5:
    {
        cout << "\nall books publications: \n";
        lms.showPublications();
        break;
    }
    case 6:
    {
        cout << "\nsearch by isbn or name: \n";
        lms.searchBook();
        break;
    }

    default:
        cout << "invalid choice! please choose a valid choice :)\n";
    }
}
// sub main function
void logedUserMenu(LMS lms)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int logedMenu;
    cout << "********************\nWelcome Big & Not Found Library :)\n********************\n\n1.Show All Books\n2.Show All Category\n3.Show All Publications\n4.Search by isbn or name\n5.About Us\n\nEnter your choice: ";
    cin >> logedMenu;
    switch (logedMenu)
    {
    case 1:
    {
        lms.showBooks();
        break;
    }
    case 2:
    {
        lms.showCategory();
        break;
    }
    case 3:
    {
        lms.showPublications();
        break;
    }
    case 4:
    {
        lms.showCategory();
        break;
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