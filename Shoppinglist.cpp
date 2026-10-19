#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Class representing a single item in the shopping list
class Item {
private:
    string name;
    int quantity;
    double price;

public:
    // Constructor
    Item(string itemName, int itemQty, double itemPrice) {
        name = itemName;
        quantity = itemQty;
        price = itemPrice;
    }

    // Getter for Item Name
    string getName() const {
        return name;
    }

    // Display details of a single item
    void displayItem() const {
        cout << "- " << name << " | Qty: " << quantity << " | Price: $" << price << "\n";
    }
};

// Class representing the Shopping List Management System
class ShoppingList {
private:
    vector<Item> items; // Dynamic array to store items

public:
    // 1. Add an item to the list
    void addItem() {
        string name;
        int qty;
        double price;

        cout << "\nEnter Item Name: ";
        cin.ignore(); // Clear buffer
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> qty;
        cout << "Enter Price per unit: ";
        cin >> price;

        Item newItem(name, qty, price);
        items.push_back(newItem);
        cout << "Item successfully added to the list!\n";
    }

    // 2. Remove an item from the list by its name
    void removeItem() {
        if (items.empty()) {
            cout << "\nYour shopping list is empty! Nothing to remove.\n";
            return;
        }

        string targetName;
        cout << "\nEnter the name of the item to remove: ";
        cin.ignore();
        getline(cin, targetName);

        bool found = false;
        // Iterate and remove match
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getName() == targetName) {
                items.erase(it);
                cout << "Item '" << targetName << "' has been removed from the list.\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item not found in the shopping list.\n";
        }
    }

    // 3. Search for a specific item in the list
    void searchItem() const {
        if (items.empty()) {
            cout << "\nThe shopping list is empty.\n";
            return;
        }

        string targetName;
        cout << "\nEnter the name of the item to search for: ";
        cin.ignore();
        getline(cin, targetName);

        bool found = false;
        for (const auto& item : items) {
            if (item.getName() == targetName) {
                cout << "\nItem Found:\n";
                item.displayItem();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item '" << targetName << "' is not in your shopping list.\n";
        }
    }

    // 4. Display all items currently stored in the list
    void displayAllItems() const {
        if (items.empty()) {
            cout << "\nYour shopping list is currently empty.\n";
            return;
        }

        cout << "\n--- CURRENT SHOPPING LIST ---\n";
        for (const auto& item : items) {
            item.displayItem();
        }
        cout << "-----------------------------\n";
    }
};

int main() {
    ShoppingList list;
    int choice;

    do {
        cout << "\n===== SHOPPING LIST MENU =====\n";
        cout << "1. Add an Item\n";
        cout << "2. Remove an Item\n";
        cout << "3. Search for an Item\n";
        cout << "4. Display All Items\n";
        cout << "5. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.addItem();
                break;
            case 2:
                list.removeItem();
                break;
            case 3:
                list.searchItem();
                break;
            case 4:
                list.displayAllItems();
                break;
            case 5:
                cout << "\nExiting program. Happy Shopping!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select an option between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
