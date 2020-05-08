#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* BT14 Me on the Guest List? */
int main()
{    
    FILE *fp;
    fp = fopen("names.txt", "r");
    char names[200][100];
        
    /* Get each name into names[] and replace \n with \0 (NULL) */
    int i=0;
    char *p;
    while((fgets(names[i],sizeof(names[i]), fp)) != NULL) {        
        if ((p = strchr(names[i], '\n')) != NULL) {
            *p = '\0';
        }
        i++;
    }
    fclose(fp);
    
    /*read keyword from the keyboard and remove the line break at the end*/
    printf("Name? ");
    char keyword[BUFSIZ]; 
    if (fgets(keyword, sizeof(keyword), stdin) != NULL) {
        if ((p = strchr(keyword, '\n')) != NULL) {
            *p = '\0';
        }
    }
    
    int lines[200], j=0;
    lines[0] = 0;
    for (i = 0; i <= (sizeof(names) / sizeof(names[0])); i++) {
        if (!(strcmp(names[i], keyword))) {
            lines[j] = i + 1;
            j++;
        }
    }
    if (!(lines[0])) {
        printf("'%s' not found\n", keyword);
    } else {
        printf("'%s' found in line: ", keyword);
        i = 0;
        do {
            printf("%d", lines[i]);
            i++;
            if (i < j) {
                printf(", ");
            }
        } while (i < j);
        printf("\n");
    }





    system("pause");
    return 0;
}