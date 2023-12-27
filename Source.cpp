#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Charity {
    string name;
    int totalDonation;
};

// Function to display charity names with numbers
void displayCharities(const vector<Charity>& charities) {
    cout << "Choose a charity:\n";
    for (size_t i = 0; i < charities.size(); ++i) {
        cout << i + 1 << ". " << charities[i].name << endl;
    }
}

int main() {
    vector<Charity> charities;
    const int NUM_CHARITIES = 3;

    // Task 1 - Set up the donation system
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        Charity newCharity;
        cout << "Enter name of Charity " << i + 1 << ": ";
        getline(cin, newCharity.name);
        newCharity.totalDonation = 0;
        charities.push_back(newCharity);
    }

    int choice;
    double shoppingBill;
    int chosenCharity;
    double donation;
    int grandTotal = 0;

    // Task 2 - Record and total each donation
    while (true) {
        displayCharities(charities);
        cout << "Enter charity choice (1, 2, 3) or -1 to show totals: ";
        cin >> choice;

        if (choice == -1) {
            // Task 3 - Show the totals so far
            cout << "Charity Totals:\n";
            sort(charities.begin(), charities.end(), [](const Charity& a, const Charity& b) {
                return a.totalDonation > b.totalDonation;
                });

            for (const auto& charity : charities) {
                cout << charity.name << ": $" << charity.totalDonation << endl;
                grandTotal += charity.totalDonation;
            }

            cout << "GRAND TOTAL DONATED TO CHARITY: $" << grandTotal << endl;
            break;
        }
        else if (choice >= 1 && choice <= NUM_CHARITIES) {
            chosenCharity = choice - 1;

            cout << "Enter shopping bill amount: $";
            cin >> shoppingBill;

            // Calculate donation
            donation = shoppingBill * 0.01;

            // Update total donation for the chosen charity
            charities[chosenCharity].totalDonation += donation;

            // Output donation details
            cout << "Donated $" << donation << " to " << charities[chosenCharity].name << endl;
        }
        else {
            cout << "Invalid choice. Please enter 1, 2, 3 or -1 only." << endl;
        }
    }

    return 0;
}

