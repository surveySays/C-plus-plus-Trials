#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool BlackJackCheck(char Cards[]);

int ConvertAscii(int Card);

bool CheckValidCard(char Card);

int main()
{
	char Cards[3];

	cout << "Card options: [A,1,2,3,4,5,6,7,8,9,10,J,Q,K]" << endl;

	for (size_t i = 0; i < 3; ++i){
		cout << "Enter a card: ";
		cin >> Cards[i];

		while (!CheckValidCard(Cards[i])){
		
			cout << "Not a card Option." << endl;

			cout << "Enter a card: ";
			cin >> Cards[i];
		}
		
		cout << endl;
	}

	if (BlackJackCheck(Cards)){
		cout << endl << "Winner" << endl;
	}
	else {
		cout << endl << "Busted" << endl;
	}

	system("pause");
	return 0;
}

bool BlackJackCheck(char Cards[]){

	int total{ 0 };

	for (size_t i = 0; i < 3; ++i) {
		total = total + ConvertAscii(static_cast<int>(Cards[i]));
	}
	
	if (total > 21) {
		cout << total << endl;
		return false;
	}

	cout << total << endl;
	return true;
}

int ConvertAscii(int Card){

	if (Card >= 65) {
		if (Card == 65) {
			return 1; // value of A
		}
		else {
			return 10; //value of J,Q,K
		}
	}
	else {
		return Card - 48; //return ascii int value 
	}
}

bool CheckValidCard(char Card) {

	char ValidCards[] = { 'A', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};

	for (size_t i = 0; i < 14; ++i) {
		if (Card == ValidCards[i]) {
			return true;
		}
	}

	return false;
}


