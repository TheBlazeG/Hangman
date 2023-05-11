#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> Words = { "MANGO","BANANA","APPLE","ORANGE","KIWI" };
vector<int>::const_iterator iter;
int Lives = 6;
bool Win;
int play;
char letter;
string Usedletters;
int main()
{
	do
	{
		system("cls");
	cout << "Welcome to Hangman! \nDo you want to play(1) or leave(0) the game?";
	cin >> play;
	if (play==1)
	{
		Win = false;
		srand(time(NULL));
		int Randomword = rand();
		int WordsRandomIndex = (Randomword % Words.size());
		string Wordused = (Words[WordsRandomIndex]);
		const string WORD=Wordused;
		string soFar(WORD.size(), '_');
		string letterUsed;
		do
		{
			system("cls");
			switch (Lives)
			{
			case 6:
				cout << "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========";

				break;
			case 5:
				cout << "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========";
				break;
			case 4:
				cout << "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========";
				break;
			case 3:
				cout << "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========";
				break;
			case 2:
				cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========";
				break;
			case 1:
				cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n   \\  |\n      |\n=========";
				break;
			case 0:
				cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========";
				break;
			default:
				break;
			}
			cout << "Write a letter to use in Hangman, the next is the letter spaces in the word\n"<<soFar<<endl<<letterUsed<<endl;
			do
			{
				cin >> letter;
			} while (letterUsed.find(letter)!= string::npos);
			
			letter=toupper(letter);
			if (WORD.find(letter)!= string::npos)
			{
				for (int i = 0; i < WORD.length(); i++)
				{
					if (WORD[i]==letter)
					{
						soFar[i] = letter;
					}
				}
			}
			else
			{
				Lives--;
			}
			letterUsed.push_back(letter);
			
			
			if (soFar==WORD)
			{
				cout <<soFar<< "\nYou Won!!";
				Win = true;
				system("pause");
			}
			if (Lives==0)
			{
				cout <<soFar<< "\nYou Lost!!";
				Win = true;
				system("pause");
			}

		} while (Win == false);
	}
	if (play==2)
	{
		cout << "Are you sure you want to quit? (2)Yes (1)No" << endl;
		cin >> play;
	}
	

	} while (play==1);
}