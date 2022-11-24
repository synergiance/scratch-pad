//
// Created by Synergiance on 12/22/21.
//

#include <malloc.h>

int main () {
	char *array1 = malloc(64);
	char *array2 = malloc(16);
	free(array1);
	free(array2);
}