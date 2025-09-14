#include <iostream>
#include <string>

using namespace std;


int main() {
    string username, token, version = "Maksh 1.0";
    
    cout << "Welcome to the Maksh! Enter your username: ";
    cin >> username;

    bool running = true;

    while (running) {
        cout << username << " >> ";
        cin >> token;

        if (token == "whoami") {
            cout << username << endl;
        } else if (token == "info") {
            cout << "Maksh version " << version << endl;
        } else if (token == "help") {
            cout << "info, help, whoami, exit " << endl;
        } else if (token == "exit") {
            cout << "Okay, good luck, " << username << endl;
            break;
        } 
        else {
            cout << "Maksh: command not found, try 'help'" << endl;
        }
    }
}
