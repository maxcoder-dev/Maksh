#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

const string VERSION = "Maksh 2.0";

// ===== Utils =====
void printDateTime() {
    time_t now = time(nullptr);
    tm local{};

#ifdef _WIN32
    localtime_s(&local, &now);
#else
    local = *localtime(&now);
#endif

    char buffer[32];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &local);
    cout << buffer << endl;
}

string toUpper(string text) {
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    return text;
}

string toLower(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ===== Main =====
int main() {
    string username;
    cout << "🚀 Welcome to Maksh shell\n";
    cout << "Enter username: ";
    getline(cin, username);

    if (username.empty())
        username = "guest";

    cout << "Type 'help' to see available commands.\n\n";

    bool running = true;
    string input;

    while (running) {
        cout << username << " >> ";
        getline(cin, input);

        if (input.empty())
            continue;

        // ===== Commands =====
        if (input == "exit") {
            cout << " Goodbye, " << username << "!\n";
            running = false;
        }
        else if (input == "help") {
            cout <<
                "Available commands:\n"
                "  help              - show this help\n"
                "  info              - shell info\n"
                "  whoami            - show username\n"
                "  date / time       - show date & time\n"
                "  echo <text>       - print text\n"
                "  upper <text>      - text to UPPERCASE\n"
                "  lower <text>      - text to lowercase\n"
                "  clear             - clear screen\n"
                "  hi                - greeting\n"
                "  exit              - exit shell\n";
        }
        else if (input == "info") {
            cout << "Maksh shell version " << VERSION << endl;
        }
        else if (input == "whoami") {
            cout << username << endl;
        }
        else if (input == "hi") {
            cout << "Hello, " << username << "\n";
        }
        else if (input == "date" || input == "time") {
            printDateTime();
        }
        else if (input == "clear") {
            clearScreen();
        }
        else if (input.rfind("echo ", 0) == 0) {
            cout << input.substr(5) << endl;
        }
        else if (input.rfind("upper ", 0) == 0) {
            cout << toUpper(input.substr(6)) << endl;
        }
        else if (input.rfind("lower ", 0) == 0) {
            cout << toLower(input.substr(6)) << endl;
        }
        else {
            cout << "Maksh: command not found → '" << input << "'\n";
        }
    }

    return 0;
}
