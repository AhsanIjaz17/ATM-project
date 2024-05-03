#include "Account.h"

bool Account::login() {
    cout << "\n\n\t\t\t-->>--=== Welcome ===-<<---" << std::endl;
     bar_Load();// Display a loading bar
    string username = "ahsan";
    string password = "12345";

    string inputUsername;
    string inputPassword;
    int attempts = 0;
    int consecutiveIncorrectAttempts = 0;

    cout << "\n\n\t\t\t---=== ATM Login ===---" << std::endl;

    while (attempts < 3) {
        cout << "Enter Login: ";
        cin >> inputUsername;
        cout << "\nEnter Pincode: ";
        cin >> inputPassword;

        if (inputUsername == username && inputPassword == password) {
            cout << "\nLogin successful!" << std::endl;
            return true;  // Return true to indicate successful login
        } else {
            attempts++;
            consecutiveIncorrectAttempts++;
            cout << "\nLogin failed. Invalid username or password." << endl;

            // Check if the user has entered incorrect credentials three times consecutively
            if (consecutiveIncorrectAttempts == 3) {
                cout << "\n\nExceeded maximum consecutive incorrect login attempts. \n\nDisabling login." << std::endl;
                return false;  // Return false to indicate disabled login
            }
        }
    }

    // If the loop completes without a successful login, return false
    return false;
}

void Account::menu() {
p:
    system("cls");// commamd used for clearing screen
    int choice;
    string pin, username;
    cout << "\n\n\t\t---===Control Pannel===---";
    cout << "\n\n1.Customer";
    cout << "\n2.Administrator";
    cout << "\n3.Exit";
    cout << "\n\nEnter your choice\t:";
    cin >> choice;
    cout << "username";
    cin >> username;
    cout << "pincode";
    cin >> pin;
    //void bar_Load();
    switch (choice) {
    case 1:

        showCustomer();
        break;

    case 2:

        if (pin == "123" && username == "admin") {
            showAdministrator();
        }
        else {
            return;
        }
    case 3:
        exit(0);
    default:
        cout << "\n\nInvalid choice please enter a valid naumber";
    }
    goto p;
}
// ---------==== Customer  ====--------------

void Account::showCustomer() {
    //bar_Load();
    system("cls");
p:
    int choice;
    cout << "\n\n1----Withdraw Cash";
    cout << "\n2----Cash Transfer";
    cout << "\n3----Deposit Cash";
    cout << "\n4----Display Balance";
    cout << "\n5.Exit";

    cout << "\n\nEnter your choice:\t";
    cin >> choice;
    system("cls");

    switch (choice) {
    case 1:
        system("cls");
        double amount, total;
        int num, number;
        this->Withdraw_Cash(amount, total);

        break;
    case 2:
        system("cls");
        this->Cash_Transfer(amount, total, num, number);
        break;
    case 3:
        system("cls");
        this->Deposit_Cash(amount, total);
        break;
    case 4:
        system("cls");
        this->Display_Balance(total);
        break;
    case 5:
        exit(0);
    default:
        cout << "\n\nInvalid choice please enter a valid naumber";
    }
    goto p;

}

// ---------==== Withdraw Cash  ====--------------
void Account::Withdraw_Cash(double amount, double total) {
    string  account_number;
    char choice;
    int  value = 0;
    ifstream file;
    file.open("Account.txt");
    if (!file) {
        cout << "File opening errors\n";
    }
    else {

        cout << "Account ID:\t";
        cin >> account_number;
        cout << "\nEnter the Withdraw  amount:\t";
        cin >> amount;
        if (amount <= 0.0) {
            cout << "\nInvalid value please enter a valid value";
        }
        int total;
        cout << "\nCash  withdraw  Successfully n!";
        while (file >> ID >> pincode >> holderName >> type >> startingBalance) {
            if (ID == account_number) {
                total = startingBalance - amount;
                value++;
                cout << "\n\nDo you wish to print a receipt (Y/N)?  \t";
                cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                    cout << "\t\t>>------------------------------<<";
                    cout << "\n\t\t|Account\t #" << ID << " " << "\n\t\t|Withdraw amount:\t" << amount;
                    cout << "\n\t\t|Current balance :\t" << total;
                    date();
                    cout << "\t\t>>-------------------------------<<";
                    cout << "\n\n\t\t--->>Thanks for Availing  Our Services <<---";
                    return;
                }
                else {
                    if (choice == 'N' || choice == 'n')
                        return;
                }
            }
        }
        file.close();
    }

    if (value == 0) {
        cout << "record not found\n";
    }
}

