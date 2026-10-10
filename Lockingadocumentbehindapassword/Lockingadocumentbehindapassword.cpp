// Lockingadocumentbehindapassword.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// This function shows the file on the screen
void displayFile(string filename) {
    ifstream myFile;
    myFile.open(filename);

    // check if the file is opened
    if (myFile.fail()) {
        cout << "I could not find that file." << endl;
        return;
    }

    string line;
    while (getline(myFile, line)) {
        cout << line << endl;
    }

    myFile.close();
}

int main() {
    string password;
    string guess;
    string answer;
    string filename;
    int tries = 0;

    //ask for the password
    cout << "Make a password: ";
    cin >> password;

    //ask if they want to see a document
    cout << "Do you want to view a document? (yes or no): ";
    cin >> answer;

    if (answer == "yes") {
        cout << "What is the name of the file? ";
        cin >> filename;

        //let them guess the password up to 3 times
        while (tries < 3) {
            cout << "Enter the password: ";
            cin >> guess;

            if (guess == password) {
                //password is right so show the file
                cout << "Correct" << endl;
                displayFile(filename);
                return 0;
            }
            else {
                tries = tries + 1;
                cout << "Wrong password." << endl;
            }
        }

        //used all 3 tries
        cout << "Too many wrong tries. You are locked out forever." << endl;
    }
    else {
        cout << "Goodbye" << endl;
    }

    return 0;
}
