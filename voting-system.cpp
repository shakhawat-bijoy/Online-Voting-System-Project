#include <iostream>
#include <string>
#include <limits>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <sstream> // Include for string stream
#include <iomanip> // Include for date formatting

using namespace std;

// Structure for voter information
struct Voter {
    string nid;
    string name;
    string birth_date;
};

// Structure for candidate information
struct Candidate {
    string id;
    string name;
};

// Global variables to hold vote counts
int votes[100];
Candidate candidates[100];
int numCandidates = 0;

// Global variables for voters
Voter voters[100];
int numVoters = 0;

// Function prototypes
void registerVoter();
void registerCandidate();
void vote();
void viewWinner();
void adminPanel();
void viewVoters();
void viewVotes();
void viewCandidates();
void loadVotersFromFile();
void saveVotersToFile();
void loadCandidatesFromFile();
void saveCandidatesToFile();
bool isValidDate(const string &date);

int main() {
    // Load voters and candidates from file at the start
    loadVotersFromFile();
    loadCandidatesFromFile();

    int choice;

    while (true) {
        cout << "\n\n\n";
        cout << "\t****** WELCOME TO THE ONLINE VOTING SYSTEM ******\n\n";
        cout << "\t*************************************************\n\n\n";
        cout << "\t1. Register Voter\n";
        cout << "\t2. Register Candidate\n";
        cout << "\t3. Vote\n";
        cout << "\t4. View Winner\n";
        cout << "\t5. Admin Panel\n";
        cout << "\t6. Exit\n\n";
        cout << "\tEnter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear buffer

        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                registerCandidate();
                break;
            case 3:
                vote();
                break;
            case 4:
                viewWinner();
                break;
            case 5:
                adminPanel();
                break;
            case 6:
                saveVotersToFile();
                saveCandidatesToFile();
                cout << "\n\tThank you for using the Voting System.\n";
                return 0;
            default:
                cout << "\n\tInvalid choice! Please try again.\n";
                break;
        }

        cout << "\n\tPress any key to continue...";
        _getch();
    }

    return 0;
}

// Function to load voters from file
void loadVotersFromFile() {
    ifstream file("voters.txt");
    if (file.is_open()) {
        while (file >> voters[numVoters].nid >> voters[numVoters].name >> voters[numVoters].birth_date) {
            numVoters++;
        }
        file.close();
    }
}

// Function to save voters to file
void saveVotersToFile() {
    ofstream file("voters.txt");
    if (file.is_open()) {
        for (int i = 0; i < numVoters; i++) {
            file << voters[i].nid << " " << voters[i].name << " " << voters[i].birth_date << endl;
        }
        file.close();
    }
}

// Function to load candidates from file
void loadCandidatesFromFile() {
    ifstream file("candidates.txt");
    if (file.is_open()) {
        while (file >> candidates[numCandidates].id >> candidates[numCandidates].name) {
            numCandidates++;
        }
        file.close();
    }
}

// Function to save candidates to file
void saveCandidatesToFile() {
    ofstream file("candidates.txt");
    if (file.is_open()) {
        for (int i = 0; i < numCandidates; i++) {
            file << candidates[i].id << " " << candidates[i].name << endl;
        }
        file.close();
    }
}

