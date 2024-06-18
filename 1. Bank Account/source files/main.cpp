/******************************

Title: Bank Accounts Project
Author: Alex Paquette
Date: 09/23/2021

*******************************/
#include <iostream>

using namespace std;

///////////BANK ACCOUNT//////////////////
class BankAccount{
    //overloaded operators
    friend ostream& operator<<(ostream& out, BankAccount &acct);
    friend istream& operator>>(istream& in, BankAccount &acct);
    protected:
        double balance = 0;
    private:
        int accountNum;
        static int nextAccountNum;
    public:
        //constructors
        BankAccount();
        BankAccount(int, double);

        //setters
        int setAccountNum(int);
        double setAccountBalance(double);

        //getters
        double getAccountBalance();
        int getAccountNum();

        //validation
        static bool isValidAccountNum(int);
        static bool isValidBalance(double);

        //other methods
        void deposit(double);
        void withdraw(double);

        //constants
        static constexpr double BALANCE_UPPER_LIMIT = 99999.99;
        static constexpr double BALANCE_LOWER_LIMIT = 0.0;
        static const int MAX_ACCOUNT = 9999;
        static const int MIN_ACCOUNT = 1000;
};
int BankAccount::nextAccountNum = 1000;
//Default constructor for bank account, sets the account number and increments the next account number
BankAccount::BankAccount(){
    this->accountNum = nextAccountNum;
    nextAccountNum++;
}
//All properties constructor for bank account, takes parameters for Account Number and Balance
//Validates values for Account Number and Balance
BankAccount::BankAccount(int NewAccountNum, double newBalance){
    if(isValidAccountNum(NewAccountNum)){
        this->accountNum = NewAccountNum;
    }else{
        accountNum = nextAccountNum;
        nextAccountNum++;
    }if(isValidBalance(newBalance)){
        this->balance = newBalance;
    }
}
//Sets new Account Number with parameter, validates parameter, and returns resulting account number
int BankAccount::setAccountNum (int NewAccountNum){
    if(isValidAccountNum(NewAccountNum))
        accountNum = NewAccountNum;
    return accountNum;
}
//Sets new Balance with parameter, validates parameter, and returns resulting balance
double BankAccount::setAccountBalance(double newAccountBalance){
    if(isValidBalance(newAccountBalance))
        balance = newAccountBalance;
    return balance;
}
//Returns the account number
int BankAccount::getAccountNum (){
    return accountNum;
}
//Returns the balance
double BankAccount::getAccountBalance(){
    return balance;
}
//Validates whether the given account number is within the lower/upper limits
bool BankAccount::isValidAccountNum(int accountNum){
    return (accountNum >= MIN_ACCOUNT && accountNum <= MAX_ACCOUNT);
}
//Validates whether the given balance is within the lower/upper limits
bool BankAccount::isValidBalance(double balanceNum){
    return (balanceNum >= BALANCE_LOWER_LIMIT && balanceNum <= BALANCE_UPPER_LIMIT);
}
//increments balance by deposited cash if resulting balance is successfully validated
void BankAccount::deposit(double cash){
    if(isValidBalance(balance+cash)&&cash>0)
        balance += cash;
}
//decrements balance by deposited cash if resulting balance is successfully validated
void BankAccount::withdraw(double cash){
    if(isValidBalance(balance-cash)&&cash>0)
        balance -= cash;
}
//Bank Account overloaded output operator
ostream& operator<<(ostream& out, BankAccount& acct){
    out <<"Bank Account Number: " << acct.getAccountNum() << "\tBalance: " << acct.getAccountBalance();
    return out;
}
//Bank Account overloaded input operator
istream& operator>>(istream& in, BankAccount& acct){
    double newBalance = 0;
    int newAccountNum = 0;

    cout << "Enter the new account number: ";
    cin >> newAccountNum;

    cout << "Enter the new balance: ";
    cin >> newBalance;

    acct.setAccountNum(newAccountNum);
    acct.setAccountBalance(newBalance);

    return in;
}

