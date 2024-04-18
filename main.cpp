#include <bits/stdc++.h>
using namespace std;

bool checkfile(string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        ofstream newfile(filename);
        return false;
    }
    return true;
}

void generateuserfile(string username)
{
    string filename = username + ".txt";

    ofstream my_file(filename);
    if (my_file)
        cout << "Registered Sucessfully" << endl;
    else
        cout << "Error While Registering" << endl;
}

void Signup()
{
    cout << "\t\t\t\t\tSignUp to RS INC.\n";
    string name, password;
    cout << "Enter Your Name : ";
    getline(cin, name);
    cout << "Enter a Password : ";
    getline(cin, password);

    string filename = "Userdata.txt";
    if (checkfile(filename))
    {
        ofstream my_file(filename, ios::app);
        my_file << name << "\t\t"
                << password << endl;
    }

    generateuserfile(name);
}

string trim(const string &str)
{
    size_t first = str.find_first_not_of(" \t");
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

void Login()
{
    cout << "\t\t\t\t\tLogin to RS INC.\n";
    string filename = "Userdata.txt";
    string username, password;
    cout << "Enter Username : ";
    getline(cin, username);
    cout << "Enter Password : ";
    getline(cin, password);

    ifstream my_file(filename);
    if (!my_file)
    {
        cout << "Error: Could not open file." << endl;
        return;
    }

    bool loginSuccess = false;
    string line;

    while (getline(my_file, line))
    {
        istringstream iss(line);
        string storedname, storedpassword;
        if (getline(iss, storedname, '\t') && getline(iss, storedpassword))
        {
            storedname = trim(storedname);
            storedpassword = trim(storedpassword);
            if (storedname == username && storedpassword == password)
            {
                cout << "Login Successful" << endl;
                loginSuccess = true;
                break;
            }
        }
    }

    my_file.close();

    if (!loginSuccess)
        cout << "Wrong Credentials! Try Again." << endl;
}
void Forgot()
{
    cout << "\t\t\t\t\tForgot Password\n";
    string filename = "Userdata.txt";
    string username;
    cout << "Enter Username : ";
    getline(cin, username);

    string line;
    ifstream my_file(filename);
    bool isfound = false;
    while (getline(my_file, line))
    {
        string storedname, storedpassword;
        istringstream iss(line);
        if (getline(iss, storedname, '\t') && getline(iss, storedpassword))
        {
            storedname = trim(storedname);
            storedpassword = trim(storedpassword);
            if (storedname == username)
            {
                cout << "Your Password is " << storedpassword;
                isfound = true;
                break;
            }
        }
    }
    if (!isfound)
        cout << "Username Not Found";
}

int main()
{
    string filename = "Userdata.txt";
    if (!checkfile(filename))
    {
        ofstream my_file(filename);
        my_file << "Username"
                << "\t\tPassword" << endl;
    }

    cout << "\t\t\t\t\tWelcome to RS INC.\n";
    int choice;
    cout << "\t\t\t\t\t\tMenu\n";
    cout << "1.SignUp\n2.Login\n3.Forgot Password\n4.Exit";
    cout << "\nEnter your choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
    case 1:
        Signup();
        break;
    case 2:
        Login();
        break;
    case 3:
        Forgot();
        break;
    default:
        cout << "Exiting.......";
    }
}
