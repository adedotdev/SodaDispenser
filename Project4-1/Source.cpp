#include <iostream>
#include <iomanip>
using namespace std;


struct DrinkInfo {
	string drinkName;
	float drinkPrice;
	int noOfDrinks;
};

class DrinkType {
	DrinkInfo d1 = { "Cola", 1.00, 20 };
	DrinkInfo d2 = { "Root beer", 1.00, 20 };
	DrinkInfo d3 = { "Orange soda", 1.00, 20 };
	DrinkInfo d4 = { "Grape soda", 1.00, 20 };
	DrinkInfo d5 = { "Bottled water", 1.50, 20 };

	// member function declarations
public:
	void displayChoices(DrinkInfo[]);
	void buyDrink(int, float, DrinkInfo[]);

	DrinkInfo structArr[5] = { d1, d2, d3, d4, d5 };

private:
	float inputMoney(int, float);
	void dailyReport(DrinkInfo[]);

	//~DrinkType() { dailyReport(DrinkInfo[]); };
};

	// member function definitions
void DrinkType::displayChoices(DrinkInfo structArr[]) {
	for (int i = 0; i < 5; i++) 
		cout << fixed << setprecision(2) 
			 << (i + 1) << ". " << structArr[i].drinkName 
			 << " - $" << structArr[i].drinkPrice << endl;
	cout << "\nPick a number or input 0 to quit: ";
}

float DrinkType::inputMoney(int choice, float money) {
	float m = 0;
	bool check;
	do {
		check = true;
		money += m;
		switch (choice) {
			case 1:
				if (money < 1.00)
					check = false;
				break;
			case 2:
				if (money < 1.00)
					check = false;
				break;
			case 3:
				if (money < 1.00)
					check = false;
				break;
			case 4:
				if (money < 1.00)
					check = false;
				break;
			case 5:
				if (money < 1.50)
					check = false;
				break;
			default:
				cout << "\nInvalid Input!";
				break;
		}
		if (check == false) {
			cout << "\nInsufficient funds! Add more money: $";
			cin >> m;
		}
	} while (check == false);

	return money;
}

void DrinkType::buyDrink(int choice, float money, DrinkInfo arr[]) {
	DrinkType d;
	char c = 'y';
	float totalMoney = inputMoney(choice, money);

	cout << fixed << setprecision(2) << endl
		 << "Selection:" << setw(10) << d.structArr[choice - 1].drinkName << endl
		 << "Price:" << setw(11) << "$" << d.structArr[choice - 1].drinkPrice << endl
		 << "Money Inputed:" << setw(3) << "$" << totalMoney << endl
		 << "Balanace:" << setw(8) << "$" << totalMoney - (d.structArr[choice - 1].drinkPrice) << endl;

	do {
		cout << "\nDo you wish to make this purchase? (y/n): ";
		cin >> c;

		if (c != 'y' && c != 'n')
			cout << "\nInvalid Input!";
		else if (c == 'n') 
			cout << "\nHere's your money: $" << totalMoney << endl;
		else if (d.structArr[choice - 1].noOfDrinks == 0)
			cout << "\nSold Out! Here's your money: $" << totalMoney << endl;
		else {
			cout << "\nHere's your beverage: " << d.structArr[choice - 1].drinkName << endl;
			cout << "Balance: $" << totalMoney - (d.structArr[choice - 1].drinkPrice);
			arr[choice - 1].noOfDrinks -= 1;
		}
	} while (c != 'y' && c != 'n');
}

void DrinkType::dailyReport(DrinkInfo arr[]) {
	float totalMoneyCollected = 0.0;
	
	cout << "\nDaily Report";
	for (int i = 0; i < 5; i++) {
		cout << arr[i].drinkName << endl
			<< "Number available" << arr[i].noOfDrinks << endl << endl;
		totalMoneyCollected += (20 - arr[i].noOfDrinks) * arr[i].drinkPrice;
	}
	cout << "Total Money Received for the day: $" << totalMoneyCollected;
}


int main() {
	DrinkType drink;
	int choice;
	float money = 0.0;
	do {
		drink.displayChoices(drink.structArr);
		cin >> choice;

		if (choice != 0) {
			cout << "\nInput money: $";
			cin >> money;

			drink.buyDrink(choice, money, drink.structArr);
		}
	
	} while (choice != 0);
	cout << "Goodbye...";

	return 0;
}