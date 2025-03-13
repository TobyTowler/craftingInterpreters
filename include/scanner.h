#pragma once

#include <string>
#include <vector>
void inputPrompt();

void run(std::string input);

void error(int line, std::string message);

void report(int line, std::string where, std::string message);

static std::vector<std::byte> runFile(std::string path);
