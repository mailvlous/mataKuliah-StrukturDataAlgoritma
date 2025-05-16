#ifndef NINETEENCODE_H
#define NINETEENCODE_H

#include <stdlib.h>
#include "binarytree.h"

typedef struct {
    char character;
    const char* code;
} Code;

const Code nineteenCodeTable[] = {
    {'A', "<"},   {'S', ">"},
    {'B', "<<"}, {'J', "<>"},  {'T', "><"}, {'2', ">>"},
    {'C', "<<<"},  {'D', "<<>"}, {'K', "<><"}, {'L', "<>>"}, {'U', "><<"}, {'V', "><>"}, {'3', ">><"}, {'4', ">>>"},
    {'E', "<<<<"}, {'F', "<<<>"}, {'G', "<<><"},  {'H', "<<>>"},  {'M', "<><<"}, {'N', "<><>"},  {'O', "<>><"}, {'P', "<>>>"}, 
    {'W', "><<<"}, {'X', "><<>"}, {'Y', "><><"}, {'Z', "><>>"}, {'5', ">><<"}, {'6', ">><>"}, {'7', ">>><"}, {'8', ">>>>"},
    {'I', "<<>><"}, {'Q', "<><<<"}, {'R', "<>><<"}, {'0', "><<<<"}, {'1', "><><<"}, {'9', ">><<<"}, {' ', ">>><<"}
};

const int nineteenCodeTableSize = sizeof(nineteenCodeTable) / sizeof(Code);

void insertCode(address root, const char* code, const char* letter);

void initNineteenTree(address root);

void reverseStr(char* str);

int findCode(address root, const char* letter, char* path);

void encodeChar(address root, char letter, char* result);

bool isNineteenCode(const char* line);

#endif // !