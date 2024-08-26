#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//struct for counting the number of times a letter is in the doc
struct counter {
    int count;
    char name;
};
int main(int argc, char *argv[])
{
    if(argc != 2) { //make sure there are only two arguments
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    FILE *f = fopen(argv[1], "r");
    if(f == NULL) { //make sure file name is inputted and not something random
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }
    struct counter array[26];
    for (int i = 0; i < 26; i++) { //init counter struct with the char name being alphabet a-z and the count to 0
        array[i].name = 'a' + i;
        array[i].count = 0;
    }
    char line[1024];
    while(fgets(line, sizeof(line), f)) { //read the line in the file
        for (int i = 0; i < strlen(line); i++) { //go through each character in the line
            char c = tolower(line[i]);  // send the character to lower case
            if(c >= 'a' && c <= 'z') {
                int index = c - 'a'; //find the index of the array
                array[index].count++;
            }
        }
    }
    fclose(f);
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
    printf("%c %d\n", array[i].name, array[i].count);
    }
    return 0;
}