///////////SAVINGS ACCOUNT//////////////////
class SavingsAccount:public BankAccount{
    //overloaded operators
    friend ostream& operator<<(ostream& out, SavingsAccount &acct);
    friend istream& operator>>(istream& in, SavingsAccount &acct);
    private:
        double interestRate = MIN_INTEREST;
    public:
        //constructors
        SavingsAccount();
        SavingsAccount(int, double, double);

        //setters
        double setInterestRate(double);

        //getters
        double getInterestRate();

        //validation
        static bool isValidInterest(double);

        //other methods
        void applyInterest();

        //constants
        static constexpr double MAX_INTEREST = 0.04;
        static constexpr double MIN_INTEREST = 0.005;
};
//Default constructor for savings account, Calls the (parent) bank account constructor
SavingsAccount::SavingsAccount():BankAccount(){}
//All properties constructor for savings account, parameters are sent to the (parent) constructor,
//interest parameter is validated
SavingsAccount::SavingsAccount(int newAcctNum, double newBalance, double newInterestRate):BankAccount(newAcctNum, newBalance){
    if(isValidInterest(newInterestRate))
        interestRate = newInterestRate;
}
//Sets new interest rate with parameter, validates parameter, and returns resulting rate
double SavingsAccount::setInterestRate(double newInterestRate){
    if(isValidInterest(newInterestRate))
        interestRate = newInterestRate;
    return interestRate;
}
//returns the interest rate
double SavingsAccount::getInterestRate(){
    return interestRate;
}
//Validates whether the given interest rate is within the lower/upper limits
bool SavingsAccount::isValidInterest(double rate){
    return (rate <= MAX_INTEREST && rate >= MIN_INTEREST);
}
//Applies interest to the current balance. Does not allow balance to exceed max value
void SavingsAccount::applyInterest(){
    double newBalance = this->getAccountBalance();
    newBalance += (newBalance*interestRate/12);
    if(isValidBalance(newBalance))
        this->setAccountBalance(newBalance);
    else
        this->setAccountBalance(BALANCE_UPPER_LIMIT);
}
//Savings Account overloaded output operator
ostream& operator<<(ostream& out, SavingsAccount& acct){
    out <<"Savings Account Number: " << acct.getAccountNum() << "\tBalance: " << acct.getAccountBalance() << "\tInterest Rate: " << acct.getInterestRate();
    return out;
}
//Savings Account overloaded input operator
istream& operator>>(istream& in, SavingsAccount& acct){
    int newAccountNum = 0;
    double newBalance = 0;
    double newInterestRate = 0;

    cout << "Enter the new account number: ";
    cin >> newAccountNum;

    cout << "Enter the new balance: ";
    cin >> newBalance;

    cout << "Enter the new interest rate: ";
    cin >> newInterestRate;

    acct.setAccountNum(newAccountNum);
    acct.setAccountBalance(newBalance);
    acct.setInterestRate(newInterestRate);

    return in;
}

///////////CHEQUING ACCOUNT//////////////////
class ChequingsAccount:public BankAccount{
    //overloaded operators
    friend ostream& operator<<(ostream& out, ChequingsAccount &acct);
    friend istream& operator>>(istream& in, ChequingsAccount &acct);
    private:
        int transCount = 0;
    public:
        //constructors
        ChequingsAccount();
        ChequingsAccount(int, double);

        //getters
        int getTransactionCount();

