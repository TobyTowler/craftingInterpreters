#include "scanner.h"
#include "Lox.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool hadError = false;

void inputPrompt() {
    string line;
    string input;

    for (;;) {
        cout << "> ";
        cin >> line;
        input += line;
        if (line == "")
            break;
        run(input);
        hadError = false;
    }
}

void run(string input) {
    Scanner scanner = scanner(input);
    vector<Token> tokens = scanner.tokens;

    for (Token t : input) {
        cout << t;
    }
}

void error(int line, string message) { report(line, "", message;) }

void report(int line, string where, string message) {
    cout << "Line " << line << "ERROR " << where << ": " << message;
    hadError = true;
}
