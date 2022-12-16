#define BROJ_ELEMENATA 1000
#include <stdio.h>
void najveciPad(int max_pad, int niz[]) {
	int pad = 0;
	int pad_a = -1, pad_b, max_pad_a, max_pad_b;
	

	for (int n = 1; n <= BROJ_ELEMENATA; n++) {
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
			if ((pad_b - pad_a) == max_pad) {
				printf("\n[%d, %d]", pad_a, pad_b);
			}
			pad_a = -1;
		}
	}
}