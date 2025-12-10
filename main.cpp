#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void printDate() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    cout << buffer << endl;
}

int main() {
    string username;
    string version = "Maksh 1.2";

    cout << "Welcome to Maksh. Enter your username: ";
    getline(cin, username);

    string input;
    bool running = true;

    while (running) {
        cout << username << " >> ";
        getline(cin, input);

        if (input == "whoami") {
            cout << username << endl;

        } else if (input == "info") {
            cout << "Maksh version " << version << endl;

        } else if (input == "help") {
            cout << "Available commands:\n"
                 << "  info, help, whoami, echo <text>, hi, lol,\n"
                 << "  date, exit\n";

        } else if (input == "exit") {
            cout << "Good luck, " << username << endl;
            running = false;

        } else if (input == "hi") {
            cout << "Hello, " << username << endl;

        } else if (input == "lol") {
            cout << "Lol" << endl;

        } else if (input == "date") {
            printDate();

        } else if (input.rfind("echo ", 0) == 0) {
            cout << input.substr(5) << endl;

        } else if (input.empty()) {
            continue;

        } else {
            cout << "Maksh: command not found. Try 'help'" << endl;
        }
    }

    return 0;
}

