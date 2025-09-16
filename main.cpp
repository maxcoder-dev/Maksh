#include <iostream>
#include <string>

using namespace std;


int main() {
    string username, token, version = "1.0";
    
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
        } else if (token == "lol") {
            cout << "Lol" << endl;
        } else if (token == "hi") {
            cout << "Hello, " << username << endl;
        } 
        else {
            cout << "Maksh: command not found, try 'help'" << endl;
        }
    }
}



