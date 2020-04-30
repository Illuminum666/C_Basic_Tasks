#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {
    char input_string[BUFSIZ]; //BUFSIZ is a constant defined by the system.
    char target_string[BUFSIZ];
    int input_string_size = 0;

    printf("Please enter a line of text, max %d characters:\n", sizeof(input_string));

    //read a text string from the keyboard and remove the line break at the end
    char *p;
    if (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        if ((p = strchr(input_string, '\n')) != NULL)
            *p = '\0';  // the \n will be replaced by the NULL character
        input_string_size = strlen(input_string);   //find the length of the text string (\0 included)
    }


    //process the input string
    int i=0, j=0;
    int space_count = 0;

    while (i < input_string_size) {
        if (i) {
            target_string[j] = '-';
            space_count += 1;
            j += 1;
        }
        while (input_string[i] == ' ') {
            i += 1;
        }
        while (input_string[i] != ' ') {
            target_string[j] = toupper(input_string[i]);
            i += 1;
            j += 1;
        }
    }

    target_string[i] = '\0'; //add NULL character to end the string

    printf("\nNo. of characters: %d\n", strlen(input_string));

    printf("No. of words: %d\n\n", space_count + 1);

    printf("Output string: %s \n",target_string);
    printf("No. of characters now: %d\n\n", strlen(target_string));

    system("pause");
    return 0;
}