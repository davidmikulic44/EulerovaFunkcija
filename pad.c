#define BROJ_ELEMENATA 1000
#include <stdio.h>
int pad(int niz[]) {
	int pad_a = -1, pad_b, max_pad_a, max_pad_b;
	int pad = 0, max_pad = 0;

	for (int n = 1; n <= BROJ_ELEMENATA; n++) {
		printf("fi(%d) = %3d\n", n, niz[n]);

		if (niz[n + 1] < niz[n]) {
			if (pad == 0)
				pad_a = n;
			pad = 1;
		}
		else {
			pad = 0;
			pad_b = n;
		}

		if (n == BROJ_ELEMENATA && pad == 1) {
			pad_b = n;
			pad = 0;
		}

		if ((pad == 0 && pad_a != -1)) {
			printf("Funkcija pada na intervalu [%d, %d]\n", pad_a, pad_b);

			if ((pad_b - pad_a) >= max_pad) {
				max_pad = pad_b - pad_a;
			}

			pad_a = -1;
		}
	}


	return max_pad;
}