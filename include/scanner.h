#pragma once

#include <string>
void inputPrompt();

void run(std::string input);

void error(int line, std::string message);

void report(int line, std::string where, std::string message);
