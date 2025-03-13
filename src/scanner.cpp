#include "scanner.h"
#include "Lox.h"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>

bool hadError = false;

void inputPrompt() {
    std::string line;
    std::string input;

    for (;;) {
        std::cout << "> ";
        std::cin >> line;
        input += line;
        if (line == "")
            break;
        run(input);
        hadError = false;
    }
}
static std::vector<std::byte> runFile(std::string path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open source file");
    }
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<std::byte> buffer(size);

    return buffer;
}

void run(std::string input) {
    Scanner scanner = scanner(input);
    vector<Token> tokens = scanner.tokens;

    for (Token t : input) {
        std::cout << t;
    }
}

void error(int line, std::string message) { report(line, "", message); }

void report(int line, std::string where, std::string message) {
    std::cout << "Line " << line << "ERROR " << where << ": " << message;
    hadError = true;
}
