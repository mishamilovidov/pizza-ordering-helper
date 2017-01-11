#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	/*
	Test Cases:
	1 - 250 Guests, 15% Tip
	Results should be...
	Large Pizzas:			35
	Medium Pizzas:			1
	Small Pizzas:			2
	Total square inches:	11422.8
	Serving square inches:	45.6913
	Total Cost with Tip:	$621
	2 - 100 Guests, 25% Tip
	Results should be...
	Large Pizzas:			14
	Medium Pizzas:			0
	Small Pizzas:			2
	Total square inches:	4624.42
	Serving square inches:	46.2442
	Total Cost with Tip:	$275
	3 - 50 Guests, 0% Tip
	Results should be...
	Large Pizzas:			7
	Medium Pizzas:			0
	Small Pizzas:			1
	Total square inches:	2312.21
	Serving square inches:	46.2442
	Total Cost with Tip:	$110
	*/

	//Section 1: Number of Pizzas Needed

	cout << "Enter how many guests will attend the event: ";
	int number_of_guests;
	cin >> number_of_guests;

	int large = number_of_guests / 7;
	int remainder1 = number_of_guests % 7;
	int medium = remainder1 / 3;
	int remainder2 = remainder1 % 3;
	int small = remainder2 / 1;

	cout << "You will need the following amount of each pizza size:\n\n";
	cout << "Large Pizzas: " << large << endl;
	cout << "Medium Pizzas: " << medium << endl;
	cout << "Small Pizzas: " << small << "\n" << endl;

	//Section 2: Computing Serving Size

	const int RADIUS_LARGE = 10;
	const int RADIUS_MEDIUM = 8;
	const int RADIUS_SMALL = 6;
	const double PI = 3.14159;
	const double AREA_LARGE = (PI * (pow(RADIUS_LARGE, 2)));
	const double AREA_MEDIUM = (PI * (pow(RADIUS_MEDIUM, 2)));
	const double AREA_SMALL = (PI * (pow(RADIUS_SMALL, 2)));

	double total_pizza_area = ((large * AREA_LARGE) + (medium * AREA_MEDIUM) + (small * AREA_SMALL));
	double total_serving_size_area = total_pizza_area / number_of_guests;

	cout << "You need to purchase " << total_pizza_area << " square inches of pizza." << endl;
	cout << "Each guest can eat " << total_serving_size_area << " square inches of pizza.\n" << endl;

	//Section 3: Computing Total Cost

	const double PRICE_LARGE = 14.68;
	const double PRICE_MEDIUM = 11.48;
	const double PRICE_SMALL = 7.28;

	cout << "Enter the percentage of the total price to be paid as a tip: ";
	int tip_amount;
	cin >> tip_amount;

	double pizza_cost = ((large * PRICE_LARGE) + (medium * PRICE_MEDIUM) + (small * PRICE_SMALL));
	double total_cost = (((tip_amount * pizza_cost) / 100) + pizza_cost);

	cout << "The total cost for pizza at this event, with tip, will be about $" << round(total_cost) << "\n" << endl;

	//End of Program

	system("pause");

	return 0;
}