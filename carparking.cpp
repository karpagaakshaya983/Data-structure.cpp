#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> parking;

    parking.push("Car 1");
    parking.push("Car 2");
    parking.push("Car 3");

    cout << "Cars entered the parking garage." << endl;

    while (!parking.empty())
    {
        cout << parking.top() << " leaves the garage." << endl;
        parking.pop();
    }

    return 0;
}
