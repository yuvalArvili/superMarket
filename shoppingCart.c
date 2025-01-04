#include "shoppingCart.h"

float totalPrice(ShoppingCart* pShoppingCart)
{
	float totalPrice = 0;
	for (int i = 0; i < pShoppingCart->itemsCount; i++)
	{
		totalPrice += pShoppingCart->itemsInCart[i]->price;
	}
	return totalPrice;
}

void addItemToCart(Product* pProduct, ShoppingCart* pShoppingCart)
{
	ShoppingItem** temp = realloc(pShoppingCart->itemsInCart,
		sizeof(ShoppingItem*) * (pShoppingCart->itemsCount + 1));
	if (!temp) {
		printf("Failed to allocate memory for the cart.\n");
		return;
	}
	pShoppingCart->itemsInCart = temp;

	ShoppingItem* newItem = (ShoppingItem*)malloc(sizeof(ShoppingItem));
	if (!newItem) {
		printf("Failed to allocate memory for the shopping item.\n");
		return;
	}
	newItem->qr = pProduct->qr; 
	newItem->price = pProduct->price;   
	newItem->quantity = 1;


	pShoppingCart->itemsInCart[pShoppingCart->itemsCount] = newItem;
	pShoppingCart->itemsCount++;

}

void printCart(Customer* pCustomer)
{
	ShoppingCart* shoppingCart = &pCustomer->shoppingCart;
	float total = totalPrice(&pCustomer->shoppingCart);
	for (int i = 0; i < shoppingCart->itemsCount; i++)
	{
		printf("item %s count %d price per item %f ", shoppingCart->itemsInCart[i]->qr,shoppingCart->itemsInCart[i]->quantity,shoppingCart->itemsInCart[i]->price);
	}
	printf("Total bill to pay: %f ", total);
	
}

void emptyCart(Customer* pCustomer)
{
	for (int i = 0; i < pCustomer->shoppingCart.itemsCount; i++) {
		free(pCustomer->shoppingCart.itemsInCart[i]);  
	}
	free(pCustomer->shoppingCart.itemsInCart);
	pCustomer->shoppingCart.itemsCount = 0;

}

void returnCart(Customer* pCustomer, SuperMarket* pSuperMarket)
{
	for (int i = 0; i < pCustomer->shoppingCart.itemsCount; i++) {
		ShoppingItem* itemInCart = pCustomer->shoppingCart.itemsInCart[i];
		Product* itemInMarket = pSuperMarket->itemsInShop[i];

		if (&itemInCart->qr == &itemInCart->qr) {
			itemInCart->quantity += itemInCart->quantity;
		}
	}
}


