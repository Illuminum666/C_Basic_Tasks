#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struct */
struct time {
    int h, m;
};

/* func. prototype */
struct time findOffSet (char *t);

struct time findOffSet (char *tz) {
    struct time t;
    if (strcmp(tz, "ACDT") == 0) {
        t.h = 10;
        t.m = 30;
    } else if (strcmp(tz, "JST") == 0) {
        t.h = 9;
        t.m = 0;
    } else if (strcmp(tz, "HKT") == 0) {
        t.h = 8;
        t.m = 0;
    } else if (strcmp(tz, "NPT") == 0) {
        t.h = 5;
        t.m = 45;
    } else if (strcmp(tz, "IST") == 0) {
        t.h = 5;
        t.m = 30;
    } else if (strcmp(tz, "MSK") == 0) {
        t.h = 3;
        t.m = 0;
    } else if (strcmp(tz, "GMT") == 0) {
        t.h = 0;
        t.m = 0;
    } else if (strcmp(tz, "EST") == 0) {
        t.h = -5;
        t.m = 0;
    } else if (strcmp(tz, "PST") == 0) {
        t.h = -8;
        t.m = 0;
    }
    return t;
}

int main() {
    struct time local;
    char tzA[5], tzB[5];

    scanf("%d %d", &local.h, &local.m); // scan inputs
    scanf("%s", &tzA);
    scanf("%s", &tzB);

    struct time tA = findOffSet(tzA), tB = findOffSet(tzB); // determine time change
    local.h += tB.h - tA.h;
    local.m += tB.m - tA.m;

    if (local.m < 0) { // fix format
        local.m += 60;
        local.h -= 1;
    } else if (local.m > 59) {
        local.m -= 60;
        local.h += 1;
    }
    if (local.h < 0) {
        local.h += 24;
    } else if (local.h > 23) {
        local.h -= 24;
    }

    if (local.h < 10) {
        printf("0%d ", local.h);
    } else {
        printf("%d ", local.h);
    }
    if (local.m < 10) {
        printf("0%d\n", local.m);
    } else {
        printf("%d\n", local.m);
    }

    return 0;
}