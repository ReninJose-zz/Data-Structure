//ShoppingCart.h

#ifndef ShoppingCart_h
#define ShoppingCart_h

#include<iostream>
#include<string>
#include<vector>
using namespace std;

#include "ItemToPurchase.h"

class ShoppingCart {
public:
	//Default Constructors
	ShoppingCart();
	ShoppingCart(string const& userName, string const& userDate);

	//accessors
	string GetCustomerName();
	string GetDate();

	void AddItem(ItemToPurchase& NewItem);
	void RemoveItem(string& remove_item);
	void ModifyItem();
	unsigned int GetNumItemsInCart();
	int GetCostOfCart();

	void PrintTotal();
	void PrintDescription();

private:
	string customerName;
	string currentDate;
	vector <ItemToPurchase> cartItems;
};

#endif