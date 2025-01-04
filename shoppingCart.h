#pragma once
#ifndef __SHOPPING_CART_H
#define __SHOPPING_CART_H

#include "shoppingItem.h"
#include "product.h"
#include "customer.h"
#include "superMarket.h"


typedef struct
{
	ShoppingItem** itemsInCart;
	int itemsCount;

}ShoppingCart;

float totalPrice(ShoppingCart* pShoppingCart);
void addItemToCart(Product* pProduct, ShoppingCart* pShoppingCart);
void printCart(Customer* pCustomer);
void emptyCart(Customer* pCustomer);
void returnCart(Customer* pCustomer, SuperMarket* pSuperMarket);

#endif