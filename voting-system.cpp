#include <iostream>
#include <string>
#include <limits> // Include the header for numeric_limits
#include <conio.h>
#include <cstdlib> //Include the header for System


using namespace std;

// Structure for voter information
struct Voter {
    string nid;
    string name;
    string birth_date;
};

// Global variables to hold vote counts
int votes_candidate1 = 0;
int votes_candidate2 = 0;

// Function prototypes
void registerVoter();
void vote();
void viewWinner();
void adminPanel();
void viewVoters();
void viewVotes();

// Array to store registered voters 
const int MAX_VOTERS = 100;
Voter voters[MAX_VOTERS];
int numVoters = 0;

//main function
int main() {
    int choice;

    while (true) {
        system("cls");    //Include the header for System
        cout << "\n\n\n";
        cout << "\t****** WELCOME TO THE ONLINE VOTING SYSTEM ******\n\n";
        cout << "\t*************************************************\n\n\n";
        cout << "\t1. Register Voter\n";
        cout << "\t2. Vote\n";
        cout << "\t3. View Winner\n";
        cout << "\t4. Admin Panel\n";
        cout << "\t5. Exit\n\n";
        cout << "\tEnter your choice: ";
        cin >> choice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Include the header for numeric_limits

        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                vote();
                break;
            case 3:
                viewWinner();
                break;
            case 4:
                adminPanel();
                break;
            case 5:
                cout << "\n\tThank you for using the Voting System.\n";
                return 0;
            default:
                cout << "\n\tInvalid choice! Please try again.\n";
                break;
        }

        cout << "\n\tPress any key to continue...";
        _getch(); // Wait for user input
    }

    return 0;
}