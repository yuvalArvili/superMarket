#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "qr.h"
#include "superMarket.h"

#define MAX 9

char* makeQr(Product* pProduct, SuperMarket* pSuperMarket)
{
	srand(time(NULL));
	char* qr = (char*)malloc(LEN1 + 1);
	if (!qr) {
		printf("Memory allocation failed\n");
		return NULL;
		do
		{
			if (pProduct->theType == eShelf) {
				qr[0] = 'S';
				qr[1] = 'H';
			}
			else if (pProduct->theType == eFrozen) {
				qr[0] = 'F';
				qr[1] = 'Z';
			}
			else if (pProduct->theType == eFridge) {
				qr[0] = 'F';
				qr[1] = 'R';
			}
			else if (pProduct->theType == eFruitVegtable) {
				qr[0] = 'F';
				qr[1] = 'V';
			}
			for (int i = 2; i < 8; i++)
			{
				qr[i] = (rand() % MAX + 1);
			}
		} while (!isQrExist(qr, pSuperMarket));
		return qr;

	}
}

	int isQrExist(const char* qr, SuperMarket* pSuperMarket){
	for (int i = 0; i < pSuperMarket->numOfItem; i++)
	{
		if (strcmp(pSuperMarket->itemsInShop[i]->qr, qr) == 0)
			return 1;
	}
	return 0;
}
int isValid(const char* qr) {
	if (strlen(qr) != 7) {
		printf("Invalid barcode length");
		return 0;
	}

	if (!((qr[0] == 'S' && qr[1] == 'H') ||
		(qr[0] == 'F' && qr[1] == 'Z') ||
		(qr[0] == 'F' && qr[1] == 'R') ||
		(qr[0] == 'F' && qr[1] == 'V'))) {
		printf("Invalid prefix type\n");
		return 0;
	}
	return 1;
}

void freeQr(Qr* qr){
	free(qr);
}

