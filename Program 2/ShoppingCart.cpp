//ShoppingCart.cpp

#include "ShoppingCart.h"

//Loop index
unsigned int i;

//default constructor
ShoppingCart::ShoppingCart() {

	customerName = "none";
	currentDate = "January 1, 2016";
}

//parameterized default constructor
ShoppingCart::ShoppingCart(string const& userName, string const& userDate) {

	customerName = userName;
	currentDate = userDate;
}

//returns customer's name 
string ShoppingCart::GetCustomerName() {

	return customerName;
}

//returns date
string ShoppingCart::GetDate() {

	return currentDate;
}

//appends item to the cart
void ShoppingCart::AddItem(ItemToPurchase& NewItem) {

	string new_item;
	string new_description;
	int new_price;
	int new_quantity;

	cin.ignore();

	cout << "ADD ITEM TO CART" << endl;
	cout << "Enter the item name:" << endl;
	getline(cin, new_item);
	NewItem.SetName(new_item);

	cout << "Enter the item description:" << endl;
	getline(cin, new_description);
	NewItem.SetDescription(new_description);

	cout << "Enter the item price:" << endl;
	cin >> new_price;
	NewItem.SetPrice(new_price);

	cout << "Enter the item quantity:" << endl;
	cin >> new_quantity;
	NewItem.SetQuantity(new_quantity);

	cartItems.push_back(NewItem);
}

//removes item from cart
void ShoppingCart::RemoveItem(string& remove_item) {
	
	unsigned int no_item = 0;

	for (i = 0; i < cartItems.size(); i++) {

		if(remove_item == cartItems.at(i).GetName()) {
			cartItems.erase(cartItems.begin() + i);
			no_item++;
		}
	}

	if (no_item == 0) {
		cout << "Item not found in cart. Nothing removed." << endl << endl;
	}
}

//returns number of item in the cart
unsigned int ShoppingCart::GetNumItemsInCart() {

	return cartItems.size();
}

//determines and returns total cost of cart
int ShoppingCart::GetCostOfCart() {

	int total_cost = 0;

	for (i = 0; i < cartItems.size(); i++) {	
		total_cost = total_cost + cartItems.at(i).GetPrice();
	}

	return total_cost;
}

//Modifies selected item's quantity and updates the cart
void ShoppingCart::ModifyItem() {

	string search_name;
	int change_quantity;
	int no_name = 0;

	cout << "CHANGE  ITEM QUANTITY" << endl;
	cout << "Enter the item name:" << endl;
	cin.ignore();
	getline(cin,search_name);

	cout << "Enter the new quantity:" << endl;
	cin >> change_quantity;


	for (i = 0; i < cartItems.size(); i++) {
		if (search_name == cartItems.at(i).GetName()) {
			cartItems.at(i).SetQuantity(change_quantity);
			no_name++;
		}
	}

	if (no_name == 0) {
		cout << "Item not found in cart. Nothing Modified." << endl << endl;
	}
}

//Prints overall information about the cart
void ShoppingCart::PrintTotal() {

	unsigned int quantity_count = 0;

	cout << endl <<"OUTPUT SHOPPING CART" << endl;

	cout << customerName << "'s Shopping Cart - " << GetDate() << endl;

	for (i = 0; i < cartItems.size(); i++) {
		quantity_count = quantity_count + cartItems.at(i).GetQuantity();
	}

	cout << "Number of Items: " << quantity_count << endl << endl;

	for (i = 0; i < cartItems.size(); i++) {
		cartItems.at(i).PrintItemCost();
	}

	if (cartItems.empty()) {
		cout << "SHOPPING CART IS EMPTY" << endl;
	}

	cout << endl << "Total: $" << GetCostOfCart() << endl << endl;
}

//Prints all item's description in the cart
void ShoppingCart::PrintDescription() {

	cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl;

	cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;

	cout << "Item Descriptions" << endl;

	for (i = 0; i < cartItems.size(); i++) {
		cartItems.at(i).PrintItemDescription();
	}
}