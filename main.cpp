// In the name of Allah, the most gracious, the most merciful
#include <bits/stdc++.h>
#include <conio.h>
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
// Function to save users to a file
void saveUsersToFile(const vector<User> &users, const string &filename)
{
    ofstream outFile(filename);

    if (outFile.is_open())
    {
        for (const auto &user : users)
        {
            outFile << user.name << "," << user.id << "," << user.email << "," << user.password << "\n";
        }

        outFile.close();
        cout << "Users saved to file successfully.\n";
    }
    else
    {
        cout << "Unable to open the file for saving users.\n";
    }
}
// books class
class Book
{
public:
    string name, isbn, category, publication, author;
    int stock;

    // Constructor
    Book(const string &n, const string &i, const string &c,
         const string &p, const string &a, int s)
        : name(n), isbn(i), category(c), publication(p), author(a), stock(s) {}

    // Function to convert Book data to CSV format
    string toCSVString() const
    {
        ostringstream oss;
        oss << quoted(name) << "," << quoted(isbn) << "," << quoted(category) << ","
            << quoted(publication) << "," << quoted(author) << "," << stock;
        return oss.str();
    }

    // Static function to parse book info from a stringstream
    static bool parseBookInfo(istringstream &iss, string &name,
                              string &isbn, string &category,
                              string &publication, string &author, int &stock)
    {
        if (iss >> quoted(name) >> quoted(isbn) >> quoted(category) >>
            quoted(publication) >> quoted(author) >> stock)
        {
            return true;
        }
        return false;
    }
};

// log in function
pair<int, string> logIn()
{
    pair<int, string> loginData;
    cout << "Fill the form to get library card :) \n";
    int id;
    cout << "id: ";
    cin >> id;
    char ch = ' ';
    string password;
    cout << "Password: ";
    while (ch != 13)
    {
        ch = getch();
        if (ch == 8 || ch == 13 || ch == 32)
            continue;
        else
        {
            password += ch;
            cout << "*";
        }
    }
    loginData.first = id;
    loginData.second = password;
    return loginData;
}

// main class
class LMS
{
    bool booksLoaded;

public:
    vector<User> users;
    vector<Book> books;

    // add books constructor
    LMS() : booksLoaded(false) {}

    // Function to save user data to a CSV file
    void saveUserToCSV(const User &user)
    {
        ofstream file("users.csv", ios::app); // Open the file in append mode

        if (file.is_open())
        {
            // Write user data to the file in CSV format
            file << user.name << "," << user.id << "," << user.email << "," << user.password << "\n";

            cout << "User data saved to CSV file.\n";

            file.close(); // Close the file
        }
        else
        {
            cout << "Error opening the CSV file.\n";
        }
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
        char ch = ' ';
        string password;
        cout << "You don't have permit to backspace\nPassword: ";
        while (ch != 13)
        {
            ch = getch();
            if (ch == 8 || ch == 13 || ch == 32)
                continue;
            else
            {
                password += ch;
                cout << "*";
            }
        }
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
            // Create a new user
            User newUser(name, id, email, password);

            // Save the user to the vector and CSV file
            users.push_back(newUser);
            saveUserToCSV(newUser);
            cout << "Congrats! You have successfully created an account and got a library card :)\n";
        }
    }
    // load users from csv
    void loadUsersFromCSV()
    {
        ifstream file("users.csv");

        if (file.is_open())
        {
            string line;

            // Read the first line (column headers) and discard it
            getline(file, line);

            while (getline(file, line))
            {
                istringstream iss(line);
                string name, email, password;
                int id;

                // Parse the CSV line into user data
                if (getline(iss, name, ',') &&
                    (iss >> id) &&
                    getline(iss >> ws, email, ',') &&
                    getline(iss >> ws, password))
                {
                    User newUser(name, id, email, password);
                    users.push_back(newUser);
                }
            }

            file.close();
        }
        else
        {
            cout << "Error opening the CSV file.\n";
        }
    }

    // Function for user login
    bool login(int id, const string &password)
    {
        for (const auto &user : users)
        {
            if (user.id == id && user.password == password)
            {
                cout << "Login successful.\n";
                return true;
            }
        }

        cout << "Login failed. Invalid ID or password.\n";
        return false;
    }
    // load books
    void loadBooksFromCSV()
    {
        ifstream file("books.csv");

        if (file.is_open())
        {
            string line;
            // Skip the first line (column names)
            getline(file, line);

            while (getline(file, line))
            {
                istringstream iss(line);
                string name, isbn, category, publication, author;
                int stock;

                // Parse the CSV line into book data
                if (Book::parseBookInfo(iss, name, isbn, category, publication, author, stock))
                {
                    Book newBook(name, isbn, category, publication, author, stock);
                    books.push_back(newBook);
                }
            }

            file.close();
            cout << "Books data loaded from CSV file successfully.\n";
        }
        else
        {
            cout << "Error opening the CSV file for loading books data.\n";
        }
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

    // Member function to show unique book categories
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
        char isbnc;
        cin >> isbnc;
        getline(cin, isbn);
        isbn = isbnc + isbn;

        cout << "Category: ";
        string category;
        char categoryC;
        cin >> categoryC;
        getline(cin, category);
        category = categoryC + category;

        cout << "Publication: ";
        string publication;
        char pub;
        cin >> pub;
        getline(cin, publication);
        publication = pub + publication;

        cout << "Author: ";
        string author;
        char auth;
        cin >> auth;
        getline(cin, author);
        author = auth + author;
        cout << "Stock: ";
        int stock;
        cin >> stock;

        // Create a new Book object
        Book newBook(name, isbn, category, publication, author, stock);

        // Add the new book to the vector
        books.push_back(newBook);

        // Save the new book to the file in append mode
        ofstream outFile("books.csv", ios::app);

        if (outFile.is_open())
        {
            outFile << newBook.name << "," << newBook.isbn << "," << newBook.category << ","
                    << newBook.publication << "," << newBook.author << "," << newBook.stock << "\n";

            outFile.close();
            cout << "Book added and saved to CSV file successfully.\n";
        }
        else
        {
            cout << "Unable to open the file for saving books.\n";
        }
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
    // issue books
    void issueBooks()
    {
    }
};

// main function
void mainFunc(LMS lms, function<void(LMS lms)> logedUserMenu)
{
    lms.loadUsersFromCSV();
    lms.loadUsersFromCSV();
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
        {
            logedUserMenu(lms);
            isUserLoged = true;
        }
        break;
    }
    case 3:
    {
        cout << "\nall books in our library: \n";
        lms.showBooks();
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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