        //other methods
        void cheque(double);
        void applyFees();
        void withdraw(double);

};
//Default constructor for chequings account, Calls the (parent) bank account constructor
ChequingsAccount::ChequingsAccount():BankAccount(){}
//All properties constructor for chequings account, parameters are sent to the (parent) constructor
ChequingsAccount::ChequingsAccount(int newAcctNum, double newBalance):BankAccount(newAcctNum, newBalance){}
//returns the number of transactions
int ChequingsAccount::getTransactionCount(){
    return transCount;
}
//withdraws the amount specified in the property
void ChequingsAccount::cheque(double chequeAmount){
    withdraw(chequeAmount);
}
//applies the transaction fees to the balance (can go negative)
//resets the transaction count to zero
void ChequingsAccount::applyFees(){
    balance -= 0.25*transCount;
    transCount = 0;
}
//withdraws the amount specified in the property and increases the number of transaction
void ChequingsAccount::withdraw(double cash){
    BankAccount::withdraw(cash);
    transCount++;
}
//Chequings Account overloaded output operator
ostream& operator<<(ostream& out, ChequingsAccount& acct){
    out <<"Chequings Account Number: " << acct.getAccountNum() << "\tBalance: " << acct.getAccountBalance() << "\tTransaction Count: " << acct.getTransactionCount();
    return out;
}
//Chequings Account overloaded input operator
istream& operator>>(istream& in, ChequingsAccount& acct){
    double newBalance = 0;
    int newAccountNum = 0;

    cout << "Enter the new account number: ";
    cin >> newAccountNum;

    cout << "Enter the new balance: ";
    cin >> newBalance;

    acct.setAccountNum(newAccountNum);
    acct.setAccountBalance(newBalance);

    return in;
}

///////////CUSTOMER//////////////////
class Customer {
    //overloaded operators
    friend ostream& operator<<(ostream& out, Customer &cust);
    friend istream& operator<<(istream& out, Customer &cust);
    private:
        string name;
        BankAccount* accounts;
        SavingsAccount* sAccounts;
        ChequingsAccount* cAccounts;
        int numAccts = 0;
        int numSAccts = 0;
        int numCAccts = 0;
    public:
        //constructors
        Customer();
        Customer (string, BankAccount[], int, SavingsAccount[], int, ChequingsAccount[], int);

        //setters
        string setName(string);
        void setAccounts(BankAccount[], int);
        void setSavingsAccounts(SavingsAccount[], int);
        void setChequingsAccounts(ChequingsAccount[], int);