// --------==== Deposit Cash ====-----------
void Account::Deposit_Cash(double amount, double total) {
    string  account_number;
    // string t_id;
    char choice;
    int  value = 0;
    ifstream file;
    file.open("Account.txt");
    if (!file) {
        cout << "File opening errors\n";
    }
    else {

        cout << "Account ID:\t";
        cin >> account_number;
        cout << "\nEnter the Deposit amount:\t";
        cin >> amount;
        if (amount <= 0.0) {
            cout << "\nInvalid value please enter a valid value";
        }
        int total;
        cout << "\nCash  Deposit Successfully n!";
        while (file >> ID >> pincode >> holderName >> type >> startingBalance) {
            if (ID == account_number) {
                total = startingBalance + amount;
                value++;
                cout << "\n\nDo you wish to print a receipt (Y/N)?  \t";
                cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                    cout << "\t\t>>------------------------------<<";
                    cout << "\n\t\t|Account\t #" << ID << " " << "\n\t\t|Deposited amount:\t" << amount;
                    cout << "\n\t\t|Current balance :\t" << total;
                    date();
                    cout << "\t\t>>-------------------------------<<";
                    cout << "\n\n\t\t--->>Thanks for Availing  Our Services <<---";
                    return;
                }
                else {
                    if (choice == 'N' || choice == 'n')
                        return;
                }
            }
        }
        file.close();
    }

    if (value == 0) {
        cout << "record not found\n";
    }
}

// ---------====  Cash Transfer  ====-------------
void Account::Cash_Transfer(int amount, int total, int num, int number) {
    int account_number;
    cout << "Account ID:\t";
    cin >> account_number;
    cout << "Enter amount in multiples of 500:\t";
    cin >> amount;
    if (amount > current_balance) {
        cout << "\nInsufficient balance! please enter a lower value";
        return;
    }
    if (amount % 500 == 0) {
        cout << "\nEnter the account number to which you want to transfer:\t";
        cin >> num;
        cout << "You wish to deposit Rs " << "-->>(";
        cout << amount << ")<<--";
        cout << " in account held by Mr. Muhammad Ali" << endl;
        cout << "\nIf this information is correct please re-enter the account number:\t";
        cin >> number;
        total = current_balance - amount;
        if (num == number) {
            cout << "\nTransaction confirmed.";
        }

        else {
            cout << "\n Invalid account number";
            return;
        }

    }
    else {
        cout << "invalid ";
        return;

    }
    char choice;
    cout << "\n\nDo you wish to print a receipt (Y/N)? \t";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        cout << "\t\t>>------------------------------<<";
        cout << "\n\t\t|Account\t #" << account_number;
        cout << "\n\t\t|Amount Transferred:\t" << amount;
        cout << "\n\t\t|Current balance :\t" << total;
        date();
        cout << "\t\t>>-------------------------------<<";
        cout << "\n\n\t\t--->>Thanks for Availing  Our Services <<---";
        return;


    }

    else if (choice == 'N' || choice == 'n') {
        return;

    }

}
// ---------==== Display Balance  ====------------
void Account::Display_Balance(double current_balance) {
    string t_id;
    int found = 0;
    fstream tfile;
    tfile.open("Account.txt", ios::in);
    if (!tfile) {
        cout << "file opening errors\n";
    }
    else {
        cout << "User ID:\t";
        cin >> t_id;

        while (tfile >> ID >> pincode >> holderName >> type >> startingBalance) {

            if (t_id == ID) {
                system("cls");
                cout << "\n\n\t User Balance\n";
                cout << "\n--------------------------------------------\n";
                cout << "Balance\t: " << startingBalance << "\n";
                cout << "\n----------------------------------------------";
                cout << "\npress any key to continue....";
                found++;
                _getch();
            }


        }
        if (found == 0) {
            cout << "record can't found";
        }
        tfile.close();
    }

}



