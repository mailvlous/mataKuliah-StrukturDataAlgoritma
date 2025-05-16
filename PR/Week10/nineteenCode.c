#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "binarytree.h"
#include "nineteenCode.h"

void insertCode(address root, const char* code, const char* letter) {
    address current = root;
    for (int i = 0; i < strlen(code); i++) {
        if (code[i] == '<') {
            if (!current->left) {
                current->left = createNode("");
                current->left->pr = current;
            }
            current = current->left;
        } else if (code[i] == '>') {
            if (!current->right) {
                current->right = createNode("");
                current->right->pr = current;
            }
            current = current->right;
        }
    }
    strcpy(current->info, letter);
}


void initNineteenTree(address root) {
    insertCode(root, "<", "A");
    insertCode(root, ">", "S");

    insertCode(root, "<<", "B");
    insertCode(root, "<>", "J");
    insertCode(root, "><", "T");
    insertCode(root, ">>", "2");

    insertCode(root, "<<<", "C");
    insertCode(root, "<<>", "D");
    insertCode(root, "<><", "K");
    insertCode(root, "<>>", "L");
    insertCode(root, "><<", "U");
    insertCode(root, "><>", "V");
    insertCode(root, ">><", "3");
    insertCode(root, ">>>", "4");

    insertCode(root, "<<<<", "E");
    insertCode(root, "<<<>", "F");
    insertCode(root, "<<><", "G");
    insertCode(root, "<<>>", "H");
    insertCode(root, "<><<", "M");
    insertCode(root, "<><>", "N");
    insertCode(root, "<>><", "O");
    insertCode(root, "<>>>", "P");

    insertCode(root, "><<<", "W");
    insertCode(root, "><<>", "X");
    insertCode(root, "><><", "Y");
    insertCode(root, "><>>", "Z");
    insertCode(root, ">><<", "5");
    insertCode(root, ">><>", "6");
    insertCode(root, ">>><", "7");
    insertCode(root, ">>>>", "8");

    insertCode(root, "<<>><", "I");
    insertCode(root, "<><<<", "Q");
    insertCode(root, "<>><<", "R");
    insertCode(root, "><<<<", "0");
    insertCode(root, "><><<", "1");
    insertCode(root, ">><<<", "9");
    insertCode(root, ">>><<", " ");
}


void reverseStr(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

int findCode(address root, const char* letter, char* path) {
    if (!root) return 0;
    if (strcmp(root->info, letter) == 0) {
        path[0] = '\0'; 
        return 1;
    }

    if (findCode(root->left, letter, path)) {
        int len = strlen(path);
        path[len] = '<';
        path[len + 1] = '\0';
        return 1;
    }

    if (findCode(root->right, letter, path)) {
        int len = strlen(path);
        path[len] = '>';
        path[len + 1] = '\0';
        return 1;
    }

    return 0;
}

void encodeChar(address root, char letter, char* result) {
    char temp[100] = ""; // buffer sementara
    char strLetter[2] = {letter, '\0'}; // ubah char jadi string
    if (findCode(root, strLetter, temp)) {
        reverseStr(temp);  // karena jalur dibangun mundur dari bawah ke atas
        strcpy(result, temp);
    } else {
        strcpy(result, "?"); // tanda tidak ditemukan
    }
}

void encodeString(address root, const char* input, char* output) {
    output[0] = '\0';  // kosongkan output terlebih dahulu

    char code[100];  // buffer untuk menyimpan hasil encode tiap huruf

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '\n' || input[i] == '\r') continue; // abaikan newline

        encodeChar(root, toupper(input[i]), code);  // encode per huruf
        strcat(output, code);  // tambahkan hasil kode ke output

        if (input[i + 1] != '\0') {
            strcat(output, " ");  
        }
    }
}

void decodeString(address root, const char* morse, char* output) {
    output[0] = '\0';  // kosongkan output

    char buffer[100] = "";
    int bufIndex = 0;
    address current = root;

    for (int i = 0; i <= strlen(morse); i++) {
        char c = morse[i];

        if (c == '<') {
            if (current->left) {
                current = current->left;
            } else {
                strcpy(output, "?"); return; // kode rusak
            }
        } else if (c == '>') {
            if (current->right) {
                current = current->right;
            } else {
                strcpy(output, "?"); return; // kode rusak
            }
        } else if (c == ' ' || c == '\0') {
            // akhir dari 1 huruf
            if (strlen(current->info) > 0) {
                strcat(output, current->info);
            } else {
                strcat(output, "?"); // jika info kosong
            }
            current = root;  // kembali ke akar
        }
    }
}


bool isNineteenCode(const char* line) {
    for (int i = 0; line[i]; i++) {
        if (line[i] != '<' && line[i] != '>' && line[i] != ' ') {
            return false;
        }
    }
    return true;
}




// const char* encodeChar(char c) {
//     if (c >= 'a' && c <= 'z') {
//         c -= 32; // Ubah huruf kecil ke huruf besar
//     }

//     int tableSize = sizeof(nineteenCodeTable) / sizeof(nineteenCodeTable[0]);

//     for (int i = 0; i < tableSize; i++) {
//         if (nineteenCodeTable[i].character == c) {
//             return nineteenCodeTable[i].code;
//         }
//     }
//     return "?"; // Jika tidak ditemukan
// }

// void encodeString(const char* input) {
//     for (int i = 0; i < strlen(input); i++) {
//         printf("%s ", encodeChar(input[i]));
//     }
//     printf("\n");
// }

// char* decodeMorse(address root, const char* code) {
//     address current = root;
//     for (int i = 0; i < strlen(code); i++) {
//         if (code[i] == '.') {
//             current = current->left;
//         } else if (code[i] == '-') {
//             current = current->right;
//         }
//         if (!current) return "?"; // tidak valid
//     }
//     return current->info;
// }
