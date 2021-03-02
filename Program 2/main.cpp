//Renin Kingsly Jose
//Data Structure and Algorithms
//Online Shopping Cart

//Main.cpp

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

//function declaration for printing menu
char PrintMenu(ShoppingCart &user, char &option);

int main(){

	string user_name;
	string user_date;
	char user_option = 'z';

	cout << "Enter customer's name:" << endl;
	getline(cin, user_name);
	cout << "Enter today's date:" << endl;
	getline(cin, user_date);

	cout << endl << "Customer name: " << user_name << endl;
	cout << "Today's date: " << user_date << endl <<endl;

	//creating ShoppingCart object and setting its private variables
	ShoppingCart user(user_name, user_date);
	
	//repeats until user inputs 'q'
	while(user_option != 'q'){
		user_option = PrintMenu(user, user_option);
	}

	return 0;
}

char PrintMenu(ShoppingCart &user, char &option) {

	ItemToPurchase item;
	string remove;

	cout << "MENU" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Remove item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output items' descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit" << endl << endl;
	
	cout << "Choose an option: " << endl;
	cin >> option;
	cout << endl;

	//checks for errors and prompts user to input correct option
	while ((option != 'a' && option != 'd' && option != 'c') && (option != 'i' && option != 'o' && option != 'q')) {
		cin.ignore();
		cout << "Choose an option: " << endl;
		cin >> option;
	}

	if(option == 'o') {
		user.PrintTotal();
	}
	else if(option == 'i') {
		user.PrintDescription();
	}
	else if(option == 'a') {
		user.AddItem(item);
	}
	else if(option == 'd') {

		cout << "REMOVE ITEM FROM CART" << endl;
		cout << "Enter name of item to remove:" << endl;
		cin.ignore();
		getline(cin,remove);
		user.RemoveItem(remove);
	}
	else if(option == 'c') {
		user.ModifyItem();
	}

	return option;
}