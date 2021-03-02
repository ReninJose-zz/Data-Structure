//ItemToPurchase.cpp

#include "ItemToPurchase.h"

//Default  Constructor
ItemToPurchase::ItemToPurchase() {
	itemName = "none";
	itemDescription = "none";
	itemPrice = 0;
	itemQuantity = 0;
}

//parameterized constructor
ItemToPurchase::ItemToPurchase(string const& item_name, string const& item_description, int const& item_price, int const& item_quantity) {
	itemName = item_name;
	itemDescription = item_description;
	itemPrice = item_price;
	itemQuantity = item_quantity;
}

//sets item's name
void ItemToPurchase::SetName(string Name) {

	itemName = Name;
}

//sets item's price
void ItemToPurchase::SetPrice(int Price) {

	itemPrice = Price;
}

//sets quantity of the item
void ItemToPurchase::SetQuantity(int Quantity) {

	itemQuantity = Quantity;
}

//Set decription of the item
void ItemToPurchase::SetDescription(string Description) {

	itemDescription = Description;
}

//returns item's name
string ItemToPurchase::GetName() {

	return itemName;
}

//returns item's price
int ItemToPurchase::GetPrice() {

	return itemPrice;
}

//returns item's quantity
int ItemToPurchase::GetQuantity() {

	return itemQuantity;
}

//returns item's description
string ItemToPurchase::GetDescription() {

	return itemDescription;
}

//multiples price and quantity and updates item's price value
void ItemToPurchase::totalPrice() {

	itemPrice = itemPrice * itemQuantity;
}

//prints Item's cost
void ItemToPurchase::PrintItemCost() {

	cout << GetName() << " " << GetQuantity() << " @ $" << GetPrice();
	totalPrice();
	cout << " = $" << GetPrice() << endl;
}

//prints item's description
void ItemToPurchase::PrintItemDescription() {

	cout << GetName() << ": " << itemDescription << endl;
}