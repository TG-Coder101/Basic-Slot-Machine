//Display 3 columns of characters on the console window
//When the game play begins, the characters in each column should rotate rapidly(i.e.intentionally overprint at the same location)
//The user can choose when to stop the first column from rotating, then the second column, and finally stop the third column.
//If the symbols in all three columns are the same, display a message indicating that the user has hit the jackpot
//If the symbols in only two columns are the same, provide a smaller jackpot prize


#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

const char [26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char fruit_machinalphabete[3][3];


void generator()
//Generates a 3x3 array for the slot machine 
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
		
			int roll = rand() % 26;        //Generates a random string of characters
			char x = alphabet[roll];
			cout << x << " ";

		}
		cout << endl;
	}
}

void spinner2(int column)
{
	int roll = rand() % 26;
	//shifts one column down 
	fruit_machine[2][column] = fruit_machine[1][column];
	fruit_machine[1][column] = fruit_machine[0][column];
	fruit_machine[0][column] = alphabet[roll];
}

void output()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << fruit_machine[i][j] << "  ";



		}

		cout << endl << endl;
	}
}

void spinner()
{
	while (!(GetKeyState(VK_SPACE) & 0x8000))
	{
		spinner2(0);
		spinner2(1);
		spinner2(2);
		system("cls");
		output();
	}
}


int main()
{
	//variables
	string spin;
	string leave;
	string stop;
	string inputb;

	srand(time(0));
	char fruit_machine[3][3];

	generator();
	spinner2(0);
	spinner2(1);
	spinner2(2);
	spinner();
		
		system("pause");

		return 0;
 }