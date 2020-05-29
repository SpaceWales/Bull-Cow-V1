#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

//5-28-20
//authored by a dumbass
//version 1

//bulls & cows
/*NOTES:::
vector of 4 different integers 0-9
guess number by repeated guesses

bull- right number and right position
cow- right number and wrong position
win condition is 4 bulls

set vector size 
use rand to generate 4 numbers 
cross check they are all different
generate 1 at a time, check against previous

get 4 numbers (int or char?) from uesr
store in 4 different variables
check against position in vector
print bull or cow

if win condition is not met, repeat

have function to get numbers, bool condition to repeat if win condition is not met*/


//generate 4 random numbers and store in vector 

//create a vector and shuffle it, rand was just not working quite right
vector<int>num_list{ 0,1,2,3,4,5,6,7,8,9 };
vector<int>bull(4);
void do_the_shuffle() {
	//shuffle the number list so bull can pick 4 numbers
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(num_list.begin(), num_list.end(), default_random_engine(seed));
}
void bull_numbers() {
	//assign the first 4 numbers to bull 
	for (int x = 0; x < 4; x++) {
		bull[x] = num_list[x];
	}
}

int main() {
	start: //goto
	do_the_shuffle();//pretty self explanatory
	bull_numbers();//get 4 random numbers into bull vector
	//testing purposes printing bull numbers
	//comment this out if you want to play fr fr
	for (int x = 0; x < bull.size(); x++) {
		cout << x << "-" << bull[x] << '\n';
	}
	
	cout << "welcome to the weirdest named game out there!\n";
	cout << "gonna need 4 integers between 0-9\n0 1 2 3\n";
	int attempts = 0;
	//start loop here with win condition
	bool win = false;
	while (win == false) {
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		cin >> a >> b >> c >> d;
		//out of range error, this is a mild first attempt not really sure how to set up yet
		/*while (a<0||a>9)//this is fucked too {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "input was not in range, try again: \n";
			cin>>//something
		}*/

		attempts++;
		//put user choices into a vector
		vector<int>user(4);
		user[0] = a;
		user[1] = b;
		user[2] = c;
		user[3] = d;
		//i can compare the vectors for the same position, but how the heck do you compare the WRONG position?
		//exact match, compare vectors, print bull
		//second loop compare variables if == number && != x? 

		//bull loop
		int bull_count = 0;
		for (int x = 0; x < bull.size(); x++) {
			if (user[x] == bull[x]) {
				bull_count++;
			}
		}
		cout << bull_count << " bull" << '\n';
		//comparing some cows
		int cow_count = 0;
		for (int x = 0; x < bull.size(); x++) {
			if (bull[x] == a) {
				if (bull[x] != user[x]) {
					cow_count++;
				}
			}
			else if (bull[x] == b) {
				if (bull[x] != user[x]) {
					cow_count++;
				}
			}
			else if (bull[x] == c) {
				if (bull[x] != user[x]) {
					cow_count++;
				}
			}
			else if (bull[x] == d) {
				if (bull[x] != user[x]) {
					cow_count++;
				}
			}
		}
		cout << cow_count << " cow" << '\n';
		if (bull_count == 4) {
			win = true;
		}
		else {
			bull_count = 0;
			cow_count = 0;
			cout << "again!: \n";

		}
	}

	cout << "congrats!\n";
	cout << attempts << " attempts!";

	//ability to restart 
	cout << "\nwould you like to play again? y or n \n";
	char play_again = ' ';
	cin >> play_again;
	if (play_again == 'n')
		cout << "\nbye!";
	else if (play_again == 'y')
		goto start;
	else
		cout << "\nnot a choice, exiting!";
	return 0;
}