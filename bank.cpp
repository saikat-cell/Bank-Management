///Admin user name : Admin
///Admin password : 12345
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<conio.h>
using namespace std;


// Function to log transactions
void log_transaction(int account_number, const std::string &transaction_type, int amount)
{
    ofstream transFile("transactions.txt", ios::app);
    if (!transFile)
    {
        cout << "Error opening transaction file!" << endl;
        return;
    }

    // Get current date and time
    time_t current_time = time(nullptr);
    char timestamp[100];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Log transaction details
    transFile << account_number << "\t" << transaction_type << "\t" << amount << "\t" << timestamp << endl;
    transFile.close();
}

class account
{
    int acno;
    char name[50];
    int deposit;
    char type;
    int Password;
public:
    void create_account(int id);
    void show_account() const;
    void modify();
    void dep(int);
    void draw(int);
    void report() const;
    int retacno() const;
    int retdeposit() const;
    char rettype() const;
    int retpass() const;
};

void account::create_account(int id)
{

    acno = id;
    cout << "\n\n\t\t\tPlease Enter the Name of the Account holder Here: ";
    cin.ignore(); // Clear the input buffer
    cin.getline(name, 50);
    cout << "\n\t\t\tEnter Type of the Account (C/S): ";
    cin >> type;
    type = toupper(type); // Convert to uppercase
    cout << "\n\t\t\tEnter The Initial amount: ";
    cin >> deposit;
    cout << "\n\t\t\tSet Password  For User: ";
    cin >> Password;
    cout << "\n\n\t\t\tAccount Created..";

    _getch();
}


void account::show_account() const
{
    cout << "\n\t\t\tAccount No. : " << acno;
    cout << "\n\t\t\tAccount Holder Name : ";
    cout << name;
    cout << "\n\t\t\tType of Account : " << type;
    cout << "\n\t\t\tBalance amount : " << deposit;
}


void account::modify()
{
    cout << "\n\t\t\tAccount No. : " << acno;
    cout << "\n\t\t\tModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\t\t\tModify Type of Account : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\t\t\tModify Balance amount : ";
    cin >> deposit;
}


void account::dep(int x)
{
    deposit += x;
}

void account::draw(int x)
{
    deposit -= x;
}

void account::report() const
{
    cout << left << setw(10) << acno
         << setw(20) << name
         << setw(10) << type
         << setw(15) << deposit
         << Password << endl;
}

int account::retacno() const
{
    return acno;
}

int account::retdeposit() const
{
    return deposit;
}

char account::rettype() const
{
    return type;
}
int account::retpass() const
{
    return Password;
}

// Function to show transaction history for a user

void show_transaction_history(int account_number)
{
    ifstream transFile("transactions.txt");
    if (!transFile)
    {
        cout << "Error opening transaction file!" << endl;
        _getch();
        return;
    }

    string line;
    bool found = false;

    cout << "\n\n\t\t\tTransaction History for Account No. " << account_number << "\n";
    cout << string(80, '-') << endl;
    cout << left << setw(15) << "Account No."
         << setw(20) << "Transaction Type"
         << setw(15) << "Amount"
         << "Date & Time" << endl;
    cout << string(80, '-') << endl;

    while (getline(transFile, line))
    {
        // Extract account number and transaction details from the line
        size_t tabPos = line.find("\t");
        string transAccountNo = line.substr(0, tabPos);

        // If the account number matches, display the transaction details
        if (transAccountNo == to_string(account_number))
        {
            // Print the formatted transaction details
            size_t secondTabPos = line.find("\t", tabPos + 1);
            string transactionType = line.substr(tabPos + 1, secondTabPos - tabPos - 1);

            size_t thirdTabPos = line.find("\t", secondTabPos + 1);
            string amountStr = line.substr(secondTabPos + 1, thirdTabPos - secondTabPos - 1);

            string dateTime = line.substr(thirdTabPos + 1);

            // Display in properly aligned format
            cout << left << setw(15) << transAccountNo
                 << setw(20) << transactionType
                 << setw(15) << amountStr
                 << dateTime << endl;
            found = true;
        }
    }

    transFile.close();

    if (!found)
    {
        cout << "\nNo transactions found for this account." << endl;
    }

    cout << "\n\n\t\t\tPress any key to continue...";
    cout.flush();  // Force flush the output buffer
    _getch();  // Wait for user input
}





void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);

