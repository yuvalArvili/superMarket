#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "superMarket.h"


void main()
{
	int answer;
	char choice;
	char barcode[7];
	char id[10];
	Customer* currentCustomer;
	Product* currentProduct;
	SuperMarket* superMarket;
	Type type;

	initSuperMarket(superMarket);
	do
	{
		printf("please choose one of the following options: \n");
		printf("0 - Show SuperMarket \n");
		printf("1 - Add Product \n");
		printf("2 - Add Customer \n");
		printf("3 - Customer Shopping \n");
		printf("4 - Print Shopping Cart \n");
		printf("5 - Customer Shopping Cart Managment \n");
		printf("6 - Print Product By Type \n");
		printf("-1 - Quit \n");
		scanf("%d ", &answer);


		switch (answer)
		{
		case 0:
			printSuperMarket(superMarket);
			break;
		case 1:
			addItemToShop(superMarket);
			break;
		case 2:
			addCustomerToShop(superMarket);
			break;
		case 3:
			printf("please enter your id");
			scanf("%9s ", id);
			if (!isRegister(&superMarket, id)) {
				printf("you must be registered");
				break;
			}
			else {
				printProduct(superMarket);
				if (superMarket->numOfCustomers == 0) {
					printf("No customer listed to market");
					break;
				}
				else if(superMarket->numOfItem == 0) {
					printf("No product in market - cannot shop");
					break;
				}
				
				while (1) {
					printf("Do you want to shop for a product Y/y ,anything else to exit");
					scanf("%s ", choice);
					if (tolower(choice) == 'y') {
						printf("Enter a barcode. Barcode should be of 7 length exactly \n Must have 2 type prefix letters followed by a 5 digits number. For example FR30201 ");
						scanf("%s ", barcode);
						while (!isValid(barcode) || !isQrExist(barcode, superMarket)) {
							if (!isValid(barcode)) {
								printf("Enter a barcode. Barcode should be of 7 length exactly \n Must have 2 type prefix letters followed by a 5 digits number. For example FR30201 ");
								scanf("%s ", barcode);
							}
							printf("this barcode do not exist");
							break;
						}

						for (int i = 0; i < superMarket->numOfCustomers; i++) {
							if (superMarket->customerList[i].id == id) {
								currentCustomer = &superMarket->customerList[i];
							}
						}
						for (int i = 0; i < superMarket->numOfItem; i++) {
							if (strcmp(&superMarket->itemsInShop[i]->qr.qr, barcode) == 0) {
								currentProduct = &superMarket->itemsInShop[i];
							}
						}
						addItemToCart(currentProduct, &currentCustomer->shoppingCart);
					}
					else {
						break;
					}
				}
			}
			break;
		case 4:
			printCustomer(superMarket);
			if (superMarket->numOfCustomers == 0) {
				printf("No customer listed to market");
				break;
			}
			else if (superMarket->numOfItem == 0) {
				printf("No product in market - cannot shop");
				break;
			}
			printf("who is shopping? Enter customer id");
			scanf("%9s ", id);
			if (isRegister(superMarket, id)) {
				for (int i = 0; i < superMarket->numOfCustomers; i++) {
					if (superMarket->customerList[i].id == id) {
						currentCustomer = &superMarket->customerList[i];
					}
				}
				printCart(currentCustomer);
			}
			printf("you must be registered");
			break;
		case 5:
			printCustomer(superMarket);
			printf("who is shopping? Enter customer id");
			scanf("%9s ", id);
			if (isRegister(superMarket, id)) {
				for (int i = 0; i < superMarket->numOfCustomers; i++) {
					if (superMarket->customerList[i].id == id) {
						currentCustomer = &superMarket->customerList[i];
					}
				}
				printCart(currentCustomer);
			}
			printf("you must be registered");
			break;
			if(currentCustomer->shoppingCart.itemsCount !=0 ){
				printf("Do you want to pay for the cart Y/y, anything else to cancel shopping!");
				scanf("%s ", choice);
				if (tolower(choice) == 'y') {
					emptyCart(currentCustomer);
					printf("---- payment was recived ----");
				}
				else {
					returnCart(currentCustomer,superMarket);
					printf("---- purchase was canceled ----");
				}
			}
			break;
		case 6:
			type = getTypeFromUser();
			printByType(superMarket,type);
			break;
		case -1:
			break;

		} 
	}while (answer >= -1 && answer <= 6);

}