#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define BROJ_ELEMENATA 1000
#pragma warning(disable:4996)
void file(int niz[]) {
	FILE* n_file = fopen("n.txt", "w");

	if (n_file == NULL) {
		printf("Greska pri otvaranju datoteke..");
		return NULL;
	}

	FILE* fi_file = fopen("fi.txt", "w");

	if (fi_file == NULL) {
		printf("Greska pri otvaranju datoteke..");
		return NULL;
	}

	for (int n = 1; n <= BROJ_ELEMENATA; n++) {
		fprintf(n_file, "%d\n", n);
		fprintf(fi_file, "%d\n", niz[n]);
	}
	fclose(n_file);
	fclose(fi_file);
}