int main()
{
    char ch, ch1;
    int num;

    do
    {
L1:
        system("CLS");
        cout << "\033[1;32m"
             << "\n\t\t=============================================\n"
             << "\t\t\033[1;34m"
             << "|                                           |\n"
             << "\t\t|      \033[1;33m\t  BANK MANAGEMENT SYSTEM\033[1;34m\t    |\n"
             << "\t\t|                                           |\n"
             << "\033[1;32m"
             << "\t\t=============================================\n\033[0m";
        cout << "\t\t\t\t    ::MAIN MENU::\n";
        cout << "\t\t\t\t     Log in as:-\n";
        cout << "\n\t\t\t\t1. ADMIN";
        cout << "\n\t\t\t\t2. USER";
        cout << "\n\t\t\t\t3. EXIT\n";
        cout << "\n\n\t\t\t\tChoice :";
        cin >> ch1;

        if(ch1 == '3')  // Exit option
        {
            system("CLS");
            cout << "\n\n\t\t\tThank you for using Bank Management System\n";
            return 0;  // Exit the program
        }
        else if(ch1 == '1')  // Admin Menu
        {

            string userName;
            int password;
            cout << "\n\n\t\t\tEnter admin user name : " ;
            cin >> userName;
            cout << "\n\n\t\t\tEnter admin Password : ";
            cin >> password;
            string usN="Admin";
            int pass= 12345;
            if(userName==usN && password==pass)
            {
A:
                system("CLS");
                cout << "\n\n\t\t\t\tSelect Your Option (1-4): ";
                cout << "\n\t\t\t\t1. NEW ACCOUNT";
                cout << "\n\t\t\t\t2. ALL ACCOUNT HOLDER LIST";
                cout << "\n\t\t\t\t3. MODIFY AN ACCOUNT";
                cout << "\n\t\t\t\t4. EXIT";
                cout << "\n\n\t\t\t\tChoice : ";
                cin >> ch;

                switch(ch)
                {
                case '1':
                    write_account();
                    goto A;
                    break;
                case '2':
                    display_all();
                    goto A;
                    break;
                case '3':
                    system("CLS");
                    cout << "\n\n\t\t\tEnter The account No. : ";
                    cin >> num;
                    modify_account(num);
                    goto A;
                    break;
                case '4':
                default:
                    system("CLS");
                    cout << "\n\n\t\t\tBrought To You By Ahmad And Abdul Rehman";
                    goto L1;
                }
            }
            else
            {
                cout << "\n\n\t\t\tWrong user name or password!!";
                cin.ignore();
                cin.get();
                goto L1;
            }

        }
        else if(ch1 == '2')  // User Menu
        {
            ifstream UniqueId("account.dat", ios::binary);
            account ac;
            int userId;
            int Pass;
            bool flag= false;
            cout << "\n\n\t\t\tEnter user id : " ;
            cin >> userId;
            cout << "\n\n\t\t\tEnter user Password : ";
            cin >> Pass;
            while (UniqueId.read((char*) (&ac), sizeof(account)))
            {
                if (ac.retacno() == userId and ac.retpass() == Pass )
                {
                    flag = true;
                    break;
                }
            }
            UniqueId.close();
            if(flag)
            {

U:
                system("CLS");
                cout << "\n\n\t\t\t\tSelect Your Option (1-5): ";
                cout << "\n\t\t\t\t1. DEPOSIT AMOUNT";
                cout << "\n\t\t\t\t2. WITHDRAW AMOUNT";
                cout << "\n\t\t\t\t3. BALANCE ENQUIRY";
                cout << "\n\t\t\t\t4. CLOSE AN ACCOUNT";
                cout << "\n\t\t\t\t5. VIEW TRANSACTION HISTORY";
                cout << "\n\t\t\t\t6. EXIT";
                cout << "\n\n\t\t\t\tChoice : ";
                cin >> ch;

                switch(ch)
                {
                case '1':
                    system("CLS");
                    deposit_withdraw(userId, 1);
                    goto U;
                    break;
                case '2':
                    system("CLS");
                    deposit_withdraw(userId, 2);
                    goto U;
                    break;
                case '3':
                    system("CLS");
                    display_sp(userId);
                    goto U;
                    break;
                case '4':
                    system("CLS");
                    delete_account(userId);
                    goto L1;
                    break;
                case '5':
                    system("CLS");
                    show_transaction_history(userId);
                    goto U;
                    break;
                case '6':
                default:
                    system("CLS");
                    goto L1;
                }
            }
            else
            {
                cout << "\n\n\t\t\tWrong user name or password!!";
                cin.ignore();
                cin.get();
                goto L1;
            }
        }
        else
        {
            system("CLS");
            cout << "\n\n\t\t\tInvalid Choice! Please select a valid option.";
            cout << "\n\n\t\t\tPress any key to continue...";
            cin.ignore();
            cin.get();
            goto L1;
        }

        cin.ignore();
        cin.get();
    }
    while (true);

    return 0;
}

