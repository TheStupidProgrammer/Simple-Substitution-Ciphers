/*
Author: Spencer Dalling
Date:10/19/2018
Project: Final Project:] Caesar Shift Cipher
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>
#include <array>
using namespace std;

string Alphabet[2][26] = { 
	{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"},
	{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q" ,"r", "s", "t", "u", "v", "w", "x", "y", "z"} 
};

string word;
string choice;
string file = "";
int select = 0;

string caesarCipher(string word, int num);
string caesarDecipher(string word, int num);
string affineCipher(string word);
string affineDecipher(string word);
void codeMenu();
void decodeMenu();
int num = 0;

int main()
{	
	cout << "Welcome, please select a function:" << endl << "1> Encrypt " << endl << "2> Decrypt" << endl << "3> Quit" << endl << ">> ";
	cin >> select;
	while (select != 3)
	{
		if (select == 1)
		{
			codeMenu();
		}
		if (select == 2)
		{
			decodeMenu();
		}
		if (select > 3 || select < 1)
		{
			cout << "Error: Invalid selection\n" << endl;
			cout << "Welcome, please select a function:" << endl << "1> Encrypt " << endl << "2> Decrypt" << endl << "3> Quit" << endl << ">> ";
			cin >> select;
		}
	}
	return 0;
}

void codeMenu()
{
	while (select != 3)
	{
		cout << "You've selected '1', please select a function" << endl << "1> Caesar Shift Cipher" << endl << "2> Affine Cipher" << endl;
		cout << "3> Return to main function selection" << endl << ">> ";
		cin >> select;
		if (select == 1)
		{
			do
			{
				ofstream outFile;
				
				cout << "Please enter the shift number\n" << ">> ";
				cin >> num;
				getline(cin, word);
				cout << "Please enter a sentence to be encoded\n" << ">> ";
				getline(cin, word);

				word = caesarCipher(word, num);
				outFile.open("CaesarCipher.txt", ios::out);
				cout << word << endl;
				outFile << word << "\n";
				outFile.close();
				cout << endl << "Would you like to add more? y/n\n" << ">> ";
				cin >> choice;
				if (choice == "y")
				{
					choice = "";
					while (choice != "n")
					{
						getline(cin, word);
						cout << "Please enter a sentence to be encoded\n" << ">> ";
						getline(cin, word);

						word = caesarCipher(word, num);
						outFile.open("CaesarCipher.txt", ios::app);
						cout << word << "\n" << endl;
						outFile << word << "\n";
						outFile.close();
						cout << endl << "Would you like to add more? y/n\n" << ">> ";
						cin >> choice;
						if (choice != "y" && choice != "n")
						{
							cout << "Error: Invalid selection\n";
							choice = "y";
						}
					}
				}
				else if (choice != "y" && choice != "n")
				{
					cout << "Error: Invalid selection\n";
					choice = "y";
				}
			} while (choice != "n");
			
		}
		if (select == 2)
		{
			ofstream outFile;
			do
			{
				getline(cin, word);
				cout << "Please enter text to be encoded\n" << ">> ";
				getline(cin, word);

				word = affineCipher(word);

				outFile.open("AffineCipher.txt", ios::out);
				cout << word << "\n" << endl;
				outFile << word << "\n";
				outFile.close();
				cout << "Would you like to add more? y/n\n" << ">> ";
				cin >> choice;
				if (choice == "y")
				{
					getline(cin, word);
					cout << "Please enter text to be encoded\n" << ">> ";
					getline(cin, word);

					word = affineCipher(word);

					outFile.open("AffineCipher.txt", ios::app);
					cout << word << "\n" << endl;
					outFile << word << "\n";
					outFile.close();
					cout << "Would you like to add more? y/n\n" << ">> ";
					cin >> choice;
				}
				else if (choice != "n")
				{
					cout << "Error: Invalid selection\n";
					choice = "y";
				}
			} while (choice != "n");
		}
		if (select > 3 || select < 1)
		{
			cout << "Error: Invalid selection\n" << endl;
		}
	}
	main();
}

void decodeMenu()
{
	cout << "You've selected '2', please select a function\n" << "1> Decode Caesar Shift Cipher\n" << "2> Decode Affine Cipher\n";
	cout << "3> Return to main function selection\n" << ">> ";
	cin >> select;

	while (select != 3)
	{
		if (select == 1)
		{
			while (select != 3)
			{
				ifstream inFile;
				cout << "You've chosen to decrypt the Caesar Cipher\n" << "1> Enter file to be decrypted\n" << "2> Enter text to be decrypted\n" << "3> Return to main selection\n";
				cout << ">> ";
				cin >> select;
				if (select == 1)
				{
					ifstream inFile;

					cout << "Please enter the file URL\n" << ">> ";
					cin >> file;
					cout << "Please enter the shift code, or enter zero if you don't know the shift code\n" << ">> ";
					cin >> num;
					start:
					inFile.open(file, ios::in);
					if (num > 0)
					{
						do 
						{
							getline(inFile, word);
							word = caesarDecipher(word, num);
							cout << word << endl;
						} while (inFile.eof() == false);
					}
					if (num < 1)
					{
						do
						{
							num = 1;
							string word1 = "";
							getline(inFile, word);
							for (string choice = ""; num <= 25; num++)
							{
								
								word1 = caesarDecipher(word, num);
								cout << num << "> " << word1 << endl << "Is this correct? y/n\n" << ">> ";
								cin >> choice;
								if (choice == "y")
								{
									cout << "The shift code was " << num << endl << endl;
									inFile.close();
									goto start;
								}
								else if (choice != "n")
								{
									cout << "Error: invalid selection\n";
									num--;
								}
							}
						} while (inFile.eof() == false);
					}
					inFile.close();
				}
				if (select == 2)
				{
					num = 0;
					cout << "Please enter the shift code, or enter zero if you don't know the shift code\n" << ">> ";
					cin >> num;
					getline(cin, word);
					cout << "Enter text to be decrypted\n" << ">> ";
					getline(cin, word);
					if (num < 1)
					{
						num = 1;
						string word1 = "";
						for (string choice = ""; num <= 25; num++)
						{
							word1 = caesarDecipher(word, num);
							cout << num << "> " << word1 << endl << "Is this correct? y/n\n" << ">> ";
							cin >> choice;
							if (choice == "y")
							{
								cout << "The shift code was " << num << endl;
								num = 27;
							}
							else if (choice != "n")
							{
								cout << "Error: invalid selection\n";
								num--;
							}
						}
					}
					else
					{
						word = caesarDecipher(word, num);
						cout << word << endl;
					}
				}
				if (select < 1 || select > 3)
				{

				}
			}
		}
		if (select == 2)
		{
			while (select != 3)
			{
				ifstream inFile;
				cout << "You've chosen to decrypt the Affine Cipher\n" << "1> Enter file to be decrypted\n" << "2> Enter text to be decrypted\n" << "3> Return to main selection\n";
				cout << ">> ";
				cin >> select;
				if (select == 1)
				{
					ifstream inFile;

					cout << "Please enter the file URL\n" << ">> ";
					cin >> file;
					inFile.open(file, ios::in);
					do
					{
						getline(inFile, word);
						word = affineDecipher(word);
						cout << word << endl;
					} while (inFile.eof() != true);
					inFile.close();
				}
				else if (select == 2)
				{
					getline(cin, word);
					cout << "Enter text to be decrypted\n" << ">> ";
					getline(cin, word);

					word = affineDecipher(word);

					cout << word << endl;
				}
				else if (select > 3 || select < 1)
				{
					cout << "Error: Invalid selection\n";
				}
			}
		}
		if (select > 3 || select < 1)
		{
			cout << "Error: Invalid selection\n" << endl;
		}
	}
	main();
}

string caesarCipher(string word, int num)
{
	string cipherAlphabet[2][26] = { {""}, {""} };
	int shift = 26 - num;

	for (int x = 0; x <= 25; x++)
	{
		cipherAlphabet[0][x] = Alphabet[0][shift];
		cipherAlphabet[1][x] = Alphabet[1][shift];
		shift++;
		if (shift > 25)
		{
			shift = 0;
		}
	}

	for (int x = 0; x <= word.length(); x++)
	{
		for (int y = 0; y <= 25; y++)
		{
			if (word.substr(x, 1) == Alphabet[0][y])
			{
				word.replace(x, 1, cipherAlphabet[0][y]);
				y = 26;
			}
			if (word.substr(x, 1) == Alphabet[1][y])
			{
				word.replace(x, 1, cipherAlphabet[1][y]);
				y = 26;
			}
		}
	}
	return word;
}

string caesarDecipher(string word, int num)
{
	string cipherAlphabet[2][26] = { {""}, {""} };
	int shift = 26 - num;

	for (int x = 0; x <= 25; x++)
	{
		cipherAlphabet[0][x] = Alphabet[0][shift];
		cipherAlphabet[1][x] = Alphabet[1][shift];
		shift++;
		if (shift > 25)
		{
			shift = 0;
		}
	}

	if (num > 0)
	{
		for (int x = 0; x <= word.length(); x++)
		{
			for (int y = 0; y <= 25; y++)
			{
				if (word.substr(x, 1) == cipherAlphabet[0][y])
				{
					word.replace(x, 1, Alphabet[0][y]);
					y = 26;
				}
				if (word.substr(x, 1) == cipherAlphabet[1][y])
				{
					word.replace(x, 1, Alphabet[1][y]);
					y = 26;
				}
			}
		}
	}
	return word;
}

string affineCipher(string word)
{
	int rem = 0;
	for (int x = 0; x <= word.length(); x++)
	{
		for (int y = 0; y <= 25; y++)
		{
			if (word.substr(x, 1) == Alphabet[0][y])
			{
				rem = ((5 * y) + 8) % 26;
				word.replace(x, 1, Alphabet[0][rem]);
				y = 26;
			}
			if (word.substr(x, 1) == Alphabet[1][y])
			{
				rem = ((5 * y) + 8) % 26;
				word.replace(x, 1, Alphabet[1][rem]);
				y = 26;
			}
		}
	}
	return word;
}

string affineDecipher(string word)
{
	int rem = 0;
	for (int x = 0; x <= word.length(); x++)
	{
		for (int y = 0; y <= 25; y++)
		{
			if (word.substr(x, 1) == Alphabet[0][y])
			{
				rem = ((21 * (y - 8)) % 26) + 26;
				if (rem > 25)
				{
					rem += -26;
				}
				word.replace(x, 1, Alphabet[0][rem]);
				y = 26;
			}
			else if (word.substr(x, 1) == Alphabet[1][y])
			{
				rem = ((21 * (y - 8)) % 26) + 26;
				if (rem > 25)
				{
					rem += -26;
				}
				word.replace(x, 1, Alphabet[1][rem]);
				y = 26;
			}
		}
	}
	return word;
}