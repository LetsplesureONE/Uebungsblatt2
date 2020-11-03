#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int wurf[6];
int becher[5];

void linex2(int l, char c) {
	for (int i = 0; i < l; i++) {
		printf("%c", c);
	}
	printf("\n");
}

void xdistance2(int dist,char c) {
	printf("%c", c);
	for (int i = 0; i < (dist - 2); i++) {
		printf(" ");
	}
	printf("%c\n", c);
}

void rechteck(int breite, int hoehe, char c) {
	linex2(breite, c);
	for (int i = 0; i < (hoehe - 2); i++) {
		xdistance2(breite, c);
	}
	linex2(breite, c);
}
	
void aufgabe1(void) {
	//Aufgabe 1 rechteck(4, 6, 'x'); return 0;
	rechteck(4, 6, 'x');
}

//Aufgabe 2

void sanduhr(int b, char c) {
	int m = 0;
	if (b % 2 == 0) {
		//oberer Teil gerade
		for (int i = b; i > 0; i = i - 2) {
			for (int j = ((b - i) / 2); j > 0; j = j - 1) {
				printf(" ");
			}
			for (int k = i; k > 0; k = k - 1) {
				printf("%c", c);
				m = k + 1;
			}
			printf("\n");
		}
		//uterer Teil gerade
		for (int i = m; i <= (b - 1); i = i + 2) {

			for (int j = ((b - i) / 2); j > 0; j = j - 1) {
				printf(" ");
			}
			printf("%c", c);
			for (int k = i - 1; k > 1; k = k - 1) {
				printf(" ");
			}
			printf("%c\n", c);
		}
		for (int i = b; i > 0; i--) {
			printf("%c", c);
		}
		printf("\n");
	}
	else {
		//oberer Teil ungerade
		for (int i = b; i > 0; i = i - 2) {
			for (int j = ((b - i) / 2); j > 0; j = j - 1) {
				printf(" ");
			}
			for (int k = i; k > 0; k = k - 1) {
				printf("%c", c);
				m = k + 1;
			}
			printf("\n");
		}
		//unterer Teil ungerade
		for (int i = m+1; i <= (b-1); i = i + 2) {

			for (int j = ((b - i) / 2); j > 0; j = j - 1) {
				printf(" ");
			}
			printf("%c", c);
			for (int k = i - 1; k > 1; k = k - 1) {
				printf(" ");
			}
			printf("%c\n", c);
		}
		for (int i = b; i > 0; i--) {
			printf("%c", c);
		}
		printf("\n");
	}
} 

void aufgabe2(void) {
	//Aufgabe 2 
	sanduhr(6, 'x'); 
	sanduhr(7, 'x');
	sanduhr(8, 'x');
	sanduhr(9, 'x');
}

//Aufgabe 3

int calcSumIntArray(int* samples, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + samples[i];
		//printf("%d",i); //debugging...;)
	}
	return sum;
}

void aufgabe3(void) {
	int samples[] = { 2, 6, 8, 10, 4 }; 
	int summe = calcSumIntArray(samples, 5); 
	printf("Die Summe ist: = %d\n", summe);
}

//Aufgabe 4

int ggT(int a, int b){
	int max = b;
	int gg = 0;
	if (a <= b) {
		max = a;
	}
	for (int i = 1; i <= max; i++) {
		if ((a % i)==0) {
			if ((b % i)==0) {
				gg = i;
			}
		}
	}
	return gg;
}

void aufgabe4(void){
	int a = 23, b = 68; 
	printf("Der ggT von %d und %d ist %d.\n", a, b, ggT(a, b));
	return 0;
}

//Aufgabe 5

void bruchMultiplikation(int o1, int u1, int o2, int u2) {
	int oe = (o1*o2);
	int ue = (u1*u2);
	int shorter = ggT(oe, ue);
	oe = oe / shorter;
	ue = ue / shorter;
	printf("Der multiplizierte Bruch aus %d/%d & %d/%d lautet: %d/%d",o1,u1,o2,u2,oe,ue);
}

void aufgabe5(void){
	int zaehler1 = 5, nenner1 = 8, zaehler2 = 2, nenner2 = 7; 
	bruchMultiplikation(zaehler1, nenner1, zaehler2, nenner2);
}

//Aufgabe 6

int dx(int d) {
	return rand() % d + 1;
}

void becherWurf(int* samples) {
	for (int i = 0; i < 5; i++) {
		samples[i]=dx(6);
	}
	/*//debug array print
	printf("Array print:");
	for (int i = 0; i < 5; i++) {
		printf(" %d",samples[i]);
	}
	*/
}

bool viererPasch(int* samples) {
	//int wurf[6]; // wegen Speicherverbrauch
	int bambus = 0;
	for (int i = 0; i < 5; i++) { // resetting wurf[]
		wurf[samples[i] - 1] = 0;
	}
	for (int i = 0; i < 5; i++) {
		wurf[samples[i] - 1]= wurf[samples[i] - 1]+1;
	}

	printf("\nWurf Array print:"); //debug print
	for (int i = 0; i < 5; i++) {
		printf(" %d", wurf[i]);
	}

	for (int i = 0;i<(6-1); i++) {
		if (wurf[i] >= 4) {
			bambus++;
		}
	}
	if (bambus > 0) {
		return true;
	}
	else return false;
}

void wuerfe(void) {
	bool count = 0;
	for (bool baum = 0; baum == 0;count++) {
		becherWurf(becher);
		baum = viererPasch(becher);
	}
	printf("to get four Identicals it took %d trys\n", count);
}

void aufgabe6(void) {
	srand(7);
	
	wuerfe();
	wuerfe();
	wuerfe();
	wuerfe();
	wuerfe();
	wuerfe();
	wuerfe();
	wuerfe();
	//becherWurf(becher);
	/*for (int i = 0; i < 100; i++) {
		printf("%d",dx(6));
	}*/
}

int main(void) {
	//aufgabe1();
	//aufgabe2();
	//aufgabe3();
	//aufgabe4();
	//aufgabe5();
	aufgabe6();
	return 0;
}