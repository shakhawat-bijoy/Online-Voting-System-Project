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

// Array to store registered voters (simulated data)
const int MAX_VOTERS = 100;
Voter voters[MAX_VOTERS];
int numVoters = 0;

int main() {
    int choice;

    while (true) {
        system("cls");
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

// Function to register a new voter
void registerVoter() {
    system("cls");
    cout << "\n\n\n";
    cout << "\t****** REGISTER VOTER ******\n\n";

    Voter voter;

    cout << "\tEnter NID: ";
    cin.ignore();
    getline(cin, voter.nid);

    cout << "\tEnter Name: ";
    getline(cin, voter.name);

    cout << "\tEnter Birth Date (dd-mm-yyyy): ";
    getline(cin, voter.birth_date);

    // Store voter information in array (simulating database or file storage)
    if (numVoters < MAX_VOTERS) {
        voters[numVoters++] = voter;
        cout << "\n\tVoter registered successfully!\n";
    } else {
        cout << "\n\tMaximum number of voters reached!\n";
    }
}

// Function to allow voter to vote
void vote() {
    system("cls");
    cout << "\n\n\n";
    cout << "\t****** VOTE ******\n\n";

    string nid;
    string name;
    string birth_date;

    cout << "\tEnter NID: ";
    cin.ignore();
    getline(cin, nid);

    cout << "\tEnter Name: ";
    getline(cin, name);

    cout << "\tEnter Birth Date (dd-mm-yyyy): ";
    getline(cin, birth_date);

    // Check if the voter is registered
    bool registered = false;
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].nid == nid && voters[i].name == name && voters[i].birth_date == birth_date) {
            registered = true;
            break;
        }
    }

    if (registered) {
        cout << "\n\tYou are eligible to vote.\n";
        cout << "\tSelect a candidate to vote for:\n";
        cout << "\t1. Candidate 1\n";
        cout << "\t2. Candidate 2\n";
        cout << "\tEnter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                votes_candidate1++;
                cout << "\n\tYou voted for Candidate 1.\n";
                break;
            case 2:
                votes_candidate2++;
                cout << "\n\tYou voted for Candidate 2.\n";
                break;
            default:
                cout << "\n\tInvalid choice!\n";
                break;
        }
    } else {
        cout << "\n\tYou are not registered as a voter.\n";
    }
}


// Function to view the winner
void viewWinner() {
    system("cls");
    cout << "\n\n\n";
    cout << "\t****** VIEW WINNER ******\n\n";

    if (votes_candidate1 > votes_candidate2) {
        cout << "\tCandidate 1 is the winner with " << votes_candidate1 << " votes!\n";
    } else if (votes_candidate2 > votes_candidate1) {
        cout << "\tCandidate 2 is the winner with " << votes_candidate2 << " votes!\n";
    } else {
        cout << "\tIt's a tie!\n";
    }
}

// Function to display admin panel
void adminPanel() {
    system("cls");
    cout << "\n\n\n";
    cout << "\t****** ADMIN PANEL ******\n\n";
    cout << "\tEnter admin password: ";

    string password;
    cin >> password;

    if (password == "admin123") {
        int choice;
        do {
            // Clear any previous error flags and flush the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\n";
            cout << "\t1. View Voters\n";

            cout << "\t2. View Votes\n";

            cout << "\t3. Back to Main Menu\n";
            cout << "\n\n";
            cout << "\tEnter your choice: ";

            // Check if the input is a number
            if (!(cin >> choice)) {
                cout << "\n\tInvalid input! Please enter a number.\n";
                choice = 0; // Reset choice to handle invalid input
            }

            switch (choice) {
                case 1:
                    viewVoters();
                    break;
                case 2:
                    viewVotes();

                    break;
                case 3:
                    return; // Exit admin panel and return to main menu
                default:
                    cout << "\n\tInvalid choice!\n";
                    break;
            }
        } while (true); // Loop until user selects to go back to main menu
    } else {
        cout << "\n\tIncorrect password! Access denied.\n";
    }
}

// Function to view registered voters
void viewVoters() {
    system("cls");
    cout << "\n\n\n";
    cout << "\t****** VIEW VOTERS ******\n\n";

    if (numVoters == 0) {
        cout << "\tNo voters to display.\n";
    } else {
        cout << "\tRegistered Voters:\n";
        cout << "\t------------------\n";
        for (int i = 0; i < numVoters; ++i) {
            cout << "\tNID: " << voters[i].nid << ", Name: " << voters[i].name << ", Birth Date: " << voters[i].birth_date << endl;
        }
    }
}

// Function to view voting results
void viewVotes() {
    system("cls");
    cout << "\n\n\n";
    cout << "\t****** VIEW VOTES ******\n\n";

    cout << "\tCandidate 1 received " << votes_candidate1 << " votes.\n";
    cout << "\tCandidate 2 received " << votes_candidate2 << " votes.\n";
}
