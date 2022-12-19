#define _CRT_SECURE_NO_WARNINGS
#define BROJ_ELEMENATA 1000
#include <stdio.h>
#pragma warning(disable:4996)
int* euler() {
	int fi_n, flag;
	int n, j, k;
	static int niz[BROJ_ELEMENATA + 1];

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
		niz[n] = fi_n;
	}
	return niz;
}

int rast(int niz[]) {
	int rast = 0, max_rast = 0;
	int rast_a = -1, rast_b, max_rast_a, max_rast_b;

	for (int n = 1; n <= BROJ_ELEMENATA; n++) {
		printf("fi(%d) = %3d\n", n, niz[n]);
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
			printf("Funkcija raste na intervalu [%d, %d]\n", rast_a, rast_b);

			if ((rast_b - rast_a) >= max_rast) {
				max_rast = rast_b - rast_a;
			}
			rast_a = -1;
		}
	}

	return max_rast;
}

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

int mirovanjeFunkcije(int niz[]) {
	int ponavljanje;
	int flag = 0;
	int brojac_ponavljanja = 1;
	int max_brojac_ponavljanja = 1, max_ponovljeni_broj = 1;
	int niz_ponovljenih_brojeva[100] = { 0 };

	for (int n = 1; n < BROJ_ELEMENATA; n++) {
		printf("fi(%d) = %3d\n", n, niz[n]);
		if (flag == 1)
			printf("Funkcija miruje na intervalu [%d, %d]\n", n - 1, n);
		if (niz[n + 1] != niz[n]) {
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

int odabir;

int main() {
	int fi_n,flag;
	int n, j, k;
	int *niz;
	int neki_n;
	niz = euler();


	do {
		printf("\n---------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t      Eulreova funkcija 1-%d \n\n",BROJ_ELEMENATA);
		printf("\t\t\t\t  1 : Ispis Eulerove funkcije\n");
		printf("\t\t\t\t  2 : Ispis intervala rasta funkcije\n");
		printf("\t\t\t\t  3 : Ispis intervala padova funkcije\n");
		printf("\t\t\t\t  4 : Ispis intervala mirovanja funkcije\n");
		printf("\t\t\t\t  5 : fi(n) = ?\n");
		printf("\t\t\t\t  6 : Zapis vrijednosti n i fi(n) u datoteke\n");
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
				printf("\nNajveci broj ponavljanja istog broja: %d", mirovanjeFunkcije(niz));
				break;
			case 5:
				system("cls");				
				do{
					printf("Unesi neki n <= %d: ",BROJ_ELEMENATA);
					scanf("%d", &neki_n);
					if (neki_n > BROJ_ELEMENATA) {
						printf("Unos mora biti manji ili jednak %d\n",BROJ_ELEMENATA);
					}
				} while (neki_n > 1000);
				system("cls");
				printf("fi(%d) = %d", neki_n, niz[neki_n]);
				break;
			case 6:
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
