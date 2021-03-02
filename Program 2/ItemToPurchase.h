//ItemsToPurchase.h

#ifndef ItemToPurchase_h
#define ItemToPurchase_h

#include<iostream>
#include <string>

using namespace std;

class ItemToPurchase {
public:
	//Default Constructors
	ItemToPurchase();
	ItemToPurchase(string const& item_name, string const& item_description, int const& item_price, int const& item_quantity);

	//Mutators
	void SetName(string Name);
	void SetDescription(string Description);
	void SetPrice(int Price);
	void SetQuantity(int Quantity);

	//Accessors
	string GetName();
	string GetDescription();
	int GetPrice();
	int GetQuantity();

	void totalPrice();
	void PrintItemCost();
	void PrintItemDescription();

private:
	string itemName;
	string itemDescription;
	int itemPrice;
	int itemQuantity;
};

#endif
