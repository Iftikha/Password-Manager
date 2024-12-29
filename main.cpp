#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>

using namespace std;

void cinInt(int* inte){
    while(!(cin>>*inte)){
        cin.clear();
        cout<<"Invalid Input type!\nRe-Enter: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

struct password{
    int passID;
    string Passlink;
    string PassAcc;
    string password;
};



string genPassword(int length, bool incNum, bool incUpper, bool incVIP){
	
    string genPass = "";
    
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    string specialsChars = "!@#$%^&*()";
    string numbers = "1234567890";
    
    string characters = lowercase;
    if(incNum) characters += numbers;
    
    if(incUpper) characters += uppercase;
    if(incVIP) characters += specialsChars;
    
    for(int i = 0; i < length; i++){
        genPass += characters[rand() % characters.length()];
    }
    
    return genPass;
}

ofstream printPass("passwords/password.txt", ios::app);

ifstream getPass("passwords/password.txt");

vector<password> passwords;

int nextID = 1;

int menu(){
    int choice;
    cout<<"Password Manager!";
    cout<<"\n\t 1. Add Password Record";
    cout<<"\n\t 2. View Password Record";
    cout<<"\n\t 4. Delete Password Record";
    cout<<"\n\t 5. Exit";
    cout<<"\n\t Enter your choice: ";
    cinInt(&choice);
    return choice;
}


void addPassword() {
    if (!printPass.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
    }
    password newPassword;
    newPassword.passID = nextID++;
    
    cout<<"Password Link: ";
    getline(cin, newPassword.Passlink);

    cout<<"Password Account: ";
    getline(cin, newPassword.PassAcc);

    cout<<"Enter Password (Enter 0 to generate password!): ";
    getline(cin,newPassword.password);

    if(newPassword.password == "0"){
        int len, incnum, incupp, incvip;
        cout<<"Password Length: ";
        cinInt(&len);

        cout<<"Include numbers (1 for yes and 0 for no): ";
        cinInt(&incnum);

        cout<<"Include Uppercase (1 for yes and 0 no): ";
        cinInt(&incupp);

        cout<<"Inlcude special characters (1 for yes and 0 for no): ";
        cinInt(&incvip);

        cin.ignore();

        newPassword.password = genPassword(len, incnum, incupp, incvip);
        cout<<"Generated Password: ";
        cout<<newPassword.password;

    }

     printPass << left<< setw(5) << newPassword.passID
              << setw(60) << newPassword.Passlink
              << setw(60) << newPassword.PassAcc
              << setw(60) << newPassword.password
              << endl;
    printPass << setfill('-')<<setw(5)<<""
                             <<setw(60)<<""
    						 <<setw(60)<<""
    						 <<setw(60)<<""
    						 <<endl;
    printPass<<setfill(' ');

    cout << "\nPassword Saved!" << endl;
    return;


}

void getPasswords(){
	
	password line;
	
	if(!getPass.is_open()){
		cerr<<"Error: Couldn't open the file!";
		return;

	}	
	for(int i = 1; getPass >> line.passID; i++ ){
		getPass >> line.Passlink;
        getPass >> line.PassAcc;
        getPass >> line.password;

        passwords.push_back(line);
	}
	for(int i = 1; i < passwords.size(); i+=2){
        cout<<passwords.at(i).passID<<"\t"<<passwords.at(i).Passlink << "\t" << passwords.at(i).PassAcc << "\t"<<passwords.at(i).password<<endl;
    }
}

void viewPass(){
	
}

void deletePass() {
    if (!getPass.is_open()) {
        cerr << "Error: Could not open the file for reading!" << endl;
        return;
    }

    password inPassword;

    for(int i = 0; getPass >> inPassword.passID; i++){
        getPass >> inPassword.Passlink;
        getPass>> inPassword.PassAcc;
        getPass >> inPassword.password;
    }



    
}


int main() {
	getPasswords();
    viewPass();
    addPassword();
    // Your code here
    return 0;
}