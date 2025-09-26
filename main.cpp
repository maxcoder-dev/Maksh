#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    string username, token, version = "Maksh 1.0";

    cout << "Welcome to the Maksh! Enter your username: ";
    getline(cin, username);

    bool running = true;

    while (running) {
        cout << username << " >> ";
        getline(cin, token);

        if (token == "whoami") {
            cout << username << endl;
        } else if (token == "info") {
            cout << "Maksh version " << version << endl;
        } else if (token == "help") {
            cout << "info, help, whoami, echo your_text, hi, lol, date, exit" << endl;
        } else if (token == "exit") {
            cout << "Okay, good luck, " << username << endl;
            break;
        } else if (token == "lol") {
            cout << "Lol" << endl;
        } else if (token == "hi") {
            cout << "Hello, " << username << endl;
        } else if (token == "date") { 
            time_t now = time(0);
            tm *ltm = localtime(&now);
            char buffer[11];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
            cout << buffer << endl;
        } else if (token.rfind("echo ", 0) == 0) {
            string text = token.substr(5);
            cout << text << endl;
        } else {
            cout << "Maksh: command not found, try 'help'" << endl;
        }
    }
}
