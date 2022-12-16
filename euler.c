#include <stdio.h>
#define BROJ_ELEMENATA 1000

int* euler() {
	int fi_n, flag;
	int n, j, k;
	static int niz[BROJ_ELEMENATA + 1];



	//FILE* n_file = fopen("n.txt", "w");
	//FILE* fi_file = fopen("fi.txt", "w");


	for (n = 1; n <= BROJ_ELEMENATA; n++) {
		fi_n = 0;
		for (j = 1; j <= n; j++) {
			for (k = 1; k <= j; k++) {
				if (n % k == 0 && j % k == 0)
					flag = k;
			}
			if (flag == 1) {
				fi_n++;
			}
		}
		//fprintf(n_file, "%d\n", n);
		//fprintf(fi_file, "%d\n", fi_n);
		niz[n] = fi_n;
	}

	//fclose(n_file);
	//fclose(fi_file);

	return niz;
}