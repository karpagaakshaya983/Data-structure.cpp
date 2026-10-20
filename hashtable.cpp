#include <iostream>
using namespace std;

int main()
{
    int table[10];
    int size = 10;

    for (int i = 0; i < size; i++)
        table[i] = -1;

    int choice, x, index, i;

    do
    {
        cout << "\n1. INSERT\n2. SEARCH\n3. DISPLAY\n4. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter account number: ";
                cin >> x;

                index = x % size;
                i = 0;

                while (i < size && table[index] != -1)
                {
                    index = (index + 1) % size;
                    i++;
                }

                if (i == size)
                    cout << "Hash table is full";
                else
                {
                    table[index] = x;
                    cout << "Inserted successfully";
                }
                break;

            case 2:
                cout << "Enter account number to search: ";
                cin >> x;

                index = x % size;
                i = 0;

                while (i < size && table[index] != -1)
                {
                    if (table[index] == x)
                        break;

                    index = (index + 1) % size;
                    i++;
                }

                if (i < size && table[index] == x)
                    cout << "Account found at index " << index;
                else
                    cout << "Account not found";
                break;

            case 3:
                cout << "Hash Table:\n";

                for (int j = 0; j < size; j++)
                    cout << j << " : " << table[j] << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