        //getters
        string getName();
        BankAccount* getAccounts();
        SavingsAccount* getSavingsAccounts();
        ChequingsAccount* getChequingsAccounts();
        int getNumAccts();
        int getNumSavingsAccts();
        int getNumChequingsAccts();
};
//Default constructor for Customer class
//Sets customer name to default value and creates empty bank account array
Customer::Customer(){
    name = "NEW CUSTOMER";
    this->accounts = new BankAccount[0];
    this->sAccounts = new SavingsAccount[0];
    this->cAccounts = new ChequingsAccount[0];
}
//All properties constructor for Customer Class
//Takes and sets name, Bank Accounts, and Number of accounts parameters
Customer::Customer(string newName, BankAccount newAccounts[], int newNumAccts, SavingsAccount newSAccounts[], int newNumSAccts, ChequingsAccount newCAccounts[], int newNumCAccts){
    name = newName;
    accounts = newAccounts;
    sAccounts = newSAccounts;
    cAccounts = newCAccounts;
    numAccts = newNumAccts;
    numSAccts = newNumSAccts;
    numCAccts = newNumCAccts;
}
//takes and sets customer name
string Customer::setName(string newName){
    name = newName;
    return name;
}
//takes and sets Bank Accounts and Number of Accounts
void Customer::setAccounts(BankAccount* newAccounts, int newNumAccts){
    accounts = newAccounts;
    numAccts = newNumAccts;
}
//takes and sets Savings Accounts and Number of Accounts
void Customer::setSavingsAccounts(SavingsAccount* newSAccounts, int newNumSAccts){
    sAccounts = newSAccounts;
    numSAccts = newNumSAccts;
}
//takes and sets Chequing Accounts and Number of Accounts
void Customer::setChequingsAccounts(ChequingsAccount* newCAccounts, int newNumCAccts){
    cAccounts = newCAccounts;
    numCAccts = newNumCAccts;
}
//returns customer name
string Customer::getName(){
    return name;
}
//returns customer account(s)
BankAccount* Customer::getAccounts(){
    return accounts;
}
//returns customer savings account(s)
SavingsAccount* Customer::getSavingsAccounts(){
    return sAccounts;
}
//returns customer chequings account(s)
ChequingsAccount* Customer::getChequingsAccounts(){
    return cAccounts;
}
//returns number of customer accounts
int Customer::getNumAccts(){
    return numAccts;
}
//returns number of customer savings accounts
int Customer::getNumSavingsAccts(){
    return numSAccts;
}
//returns number of customer chequings accounts
int Customer::getNumChequingsAccts(){
    return numCAccts;
}
//Customer overloaded output operator
ostream& operator<<(ostream& out, Customer& cust){
    out <<"Customer Name: " << cust.getName() << "\tBank Accounts: " << cust.getNumAccts() << "\tSavings Accounts: " << cust.getNumSavingsAccts() << "\tChequings Accounts: " << cust.getNumChequingsAccts() << endl;
    int i = cust.getNumAccts();
    if (i != 0){
        out << endl <<"Bank Accounts" << endl;
        for(int x = 0; x < i; x++){
            out << cust.getAccounts()[x] << endl;
        }
    }
    i = cust.getNumSavingsAccts();
    if (i != 0){
        out << endl <<"Savings Accounts" << endl;
        for(int x = 0; x < i; x++){
            out << cust.getSavingsAccounts()[x] << endl;
        }
    }
    i = cust.getNumChequingsAccts();
    if (i != 0){
        out << endl <<"Chequings Accounts" << endl;
        for(int x = 0; x < i; x++){
            out << cust.getChequingsAccounts()[x] << endl;
        }
    }
    return out;
}
//Customer overloaded input operator
istream& operator>>(istream& in, Customer& cust){
    string newName = "NEW CUSTOMER";
    string createAccounts = "y";
    BankAccount* newAccounts = new BankAccount[0];
    SavingsAccount* newSavingsAccounts = new SavingsAccount[0];
    ChequingsAccount* newChequingsAccounts = new ChequingsAccount[0];
    int newNumAccts = 0, newNumSavingsAccts = 0, newNumChequingsAccts = 0;
    int uInput;


    cout << "Enter the customer's name: ";
    cin >> newName;

    cout << "Would you like to set an account?(y/n)?" << endl << "Enter: ";
    cin >> createAccounts;
    while(createAccounts == "y"){
        cout << "What type of account?" << endl << "1 - Bank Account\n2 - Savings Account\n3 - Chequings Account\nEnter: ";
        cin >>  uInput;
        switch(uInput){
            case 1:{
                newNumAccts++;
                BankAccount newAcct;
                cin >> newAcct;
                BankAccount* carryOver = new BankAccount[newNumAccts];
                for(int x=1; x<newNumAccts; x++){
                    carryOver[x-1] = newAccounts[x-1];
                }
                carryOver[newNumAccts-1] = newAcct;
                newAccounts = carryOver;
                break;
            }
            case 2:{
                newNumSavingsAccts++;
                SavingsAccount newSavingsAcct;
                cin >> newSavingsAcct;
                SavingsAccount* carrySOver = new SavingsAccount[newNumSavingsAccts];
                for(int x=1; x<newNumSavingsAccts; x++){
                    carrySOver[x-1] = newSavingsAccounts[x-1];
                }
                carrySOver[newNumSavingsAccts-1] = newSavingsAcct;
                newSavingsAccounts = carrySOver;
                break;
            }
            case 3:{
                newNumChequingsAccts++;
                ChequingsAccount newChequingsAcct;
                cin >> newChequingsAcct;
                ChequingsAccount* carryCOver = new ChequingsAccount[newNumChequingsAccts];
                for(int x=1; x<newNumChequingsAccts; x++){
                    carryCOver[x-1] = newChequingsAccounts[x-1];
                }
                carryCOver[newNumChequingsAccts-1] = newChequingsAcct;
                newChequingsAccounts = carryCOver;
                break;
            }
            default:
                cout << "Account creation failed" << endl;
                break;
        }
        cout << "Would you like to set another account?(y/n)?" << endl << "Enter: ";
        cin >> createAccounts;
    }

    cust.setName(newName);
    cust.setAccounts(newAccounts, newNumAccts);
    cust.setSavingsAccounts(newSavingsAccounts, newNumSavingsAccts);
    cust.setChequingsAccounts(newChequingsAccounts, newNumChequingsAccts);

    return in;
}