void write_account()
{
    system("CLS");
    int id;
    cout << "\n\t\t\tEnter the Account No. : ";
    cin >> id;

    // Check if the ID already exists
    ifstream ReadIdFile("ids.txt");
    int found = 0;

    if (ReadIdFile)   // Proceed if file exists
    {
        int A_id;
        while (ReadIdFile >> A_id)   // Read integers one by one
        {
            if (A_id == id)
            {
                found = 1;
                cout << "\n\t\t\tThis ID Already Exists.";
                break;
            }
        }
        ReadIdFile.close();
    }

    if (found)
    {
        _getch();
        return; // Exit if ID already exists
    }

    // If the ID is new, append it to the file
    ofstream IdFile("ids.txt", ios::app); // Open file in append mode
    if (!IdFile)
    {
        cout << "\n\t\t\tError opening file for writing!";
        _getch();
        return;
    }

    IdFile << id << endl; // Write the ID to the file
    IdFile.close();

    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    ac.create_account(id);
    outFile.write((char*) (&ac), sizeof(account));
    outFile.close();


}

void display_sp(int n)
{
    account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\t\t\tBALANCE DETAILS\n";
    while (inFile.read((char*) (&ac), sizeof(account)))
    {
        if (ac.retacno() == n)
        {
            ac.show_account();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\n\t\t\tAccount number does not exist";
    cin.ignore();
    cout<<"\n\n\t\t\tPress any key to contunue";
    _getch();
}



void modify_account(int n)
{
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read((char*) (&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            cout << "\n\n\t\t\tEnter The New Details of account" << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write((char*) (&ac), sizeof(account));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\t\t\tRecord Not Found ";
    _getch();
}




void delete_account(int n)
{
    account ac;
    ifstream inFile,read_idFile, HistoryFile;
    ofstream outFile,write_idFile, tem_historyFile;
    bool found = false; // Flag to track if the account is found

    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened! Press any key...";
        _getch();
        return;
    }
    read_idFile.open("ids.txt");
    if (!read_idFile)
    {
        cout << "File could not be opened! Press any key...";
        _getch();
        return;
    }
    HistoryFile.open("transactions.txt");
    if (!HistoryFile)
    {
        cout << "File could not be opened! Press any key...";
        _getch();
        return;
    }
    string line;

    outFile.open("Temp.dat", ios::binary);
    write_idFile.open("tem_id.txt", ios::app);
    tem_historyFile.open("tem_transactions.txt", ios::app);

    inFile.seekg(0, ios::beg);


    while (inFile.read((char*)(&ac), sizeof(account)))
    {
        if (ac.retacno() != n)
        {
            outFile.write((char*)(&ac), sizeof(account));
            write_idFile<<ac.retacno()<<endl;
            while (getline(HistoryFile, line))
            {
                // Extract account number and transaction details from the line
                size_t tabPos = line.find("\t");
                string transAccountNo = line.substr(0, tabPos);

                // If the account number matches, display the transaction details
                if (transAccountNo != to_string(n))
                {
                    tem_historyFile << line << endl;
                }
            }
        }
        else
        {
            found = true; // Account to delete is found
        }
    }

    inFile.close();
    outFile.close();
    read_idFile.close();
    write_idFile.close();
    HistoryFile.close();
    tem_historyFile.close();
    if (!found)
    {
        // If the account was not found, delete Temp.dat and inform the user
        remove("Temp.dat");
        remove("tem_id.txt");
        remove("tem_transactions.txt");
        cout << "\n\nAccount number " << n << " does not exist.";
    }
    else
    {
        // If the account was found, replace the original file
        remove("account.dat");
        remove("ids.txt");
        remove("transactions.txt");
        rename("Temp.dat", "account.dat");
        rename("tem_id.txt", "ids.txt");
        rename("tem_transactions.txt", "transactions.txt");
        cout << "\n\nRecord Deleted.";
    }

    _getch();
}


void display_all()
{
    system("CLS");
    account ac;

    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        _getch();
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << string(65, '=') << endl;
    cout << left << setw(10) << "A/c no."
         << setw(20) << "NAME"
         << setw(10) << "Type"
         << setw(15) << "Balance"
         << "Password" << endl;
    cout << string(65, '=') << endl;
    while (inFile.read((char*) (&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
    cout<<"Press any to contunue";
    _getch();
}


void deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read((char*) (&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            if (option == 1)
            {
                cout << "\n\n\t\t\tTO DEPOSITSS AMOUNT";
                cout << "\n\n\t\t\tEnter The amount to be deposited: ";
                cin >> amt;
                ac.dep(amt);
                log_transaction(n, "Deposit", amt);  // Log the deposit transaction
            }
            if (option == 2)
            {
                cout << "\n\n\t\t\tTO WITHDRAW AMOUNT";
                cout << "\n\n\t\t\tEnter The amount to be withdraw: ";
                cin >> amt;
                int bal = ac.retdeposit() - amt;
                if (bal < 0)
                    cout << "Insufficience balance";
                else
                {
                    ac.draw(amt);
                    log_transaction(n, "Withdraw", amt);  // Log the withdrawal transaction
                }
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write((char*) (&ac), sizeof(account));
            cout << "\n\n\t\t\tRecord Updated";
            found = true;
            _getch();
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\t\t\tRecord Not Found ";
}



