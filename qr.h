#pragma once
#ifndef __QR_H
#define __QR_H

#define LEN1 7


typedef struct Product Product;
typedef struct SuperMarket SuperMarket;


typedef struct
{
	char qr[LEN1];
	
	
}Qr;

char* makeQr(Product* pProduct, SuperMarket* pSuperMarket);
int isQrExist(const char* qr,SuperMarket* pSuperMarket);
int isValid(char* qr);
void freeQr(Qr* qr);

#endif