int main(){
    cout << "Test the Bank Account Methods:"<<endl;
    //Test Bank Account Methods
    BankAccount bAccts[] = {BankAccount(), BankAccount(2000, 550.50)};          //test default and all-properties constructors
    bAccts[0].setAccountNum(1010);                                              //test setAccountNum();
    bAccts[0].setAccountBalance(10000);                                         //test setAccountBalance();
    bAccts[0].deposit(1000);                                                    //test deposit();
    bAccts[0].withdraw(2000);                                                   //test withdraw();
    cout << "Account Number: " << bAccts[0].getAccountNum() << endl;            //test getAccountNum();
    cout << "Account Balance: " << bAccts[0].getAccountBalance() << endl;       //test getAccountBalance();
    cin >> bAccts[0];                                                           //test input operator
    cout << bAccts[0] << endl;                                                  //test output operator

    cout << endl<<"Test the Savings Account Methods:"<<endl;
    //Test Savings Account Methods
    SavingsAccount sAccts[] = {SavingsAccount(), SavingsAccount(2001, 0.03, 560.60)};//test default and all-properties constructors
    sAccts[0].setInterestRate(0.03);                                            //test setInterestRate();
    cout << "Interest Rate: " << sAccts[0].getInterestRate() << endl;           //test getInterestRate();
    sAccts[0].applyInterest();                                                  //test applyInterest();
    cout << sAccts[0] << endl;                                                  //test output operator
    cin >> sAccts[0];                                                           //test input operator
    cout << sAccts[0] << endl;

    cout << endl<<"Test the Chequings Account Methods:"<<endl;
    //Test Chequings Account Methods
    ChequingsAccount cAccts[] = {ChequingsAccount(), ChequingsAccount(2003, 570.70)};//test default and all-properties constructors
    cAccts[1].cheque(100);                                                      //test cheque();
    cAccts[1].withdraw(100);                                                    //test withdraw(); - this function is overloaded for Chequings to allow for transaction  count to increase
    cout <<"Number of Transactions: "<< cAccts[1].getTransactionCount() << endl;//test getTransactionCount();
    cout << cAccts[1] << endl;                                                  //test the output operator
    cAccts[1].applyFees();                                                      //test applyFees();
    cout << cAccts[1] << endl;
    cin >> cAccts[0];                                                           //test the input operator
    cout << cAccts[0] << endl;

    cout << endl<<"Test the Customer Class Methods:"<<endl;
    //Test Chequings Account Methods
    Customer custs[] = {Customer(), Customer("Alex", bAccts, 2, sAccts, 2, cAccts, 2), Customer()};//test default and all-properties constructors
    cout << "Customer with no accounts" << endl << custs[0] << endl;            //test the output operator
    custs[0].setName("Jim");                                                    //test setName();
    custs[0].setAccounts(bAccts, 2);                                            //test setAccounts();
    custs[0].setSavingsAccounts(sAccts, 2);                                     //test setSavingsAccounts();
    custs[0].setChequingsAccounts(cAccts, 2);                                   //test setChequingsAccounts();
    cout << "Name: " << custs[0].getName() << endl;                             //test getName();
    cout << "Number of Bank Accounts: " << custs[0].getNumAccts() << endl;      //test getNumAccts();
    cout << "Number of Savings Accounts: " << custs[0].getNumSavingsAccts() << endl;//test getNumSavingsAccts();
    cout << "Number of Chequings Accounts: " << custs[0].getNumChequingsAccts() << endl << endl;//test getNumChequingsAccts();
    cout << "Bank Accounts" << endl << custs[0].getAccounts()[0] << endl << custs[0].getAccounts()[1] << endl << endl;//test getAccounts();
    cout << "Savings Accounts" << endl << custs[0].getSavingsAccounts()[0] << endl << custs[0].getSavingsAccounts()[1] << endl << endl;//test getSavingsAccounts();
    cout << "Chequings Accounts" << endl << custs[0].getChequingsAccounts()[0] << endl << custs[0].getChequingsAccounts()[1] << endl << endl;//test getChequingsAccounts();
    cout << custs[1] << endl;                                                   //test output operator
    cin >> custs[2];                                                            //test input operator
    cout << custs[2] << endl;

    return 0;
}
