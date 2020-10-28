#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct osoba * Pozicija;
struct osoba;


struct osoba {
	char ime[MAX];
	char prezime[MAX];
	int god;
	Pozicija next;
};

int UnosP( Pozicija P);
void Ispis(Pozicija P);
int UnosP(Pozicija P);
Pozicija Trazi(Pozicija P);
Pozicija TraziPret(Pozicija P);


int main() {

	struct osoba Head;
	Head.next = NULL;
	struct osoba * k;

	UnosP(&Head);
	UnosP(&Head);
	//Ispis(Head.next);
	UnosK(&Head);  
	Ispis(Head.next);
	k = Trazi(Head.next);
	printf("prezime je na adresi %d\n", k);
	printf("Trazeno prezime je osobe %s %s %d\n", k->ime, k->prezime, k->god);

	Izbrisi(&Head);
	printf("lista s izbrisanom osobom:\n");
	Ispis(Head.next);

	return 0;
}

int UnosP( Pozicija P) {

	Pozicija q;
	q = (Pozicija)malloc(sizeof(struct osoba));

	if (q == NULL) return q;

	printf("Upisi podatke o osobi koju zelite dodat na pocetak (ime prezime godina): ");
	scanf("%s %s %d", q->ime, q->prezime, &q->god);

	q->next = P->next;
	P->next = q;

	return 0;
}

void Ispis(Pozicija P) {

	if (P == NULL)
		printf("Lista je prazna! \n");
	else {

		while (P != NULL) {
			printf("%s %s %d\n", P->ime, P->prezime, P->god);
			P = P->next;
		}
	}
}

int UnosK(Pozicija P) {

	Pozicija q;
	q = (Pozicija)malloc(sizeof(struct osoba));

	if (q == NULL) return q;

	else {
		printf("Upisi podatke o osobi koju zelite dodati na kraj (ime prezime godina): ");
		scanf("%s %s %d", q->ime, q->prezime, &q->god);

		while (P->next != NULL)
			P = P->next;

			q->next = P->next;
			P->next = q;
		
	}
	return 0;
}

Pozicija Trazi(Pozicija P) {
	char prez[MAX];

	printf("Koje prezime trazite?");
	scanf(" %s", prez);

	while (P != NULL && (strcmp( P->prezime,prez)) !=0) {
		P = P->next;
	}
	if (P == NULL)
		printf("nema tog prezimena,\n");
	
	return P;
}

Pozicija TraziPret(Pozicija P)
{
	char string[20];

	puts("upisi prezime koje trazis (zelis izbrisati tu osobu):");
	scanf(" %s", string);

	while (P->next != NULL && strcmp(P->next->prezime,string) != 0)
		P = P->next;
	if (P->next == NULL) return NULL;
	return P;
}

int Izbrisi(Pozicija P)
{
	Pozicija prev;

	prev = TraziPret(P);
	if (prev != NULL){
		P = prev->next;
			prev->next = P->next;
			free(P);
	}

}