// Function to check if the date is valid
bool isValidDate(const string &date) {
    if (date.size() != 10 || date[2] != '-' || date[5] != '-') {
        return false;
    }

    int day, month, year;
    stringstream ss(date);
    ss >> setw(2) >> day;
    ss.ignore();
    ss >> setw(2) >> month;
    ss.ignore();
    ss >> setw(4) >> year;

    if (month < 1 || month > 12 || year < 1900 || year > 2024) {
        return false;
    }

    int daysInMonth[] = { 31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

// Function to register a new voter
void registerVoter() {
    cout << "\n\n\n";
    cout << "\t****** REGISTER VOTER ******\n\n";

    Voter voter;

    cout << "\tEnter NID: ";
    getline(cin, voter.nid);

    cout << "\tEnter Name: ";
    getline(cin, voter.name);

    int invalidCount = 0;

    while (invalidCount < 5) {
        cout << "\tEnter Birth Date (dd-mm-yyyy): ";
        getline(cin, voter.birth_date);

        if (isValidDate(voter.birth_date)) {
            break;
        } else {
            invalidCount++;
            cout << "\tInvalid date format or date does not exist. Please try again.\n";
            if (invalidCount == 5) {
                cout << "\n\tToo many invalid attempts. Returning to the main menu.\n";
                return;
            }
        }
    }

    if (numVoters < 100) {
        voters[numVoters++] = voter;
        cout << "\n\tVoter registered successfully!\n";
    } else {
        cout << "\n\tMaximum number of voters reached!\n";
    }
}

// Function to register a new candidate
void registerCandidate() {
    cout << "\n\n\n";
    cout << "\t****** REGISTER CANDIDATE ******\n\n";

    Candidate candidate;

    cout << "\tEnter Candidate ID: ";
    getline(cin, candidate.id);

    cout << "\tEnter Candidate Name: ";
    getline(cin, candidate.name);

    if (numCandidates < 100) {
        candidates[numCandidates++] = candidate;
        votes[numCandidates - 1] = 0;
        cout << "\n\tCandidate registered successfully!\n";
    } else {
        cout << "\n\tMaximum number of candidates reached!\n";
    }
}

// Function to allow voter to vote
void vote() {
    cout << "\n\n\n";
    cout << "\t****** VOTE ******\n\n";

    string nid;
    string name;
    string birth_date;

    cout << "\tEnter NID: ";
    getline(cin, nid);

    cout << "\tEnter Name: ";
    getline(cin, name);

    cout << "\tEnter Birth Date (dd-mm-yyyy): ";
    getline(cin, birth_date);

    bool registered = false;
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].nid == nid && voters[i].name == name && voters[i].birth_date == birth_date) {
            registered = true;
            break;
        }
    }

    if (registered) {
        cout << "\n\tYou are eligible to vote.\n"<<endl;
        cout << "\tSelect a candidate to vote for:\n";
        for (int i = 0; i < numCandidates; i++) {
            cout << "\t" << candidates[i].id << ". " << candidates[i].name << "\n";
        }
        cout << "\tEnter your choice: ";

        int choice;
        cin >> choice;

        if (choice > 0 && choice <= numCandidates) {
            votes[choice - 1]++;
            cout << "\n\tVote cast successfully!\n";
        } else {
            cout << "\n\tInvalid choice! Vote not cast.\n";
        }
    } else {
        cout << "\n\tYou are not registered as a voter.\n";
    }
}

// Function to view the winner
void viewWinner() {
    cout << "\n\n\n";
    cout << "\t****** VIEW WINNER ******\n\n";

    int winnerIndex = 0;
    int maxVotes = votes[0];

    for (int i = 1; i < numCandidates; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    cout << "\tWinner is " << candidates[winnerIndex].name << " with " << maxVotes << " votes!\n";
}

// Function to display admin panel
void adminPanel() {
    cout << "\n\n\n";
    cout << "\t****** ADMIN PANEL ******\n\n";
    cout << "\tEnter admin password: ";

    string password;
    char ch;
    password.clear();

    // Hiding password input
while (true) {
    ch = _getch();
    if (ch == '\r') break;
    if (ch == '\b') {
        if (!password.empty()) {
            password.resize(password.size() - 1);
            cout << "\b \b";
        }
    } else {
        password += ch;
        cout << '*';
    }
}
    cout << endl;

    if (password == "admin123") {
        int choice;
        do {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\n";
            cout << "\t1. View Voters\n";
            cout << "\t2. View Candidates\n";
            cout << "\t3. View Votes\n";
            cout << "\t4. Back to Main Menu\n";
            cout << "\n\n";
            cout << "\tEnter your choice: ";

            if (!(cin >> choice)) {
                cout << "\n\tInvalid input! Please enter a number.\n";
                choice = 0;
            }

            switch (choice) {
                case 1:
                    viewVoters();
                    break;
                case 2:
                    viewCandidates();
                    break;
                case 3:
                    viewVotes();
                    break;
                case 4:
                    return;
                default:
                    cout << "\n\tInvalid choice!\n";
                    break;
            }
        } while (true);
    } else {
        cout << "\n\tIncorrect password! Access denied.\n";
    }
}

// Function to view registered voters
void viewVoters() {
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

// Function to view candidates
void viewCandidates() {
    cout << "\n\n\n";
    cout << "\t****** VIEW CANDIDATES ******\n\n";

    if (numCandidates == 0) {
        cout << "\tNo candidates to display.\n";
    } else {
        cout << "\tRegistered Candidates:\n";
        cout << "\t---------------------\n";
        for (int i = 0; i < numCandidates; ++i) {
            cout << "\tID: " << candidates[i].id << ", Name: " << candidates[i].name << endl;
        }
    }
}

// Function to view voting results
void viewVotes() {
    cout << "\n\n\n";
    cout << "\t****** VIEW VOTES ******\n\n";

    for (int i = 0; i < numCandidates; i++) {
        cout << "\t" << candidates[i].name << " received " << votes[i] << " votes.\n";
    }
}
