#include <iostream>	
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

/*SAT = saturn*/

const double USA_SMALL = 6.0, USA_MEDIUM = 9.0, USA_LARGE = 12.0,
CAN_SMALL = 8.0, CAN_MEDIUM = 12.0, CAN_LARGE = 15.0,
AUS_SMALL = 10.0, AUS_MEDIUM = 14.0, AUS_LARGE = 17.0,
SAT_SMALL = 20.0, SAT_MEDIUM = 34.0, SAT_LARGE = 45.0, ELSE_NUM = 0.0,
LOW_PRICE_RANGE = 50.0, MED_PRICE_RANGE = 100.0, HIGH_PRICE_RANGE = 150.0;
const char TITLE_CHAR = '.', THANKS_CHAR = '-';
const int CHAR_LENGTH_1 = 50, CHAR_LENGTH_2 = 40;
const string TITLE_WORDS = "ITCS 2530 - Programming Assignment for week #3";



int main() {
	//declare variables
	string itemName, destination, outString;
	char fragility;
	double orderTotal, shippingCost;
	ofstream outFile;

	//open the output file
	outFile.open("Order.txt");

	//print the headings to the screen
	cout << setfill(TITLE_CHAR);
	cout << setw(CHAR_LENGTH_1) << TITLE_CHAR << endl;
	cout << TITLE_WORDS << endl;
	cout << setfill(TITLE_CHAR);
	cout << setw(CHAR_LENGTH_1) << TITLE_CHAR << endl << endl;

	//print the headings to the output file
	outFile << setfill(TITLE_CHAR);
	outFile << setw(CHAR_LENGTH_1) << TITLE_CHAR << endl;
	outFile << TITLE_WORDS << endl;
	outFile << setfill(TITLE_CHAR);
	outFile << setw(CHAR_LENGTH_1) << TITLE_CHAR << endl << endl;

	//prompt for information
	
	cout << setfill(TITLE_CHAR);
	
	outString = "Please enter the item name (no spaces)";
	cout << outString << setw(CHAR_LENGTH_1 - outString.length()) << ":";
	cin >> itemName;
	// print item name question and answer to output file
	outFile << outString << setw(CHAR_LENGTH_1 - outString.length()) << ":";
	outFile << itemName << endl;

	outString = "Is the item fragile? (y=yes/n=no)";
	cout << outString << setw(CHAR_LENGTH_1 - outString.length()) << ":";
	cin >> fragility;

	// print fragility question and answer to output file
	outFile << outString << setw(CHAR_LENGTH_1 - outString.length()) << ":";
	outFile << fragility << endl;

	outString =  "Please enter your order total";
	cout << outString << setw(CHAR_LENGTH_1 - outString.length()) << ":";
	cin >> orderTotal;

	// print order total question and answer to output file
	outFile << outString << setw(CHAR_LENGTH_1 - outString.length()) << ":";
	outFile << orderTotal << endl;

	outString =  "Please enter destination. (usa/can/aus/sat)";
	cout << outString << setw(CHAR_LENGTH_1 - outString.length()) << ":";
	cin >> destination;
	cout << endl;

	// print destination question and answer to output file
	outFile << outString << setw(CHAR_LENGTH_1 - outString.length()) << ":";
	outFile << destination << endl << endl;

	//calculate and compare information
	transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

	//print error message and exit program if incorrect country selected
	if (destination != "USA" && destination != "CAN" && destination != "AUS" && destination != "SAT")
	{
		cout << "invalid entry, exiting" << endl;
		system("PAUSE");
		return 0;
	}

	//choose shipping cost based on country
	switch (destination[0])
	{
	case 'u':
	case 'U':
		if (orderTotal <= LOW_PRICE_RANGE)
		{
			shippingCost = USA_SMALL;
		}
		else if (orderTotal > LOW_PRICE_RANGE && orderTotal <= MED_PRICE_RANGE)
		{
			shippingCost = USA_MEDIUM;
		}
		else if (orderTotal > MED_PRICE_RANGE && orderTotal <= HIGH_PRICE_RANGE)
		{
			shippingCost = USA_LARGE;
		}
		else
		{
			shippingCost = ELSE_NUM;
		}
		break;
	case 'c':
	case 'C':
		if (orderTotal <= LOW_PRICE_RANGE)
		{
			shippingCost = CAN_SMALL;
		}
		else if (orderTotal > LOW_PRICE_RANGE && orderTotal <= MED_PRICE_RANGE)
		{
			shippingCost = CAN_MEDIUM;
		}
		else if (orderTotal > MED_PRICE_RANGE && orderTotal <= HIGH_PRICE_RANGE)
		{
			shippingCost = CAN_LARGE;
		}
		else
		{
			shippingCost = ELSE_NUM;
		}
		break;
	case 'a':
	case 'A':
		if (orderTotal <= LOW_PRICE_RANGE)
		{
			shippingCost = AUS_SMALL;
		}
		else if (orderTotal > LOW_PRICE_RANGE && orderTotal <= MED_PRICE_RANGE)
		{
			shippingCost = AUS_MEDIUM;
		}
		else if (orderTotal > MED_PRICE_RANGE && orderTotal <= HIGH_PRICE_RANGE)
		{
			shippingCost = AUS_LARGE;
		}
		else
		{
			shippingCost = ELSE_NUM;
		}
		break;
	case 's':
	case 'S':
		if (orderTotal <= LOW_PRICE_RANGE)
		{
			shippingCost = SAT_SMALL;
		}
		else if (orderTotal > LOW_PRICE_RANGE && orderTotal <= MED_PRICE_RANGE)
		{
			shippingCost = SAT_MEDIUM;
		}
		else if (orderTotal > MED_PRICE_RANGE && orderTotal <= HIGH_PRICE_RANGE)
		{
			shippingCost = SAT_LARGE;
		}
		else
		{
			shippingCost = ELSE_NUM;
		}
		break;
	default:
		cout << "invalid entry, exiting" << endl;
		system("PAUSE");
		return 0;
		break;
	}
	// add extra shipping cost if item is fragile
	if (fragility == 'y' || fragility == 'Y')
		shippingCost += 2.0;
	else if (fragility == 'n' || fragility == 'N')
		shippingCost = shippingCost;
	else
	{
		cout << "invalid entry, exiting" << endl;
		system("PAUSE");
		return 0;
	}
	
	//convert itemName string to uppercase
	transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);

	
	//output final variables
	cout << setfill(TITLE_CHAR)<<fixed<<showpoint<<setprecision(2);
	
	outFile << fixed << showpoint << setprecision(2);

	outString = "Your item is ";
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << itemName;
	cout << endl;

	outFile << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << itemName;
	outFile << endl;

	outString = "Your shipping cost is ";
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << "$" << shippingCost;
	cout << endl;

	outFile << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << "$" << shippingCost;
	outFile << endl;

	outString = "You are shipping to ";
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << destination;
	cout << endl;

	outFile << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << destination;
	outFile << endl;

	outString = "Your total shipping costs are";
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << "$" << shippingCost + orderTotal;
	cout << endl<<endl;					

	outFile << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << "$" << shippingCost + orderTotal;
	outFile << endl << endl;

	cout << setfill(THANKS_CHAR);
	cout << setw(CHAR_LENGTH_2) << THANKS_CHAR << "Thank You!" << endl;

	outFile << setfill(THANKS_CHAR);
	outFile << setw(CHAR_LENGTH_2) << THANKS_CHAR << "Thank You!" << endl;

	outFile.close();

	system("PAUSE");

	return 0;
}
/*Code I didn't use - couldn't work out why my setw wasn't working

cout << setfill(TITLE_CHAR);

	outString = "Your item is ";
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << itemName;
	cout << endl;
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << itemName;
	cout << endl;

	outString = "Your shipping cost is ";
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << "$" << shippingCost;
	cout << endl;
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << "$" << shippingCost;
	cout << endl;

	outString = "You are shipping to ";
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << destination;
	cout << endl;
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << destination;
	cout << endl;

	outString = "Your total shipping costs are";
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << "$" << shippingCost + orderTotal;
	cout << endl;
	cout << outString << setw(CHAR_LENGTH_2 - outString.length()) << TITLE_CHAR << "$" << shippingCost + orderTotal;
	cout << endl;
*/