#pragma once
#include "qr.h"
#ifndef __SHOPPING_ITEM_H
#define __SHOPPING_ITEM_H

typedef struct
{
	Qr qr;
	float price;
	int quantity;

}ShoppingItem;



#endif