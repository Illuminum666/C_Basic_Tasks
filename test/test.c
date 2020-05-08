#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

int main() {
	int array[200], i;
	printf("%d\n", (array[0] == NULL) ? 1 : 2);
	for (i = 0; i <= (sizeof(array)/sizeof(array[0])); i++) {
		printf("%d\n", array[i]);
	}

	system("pause");
	return 0;
}