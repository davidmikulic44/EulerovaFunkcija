#define _CRT_SECURE_NO_WARNINGS
#define BROJ_ELEMENATA 1000
#include <stdio.h>
#include "header.h"

int odabir = 44;

int main() {
	int fi_n,flag;
	int n, j, k;
	int *niz;
	niz = euler();


	do {
		printf("\n---------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t      Eulreova funkcija 1-%d \n\n",BROJ_ELEMENATA);
		printf("\t\t\t\t  1 : Ispis Eulerove funkcije\n");
		printf("\t\t\t\t  2 : Ispis intervala rasta funkcije\n");
		printf("\t\t\t\t  3 : Ispis intervala padova funkcije\n");
		printf("\t\t\t\t  4 : Ispis intervala mirovanja funkcije\n");
		printf("\t\t\t\t  5 : Zapisi vrijednosti n i fi(n) u datoteke\n");
		printf("\t\t\t\t  0 : Izlaz iz programa\n");
		printf("---------------------------------------------------------------------------------------------------------\n");

		scanf(" %d", &odabir);

		switch (odabir) {
			case 1:
				system("cls");
				for (n = 1; n <= BROJ_ELEMENATA; n++) {
					printf("fi(%d) = %d\n", n, niz[n]);
				}
				break;
			case 2:
				system("cls");
				int max_rast = rast(niz);
				printf("\nNajveci rast: %d, na intervalima:\n", max_rast+1);
				najveciRast(max_rast,niz);
				break;
			case 3:
				system("cls");
				int max_pad = pad(niz);
				printf("\nNajveci pad: %d, na intervalima:\n", max_pad+1);
				najveciPad(max_pad, niz);
				break;
			case 4:
				system("cls");
				printf("\nNajveci broj ponavljanja broja: %d", mirovanjeFunkcije(niz));
				break;
			case 5:
				system("cls");
				file(niz);
				printf("Vrijednosti su zapisane u n.txt i fi.txt!");
				break;
			case 0:
				printf("\nGasenje programa...\n");
				return 0;
			default:
				system("cls");
				printf("Opcija ne postoji...");
				break;
		}
	} while (odabir != 0);
}