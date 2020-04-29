#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int main() {
    int max, min, mean = 0, i = 0, j, freq = 0;
    char num[6];

    FILE *fp, *fp2;
    fp = fopen("numbers.txt", "r");
    fp2 = fopen("frequency.txt", "w");

    if (fp == NULL || fp2 == NULL) { // detects whether the text file is present or not
        printf("Some text files not detected\n");
        system("pause");
        return 0;
    }

    printf("Loading...");

    while (fgets(num, 6, fp) != NULL) { // read file
        if (!(i)) {
            max = atoi(num);
            min = atoi(num);
        } else {
            if (max <= atoi(num)) { // max
                max = atoi(num);
            } 
            if (min >= atoi(num)) { // min
                min = atoi(num);
            }
        }
        i += 1;
        mean += atoi(num);
    }

    fclose(fp);
    for (i = 0; i < 10000; i++) { // check frequency
        freq = 0;
        fp = fopen("numbers.txt", "r");
        while (fgets(num, 6, fp) != NULL) { // count
            if (i == atoi(num)) {
                freq += 1;
            }
        }
        if (freq) { //print in file
            if (!(i)) {
                fprintf(fp2, "000");
            } else {
                for (j = 1; j <= (3 - floor(log10(i))); j++) {
                    fprintf(fp2, "0");
                }
            }
            fprintf(fp2, "%d\t%d\n", i, freq);
        }
        
        fclose(fp);
    }

    fclose(fp2);

    /* print stuff */
    system("cls");
    printf("Max\t= %d\n", max);
    printf("Min\t= %d\n", min);
    printf("Mean\t= %d\n", mean / i);
    printf("Frequency of integers is in frequency.txt\n");
    system("pause");
    return 0;
}