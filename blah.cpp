// blah.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> // for random number generation
#include <ctime> // for seeding random numbers
using namespace std;
/*
int main()
{
	//declare name constant and variables
	int score1 = 0;
	int score2 = 0;

	//enter the first score and the second score
	cout << "First score: ";
	cin >> score1;
	cout << "Second score: ";
	cin >> score2;

	//if (the first score is greater then the secons score) swap the scores so that the first score is the lowest score
	if (score1 > score2)
	{
		int temp = 0;
		temp = score1;
		score1 = score2;
		score2 = temp;
	} //end if

	//display the first score and the second score
	cout << "Lowest: " << score1 << endl;
	cout << "Highest: " << score2 << endl;
 }
 */

int main()
{

	// seed random number generator
	srand(static_cast<unsigned int>(time(0)));

	// declare variables for scores
	int score1 = 0;
	int score2 = 0;

	// welcome message with a fun tone
	cout << "Welcome to the Ultimate Score Comparison Challenge!" << endl;
	cout << "You'll enter two scores, and I'll tell you which one is higher!" << endl;

	// get the first from the user with error checking
	while (true) {
		cout << "Enter the first score (between 0 and 100): ";
		cin >> score1;

		// check if input is valid		
		if (cin.fail() || score1 < 0 || score1 > 100) {
			cout << "Oops! Please enter a valid score between 0 and 100." << endl;
			cin.clear(); // clear the error flag
			cin.ignore(1000, '\n'); // discard invalid input
		}
		else {
			break;
		}
	}
	// get the second score from the user with error checking
	while (true) {
		cout << "Enter the second score (between 0 and 100): ";
		cin >> score2;

		//check if input is valid
		if (cin.fail() || score2 < 0 || score2 > 100) {
			cout << "Oops! Please enter a valid score between 0 and 100." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			break;
		}
	}

	// fun randomized event - random chance to swap scores without user knowing
	if (rand() % 2 == 0) {
		cout << "A twist in the game! Something mysterious might happen to your scores ..." << endl;
		swap(score1, score2); // using built-in swap function
	}

	//ensure the lowest number is in score1
	if (score1 > score2) {
		swap(score1, score2); // simpler swap function
	}

	// display the results in a fun way
	cout << "Drumroll please... 🥁" << endl;
	cout << "and the lowest score is: " << score1 << "!" << endl;
	cout << "the highest score is: " << score2 << "!" << endl;

	// bonus interaction: ask id the player wants to play again
	char choice;
	cout << "Would you like to compare scores again? (y/n): ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y') {
		cout << "Great! Let's do this again! 🎉" << endl;
		main(); // Call main again for a reply (not the best practice, but fun for now)
	}
	else {
		cout << "Thanks for playing! Come back soon! 😊" << endl;
	}

	return 0;
} 