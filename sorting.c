#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void sortuj_wstawianie(int tab[], int n) {
	
	int comparison = 0;
	int swap = 0;
	int pom, j;
	for (int i = 1; i < n; i++) {
		pom = tab[i];
		j = i - 1;

		while (++comparison && j >= 0 && tab[j] > pom) {
			tab[j + 1] = tab[j];
			--j;
			swap++;
		}
		tab[j + 1] = pom;
		swap++;
	}
	printf("%d %d %d\n", n, comparison, swap);
}

void sortuj_wybor(int tab[], int n) {
	int mn_index;
	int comparison = 0;
	int swap = 0;

	for (int i = 0; i < n - 1; i++)
	{
		mn_index = i;
		for (int j = i + 1; j < n; j++) {
			comparison++;
			if (tab[j] < tab[mn_index]) {
				mn_index = j;
			}
		}
		int box = tab[mn_index];
		tab[mn_index] = tab[i];
		tab[i] = box;
		swap++;
	}
	printf("%d %d %d\n", n, comparison, swap);
}

void sortuj_zamiana(int tab[], int n) {
	int comparison = 0;
	int swap = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			comparison++;
			if (tab[j - 1] > tab[j]) {
				int box = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = box;
				swap++;
			}
		}
	}
	printf("%d %d %d\n", n, comparison, swap);
}


int main() {
	
	srand(time(NULL));
	int t[10000];
	printf("Sortowanie przez wstawianie\n");
	
		for (int tabSize = 100; tabSize <= 10000; tabSize += 100) {
		for (int j = 0; j < tabSize; j++) {
			t[j] = tabSize - j;
		}
		sortuj_wstawianie(t, tabSize);
	}
	
	printf("\nSortowanie przez wybor\n");
	for (int tabSize = 100; tabSize <= 10000; tabSize += 100) {
		for (int j = 0; j < tabSize; j++) {
			t[j] = tabSize - j;
		}
		sortuj_wybor(t, tabSize);
	}
	
	printf("\nSortowanie przez zamiane\n");
	for (int tabSize = 100; tabSize <= 10000; tabSize += 100) {
		for (int j = 0; j < tabSize; j++) {
			t[j] = tabSize - j;
		}
		sortuj_zamiana(t, tabSize);
	}
	

	return 0;
}

