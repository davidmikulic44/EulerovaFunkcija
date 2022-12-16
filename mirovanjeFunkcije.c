#define BROJ_ELEMENATA 1000
#include <stdio.h>
int mirovanjeFunkcije(int niz[]) {
	int ponavljanje;
	int flag=0;
	int brojac_ponavljanja = 1;
	int max_brojac_ponavljanja = 1, max_ponovljeni_broj = 1;
	int niz_ponovljenih_brojeva[100] = { 0 };

	for (int n = 1; n < BROJ_ELEMENATA; n++) {
		printf("fi(%d) = %3d\n", n, niz[n]);
		if (flag == 1)
			printf("Funkcija miruje na intervalu [%d, %d]\n", n - 1, n);
		if (niz[n + 1] != niz[n]){
			brojac_ponavljanja = 1;
			flag = 0;
		}
		if (niz[n + 1] == niz[n]) {
			flag = 1;
			
			
			for (int i = 0; i < 100; i++) {
				if (niz_ponovljenih_brojeva[i] == 0) {
					niz_ponovljenih_brojeva[i] = niz[n];
					break;
				}
			}

			ponavljanje = niz[n];
			brojac_ponavljanja++;
			if (brojac_ponavljanja > max_brojac_ponavljanja) {
				max_brojac_ponavljanja = brojac_ponavljanja;

			}
			if (ponavljanje > max_ponovljeni_broj)
				max_ponovljeni_broj = ponavljanje;
		}
		
	}

	printf("\nNajveci ponovljeni broj: %d", max_ponovljeni_broj);

	return max_brojac_ponavljanja;
}