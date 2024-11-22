#include<iostream>
#include<cstring>
using namespace std;

struct charity {
    int donation_id;
    string donor_name;
    int donation_amount;
    struct charity *next;
};

class donation_info {
    private: 
    charity *head; 

    public:
    donation_info() {
       head = NULL;
    }

    void addinfo(int id, int amount, string name) {
        charity *temp = new charity;
        temp->donation_id = id;
        temp->donation_amount = amount;
        temp->donor_name = name;
        temp->next = head;
        head = temp;
    }

    void display() {
        charity *temp = head;
        if (head == NULL) {
            cout << "\nThere is no data available." << endl;
            return;
        }
        while (temp != NULL) {
            cout << "\nDonor Name: " << temp->donor_name;
            cout << "\nDonation ID: " << temp->donation_id;
            cout << "\nDonation Amount: " << temp->donation_amount << endl;
            temp = temp->next;
        }
    }

    void updatedata(int id, int amount, string name) {
        charity* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (id == temp->donation_id) {
                temp->donor_name = name;
                temp->donation_amount = amount;
                found = true;
                cout << "\nData updated successfully." << endl;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "\nInvalid donor ID." << endl;
        }
    }

    void remove(int id) {
        charity* temp = head;
        charity* prev = NULL;
        
        while (temp != NULL && temp->donation_id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "\nDonor not found." << endl;
            return;
        }

        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "\nInformation deleted successfully." << endl;
    }

    void search(int id) {
        charity* temp = head;
        bool found = false;
        
        while (temp != NULL) {
            if (temp->donation_id == id) {
                cout << "\nDonor found:";
                cout << "\nDonor Name: " << temp->donor_name;
                cout << "\nDonation ID: " << temp->donation_id;
                cout << "\nDonation Amount: " << temp->donation_amount << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        
        if (!found) {
            cout << "\nDonor not found." << endl;
        }
    }
};

int main() {
    donation_info obj1;
    int ch, id, amount;
    string name;

    do {
        cout << "\nEnter your choice\n1. Insert donation info \n2. Display \n3. Update \n4. Remove \n5. Search \n6. Exit:\t";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter Donor Name:\t";
                cin >> name;
                cout << "\nEnter Donation ID:\t";
                cin >> id;
                cout << "\nEnter Donation Amount:\t";
                cin >> amount;
                obj1.addinfo(id, amount, name);
                break;

            case 2:
                obj1.display();
                break;

            case 3:
                cout << "\nEnter Donation ID to update:\t";
                cin >> id;
                cout << "\nEnter New Donor Name:\t";
                cin >> name;
                cout << "\nEnter New Donation Amount:\t";
                cin >> amount;
                obj1.updatedata(id, amount, name);
                break;

            case 4:
                cout << "\nEnter Donation ID to remove:\t";
                cin >> id;
                obj1.remove(id);
                break;

            case 5:
                cout << "\nEnter Donation ID to search:\t";
                cin >> id;
                obj1.search(id);
                break;

            case 6:
                cout << "\nExiting program." << endl;
                break;

            default:
                cout << "\nInvalid choice" << endl;
                break;
        }
    } while (ch != 6);

    return 0;
}
