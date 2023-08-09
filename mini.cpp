#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>

using namespace std;

struct Item {
    string name;
    float price;
};

class SuperMarketBillingSystem {
private:
    unordered_map<int, Item> inventory;

public:
    SuperMarketBillingSystem() {
        // Initialize the inventory with some sample items
        inventory = {
            {1001, {"Apple", 1.0}},
            {1002, {"Banana", 0.5}},
            {1003, {"Orange", 0.8}},
            {1004, {"Mango", 2.0}},
            {1005, {"Grapes", 1.5}}
        };
    }

    void addItem(int itemNo, const string& itemName, float price) {
        Item item = {itemName, price};
        inventory[itemNo] = item;
    }

    void removeItem(int itemNo) {
        inventory.erase(itemNo);
    }

    void displayItems() {
        cout << "Item No\t\tItem Name\t\tPrice" << endl;
        cout << "------------------------------------------" << endl;
        for (const auto& pair : inventory) {
            int itemNo = pair.first;
            const Item& item = pair.second;
            cout << itemNo << "\t\t" << item.name << "\t\t\t" << item.price << endl;
        }
    }

    void generateBill() {
        int itemNo;
        float total = 0.0;

        cout << "=== BILLING ===" << endl;
        cout << "Enter item number (0 to exit): ";
        cin >> itemNo;

        while (itemNo != 0) {
            if (inventory.find(itemNo) != inventory.end()) {
                const Item& item = inventory[itemNo];
                cout << "Item: " << item.name << endl;
                cout << "Price: " << item.price << endl;
                total += item.price;
            } else {
                cout << "Invalid item number!" << endl;
            }

            cout << "Enter item number (0 to exit): ";
            cin >> itemNo;
        }

        cout << "-------------------------" << endl;
        cout << "Total: " << total << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    SuperMarketBillingSystem billingSystem;

    // Add more items to the inventory if needed
    billingSystem.addItem(1006, "Pineapple", 2.5);
    billingSystem.addItem(1007, "Watermelon", 3.0);

    int choice;
    do {
        cout << "=== SUPER MARKET BILLING SYSTEM ===" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Remove Item" << endl;
        cout << "3. Display Items" << endl;
        cout << "4. Generate Bill" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int itemNo;
                string itemName;
                float price;

                cout << "Enter item number: ";
                cin >> itemNo;
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, itemName);
                cout << "Enter price: ";
                cin >> price;

                billingSystem.addItem(itemNo, itemName, price);
                cout << "Item added successfully!" << endl;
                break;
            }
            case 2: {
                int itemNo;

                cout << "Enter item number to remove: ";
                cin >> itemNo;

                billingSystem.removeItem(itemNo);
                cout << "Item removed successfully!" << endl;
                break;
            }
            case 3:
                billingSystem.displayItems();
                break;
            case 4:
                billingSystem.generateBill();
                break;
            case 5:
                cout << "Exiting program... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}

