#pragma once
#include <Windows.h>
#include <string>
#include <iostream>

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define KBOLD "\x1B[1m"


void printY(const std::string buffer);
void printRB(const std::string buffer);
void printB(const std::string buffer);
void printG(const std::string buffer);


void SetColor(int value);