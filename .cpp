#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "What's your name? ";
    getline(cin, name); // Taking input from the user
    cout << "Hello, " << name << "! Welcome to C++" << endl; // Output the greeting
    return 0;
}
