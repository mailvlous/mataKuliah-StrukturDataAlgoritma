#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include "nineteenCode.h"
#include "binarytree.c"
#include "nineteenCode.c"


int main (){
    address root = createNode("");
    initNineteenTree(root);

    inorderTraversal(root);

    printf("\n");
   
    FILE *inFile = fopen("teks.txt", "r");
    if (!inFile) {
        printf("Gagal membuka input.txt!\n");
        return 1;
    }

    FILE *outFile = fopen("output.txt", "w");
    if (!outFile) {
        printf("Gagal membuka output.txt!\n");
        fclose(inFile);
        return 1;
    }

    char line[1000];
    char encoded[10000] = "";
    char decoded[10000] = "";


    while (fgets(line, sizeof(line), inFile)) {
        line[strcspn(line, "\n")] = 0;

        encoded[0] = '\0';
        decoded[0] = '\0';

        if (isNineteenCode(line)) {
            decodeString(root, line, decoded);
            fprintf(outFile, "Decoded: %s\n", decoded);
        } else {
            encodeString(root, line, encoded);
            fprintf(outFile, "Encoded: %s\n", encoded);
        }
    }

    fclose(inFile);
    fflush(outFile);

    fclose(outFile);

    char result[100];
    encodeString(root, "JTK Politeknik Negeri Bandung", result);
    printf("%s\n", result);

    char hasil[100];
    decodeString(root, "<< <>>", hasil);
    printf("%s\n", hasil);


    return 0;
}