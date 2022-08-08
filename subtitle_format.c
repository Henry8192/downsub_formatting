#include <stdio.h>
#include <string.h>
int main() {
    char str[60];
    FILE* fp, * dest;

    /* opening file for reading */
    fp = fopen("sub.txt", "r");
    dest = fopen("result.txt", "w");

    if (fp == NULL) {
        perror("Error opening file with the file name \"sub.txt\"");
        return -1;
    }
    while (fgets(str, 60, fp) != NULL) {
        if (str[0] == '\n') continue;
        str[strlen(str) - 1] = '\0';
        fprintf(dest, "%s ", str);
    }
    fclose(fp);
    return 0;
}