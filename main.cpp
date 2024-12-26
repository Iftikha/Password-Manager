#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

void cinInt(int* inte){
    while(!(cin>>*inte)){
        cin.clear();
        cout<<"Invalid Input type!\nRe-Enter: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

class password{
    private:
    public:
        int PassID;
        string Passlink;
        string PassAcc;
        string password;
        string genPassword(int lenght, bool incNum, bool incUpper, bool incVIP){
            string genPass = "";
            string lowercase = "abcdefghijklmnopqrstuvwxyz";
            string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string specialsChars = "!@#$%^&*()";
            string numbers = "1234567890";

            string characters = lowercase;
            if(incNum) characters += numbers;
            if(incUpper) characters += uppercase;
            if(incVIP) characters += specialsChars;

            for(int i = 0; i <= lenght; i++){
                genPass = characters[rand() % characters.length()];
            }

            return genPass;
        }

};

vector<password> Passwords;

int nextID = 1;

int menu(){
    int choice;
    cout<<"Password Manager!";
    cout<<"\n\t 1. Add Password Record";
    cout<<"\n\t 2. View Password Record";
    cout<<"\n\t 3. Edit Password Record";
    cout<<"\n\t 4. Delete Password Record";
    cout<<"\n\t 5. Exit";
    cout<<"\n\t Enter your choice: ";
    cinInt(&choice);
    return choice;
}

int main() {
    
    // Your code here
    return 0;
}