// ---------====  Administrator  ====--------------
void Account::showAdministrator() {
p:
    system("cls");
    int choice;

    cout << "\n\n1----Create New Account.";
    cout << "\n2----Delete Existing Account.";
    cout << "\n3----Update Account Information.";
    cout << "\n4----Search for Account.";
    cout << "\n5----View Reports.";
    cout << "\n6.Exit";
    cout << "\n\nEnter your choice";
    cin >> choice;
    switch (choice) {
    case 1:
        this->createAccount();
        break;
    case 2:
        this->delRecord();
        break;
    case 3:
        this->updateRecord();
        break;
    case 4:
        this->SearchRecord();
        break;
    case 5:
        cout << "dnd";
    case 6:
        exit(0);
    default:
        cout << "\n\nInvalid choice please enter a valid naumber";
    }

    goto p;

}
// ---------====  Loading bar function  ====--------------
void Account::bar_Load() {
    char bar_front = 219, bar_back = 176;
    cout << endl;
    cout << "\t\t\t\t\t\t" << "Loading...\n" << endl;
    cout << "\t\t\t\t\t";
    for (int i = 0; i < 31; i++) {
        cout << bar_back;
    }
    cout << "\r";
    cout << "\t\t\t\t\t";
    for (int i = 0; i < 31; i++) {
        cout << bar_front;
        Sleep(150);
    }
    cout << "\r";
    cout << "\t\t\t\t\t";
    system("cls");
}
// ---------====  Date function used for creating time and date ====---------
void Account::date() {
    time_t now = time(0);

    // convert now to string form
    char* date_time;
#ifndef _WIN32
    date_time  = ctime(&now);
#endif // !WIN_32

    
    // current date and time on the current system
    cout << "\n\t\t|Date and Time : " << date_time << endl;
}
// ---------====  Create Account ====--------------
void Account::createAccount() {
p:
    system("cls");
    fstream file;
    string lg, hln, type;
    int pin, blnc;
    static  int account_number = 11;
    int account = account_number++;
    //-------------
    cout << "Login ID:\t";
    cin >> ID;
    system("cls");
    cout << "Pin Code:\t";
    cin >> pincode;
    system("cls");
    cout << "Holders Name::\t";
    cin >> holderName;
    system("cls");
    int attempts = 0;
    do {
        cout << "\nType (savings,current):\t";
        cin >> type;
        system("cls");
        if (type != "current" && type != "savings") {
            cout << "Invalid Input try gain\n";
            _getch();
            attempts++;
        }
    } while ((type != "current" && type != "savings") && attempts < 3);
    if (attempts == 3) {
        return;
    }
    cout << "Starting Balance:\t";
    cin >> startingBalance;

    file.open("Account.txt", ios::in);
    // checking file exist or not
    // if file not exist we will write and append data in file
    if (!file) {
        file.open("Account.txt", ios::app | ios::out);
        file << " " << ID << " " << pincode << " " << holderName << " " << type << " " << startingBalance << "\n";
        file.close();
    }
    // if file exist read data from file
    else {
        file >> lg >> pin >> hln >> type >> blnc;
    }
    // check ID exist or not
    while (file >> lg >> pin >> hln >> type >> blnc) {
        if (lg == ID) {
            cout << "user ID already existed\n";
            _getch();
            goto p;
        }

    }
    // if ID not exist then send user record
    file.close();
    file.open("Account.txt", ios::app | ios::out);
    file << " " << ID << " " << pincode << " " << holderName << " " << type << " " << startingBalance << "\n";
    file.close();
    cout << "\n\n\t\t--->>Account Created Sucessfully<<---";
    cout << "\n\tThe account number assigned is\t:" << account;
    _getch();


}
void Account::SearchRecord() {
    system("cls");
    string t_id;
    int found = 0;
    fstream file;
    file.open("Account.txt");
    if (!file) {
        cout << "File finding errors";
    }
    else {
        cout << "User ID:\t";
        cin >> t_id;
        file >> ID >> pincode >> holderName >> type >> startingBalance;
        while (file >> ID >> pincode >> holderName >> type >> startingBalance) {

            if (t_id == ID) {
                system("cls");
                cout << "\n\n\t Search User Record";
                cout << "\n-----------------------------------------------------------------------------------";
                cout << " \n\n\tLogin ID:\t" << ID << "\t\tPinCode\t  " << pincode << "\t\tHolderName\t " << holderName;
                cout << " \n\n\tType(Saving,Current):\t" << type << "\t\tBalance\t: " << startingBalance << "\n";
                cout << "\n-------------------------------------------------------------------------------------";
                cout << "\npress any key to continue....";

                found++;
                _getch();
            }
            if (found == 0) {
                cout << "record can't found";
            }

        }
        file.close();
    }


}
void Account::updateRecord() {
    //system("cls");
    fstream file, file1;
    string t_id, id, hl, t;
    int found = 0, p;
    cout << "\n\n\t edit user Record";
    file.open("Account.txt", ios::in);
    if (!file) {
        cout << "file opening errors\n";
    }
    else {
       
       cout << "User ID:\t";
             cin >> t_id;
        while (file >> ID >> pincode >> holderName >> type >> startingBalance) {
          
            if (t_id == ID) {
                system("cls");
                
                cout<<"\n\n\t Old Information";
                cout<<"\n------------------------------------------------------------------------------------";
                cout<<" \n\n\tLogin ID:\t"<<ID<<"\t\tPinCode\t  "<<pincode<<"\t\tHolderName\t "<<holderName;
                cout<<" \n\n\tType(Saving,Current):\t"<<type<<"\t\tBalance\t: "<<startingBalance<<"\n";
                cout<<"\n-------------------------------------------------------------------------------------";
                cout<<"\npress any key to continue....";
                found++;
                _getch();
                cout << "\n Login Id";
                cin >> id;
                cout << "\nPinCode";
                cin >> p;
                cout << "\nHolderName";
                cin >> hl;
                cout << "\ntype";
                cin >> t;
                cout << "\n\n\t Record update successfully";
                found++;
            }
            else {
                file << " " << id << " " << p << " " << hl << " " << t << " " << " " << startingBalance;

            }

            file.close();
           

            if (found == 0) {
                cout << "record can't found";
            }

        }

    }
}
void Account::delRecord(){
	string t_id;
	 cout << "Enter the User ID which you want to deleteD:\t";
     cin >> t_id;
     cout<<"Account Deleted successfully";
     _getch();
     
}
