#define BROJ_ELEMENATA 1000
#include <stdio.h>

void najveciRast(int max_rast, int niz[]) {
	int rast = 0;
	int rast_a = -1, rast_b, max_rast_a, max_rast_b;

	for (int n = 1; n <= BROJ_ELEMENATA; n++) {
		if (niz[n + 1] > niz[n]) {
			if (rast == 0)
				rast_a = n;
			rast = 1;
		}
		else {
			rast = 0;
			rast_b = n;
		}

		if (n == BROJ_ELEMENATA && rast == 1) {
			rast_b = n;
			rast = 0;
		}

		if (rast == 0 && rast_a != -1) {
			if ((rast_b - rast_a) == max_rast) {
				printf("\n[%d, %d]", rast_a, rast_b);
			}
			rast_a = -1;
		}
	}
}