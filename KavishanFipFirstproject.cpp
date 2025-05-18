#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Palyer Information
struct Player
{
	string RegistrationNo;
	string FirstName;
	string LastName;
	string DateOfBirth;
	string Team;
	double Runscored;

};

Player players[20];//Array To store Up to 20 Players
int playercount = 0; // current Count of players 
string UserLogin = "";//user's login information
bool loginStart = false;

void LogIn()
{
	string UserName;
	string Password;

	cout << "\t" << " 01.EnTer The User Name : ";
	cin >> UserName;
	cout << "\n""\n";

	cout << "\t" << " 02.EnTer The User Password : ";
	cin >> Password;
	cout << "\n""\n";

	if (UserName == "KAVISHAN" && Password == "KAVI1234")
	{
		UserLogin = UserName;
		cout << "\t" << " ||Logging In Is Successful||";
		cout << "\n""\n";
		loginStart = true;
	}
	else
	{
		cout << "\t" << " ||Invalid Credentials. Try Again Another Time||";
		cout << "\n""\n";
	}

}




void AddNewPlayer()
{
	Player NewPlayer;
	cout << "\t" << " 01. Enter The Registration Number :  ";
	cin >> NewPlayer.RegistrationNo;
	cout << "\n""\n";

	cout << "\t" << " 02. Enter The  First Name :  ";
	cin >> NewPlayer.FirstName;
	cout << "\n""\n";

	cout << "\t" << " 03. Enter The  Last Name :  ";
	cin >> NewPlayer.LastName;
	cout << "\n""\n";

	cout << "\t" << " 04. Enter The  Date Of Birth (YYYY:MM:DD:) :  ";
	cin >> NewPlayer.DateOfBirth;
	cout << "\n""\n";

	cout << "\t" << " 05. Enter The Runs Scored :  ";
	cin >> NewPlayer.Runscored;
	cout << "\n""\n";

	cout << "\t" << " 06. Enter The  Team  :  ";
	cin >> NewPlayer.Team;
	cout << "\n""\n";


	players[playercount++] = NewPlayer;
	cout << "\t" << "||The Player Has Been Successfully Added||";
	cout << "\n""\n";

}

void DisplayPlayers()
{
	for (int i = 0; i < playercount; i++)
	{
		cout << "\t" << " 01. ResistraTion Number : " << players[i].RegistrationNo << "\n""\n";
		cout << "\t" << " 02. Full Name : " << players[i].FirstName << players[i].LastName << "\n""\n";
		cout << "\t" << " 03. Date Of Birth : " << players[i].DateOfBirth << "\n""\n";
		cout << "\t" << " 04. Runscored : " << players[i].Runscored << "\n""\n";
		cout << "\t" << " 05. Team  : " << players[i].Team << "\n""\n";
		cout << "\n""\n";;

	}
}

void SearchPlayers()
{
	string RegistrationNo;
	cout << "\t" << " To Start A Search, Enter The Registration Number : ";
	cin >> RegistrationNo;
	cout << "\n""\n";

	bool found = false;
	for (int i = 0; i < playercount; i++)
	{
		if (players[i].RegistrationNo == RegistrationNo)
		{
			cout << "\t" << " 01. ResistraTion Number : " << players[i].RegistrationNo << "\n""\n";
			cout << "\t" << " 02. Full Name : " << players[i].FirstName << players[i].LastName << "\n""\n";
			cout << "\t" << " 03. Date Of Birth : " << players[i].DateOfBirth << "\n""\n";
			cout << "\t" << " 04. Runscored : " << players[i].Runscored << "\n""\n";
			cout << "\t" << " 05. Team  : " << players[i].Team << "\n""\n";
			cout << "\n""\n";
			found = true;
			break;

		}

	}
	if (!found)
	{
		cout << "\t" << "||No Player Found||" << "\n""\n";
	}

}
void SavePlayerstoFile()
{
	ofstream outFile("players.txt");

	outFile << playercount << endl;

	for (int i = 0; i < playercount; i++)
	{
		outFile << players[i].RegistrationNo << endl;
		outFile << players[i].FirstName << endl;
		outFile << players[i].LastName << endl;
		outFile << players[i].DateOfBirth << endl;
		outFile << players[i].Runscored << endl;
		outFile << players[i].Team << endl;


		outFile.close();
		cout << "\t" << " Players have been saved to file " << "\n""\n";


	}
}



void LogOut()
{
	loginStart = false;
	cout << "\t" << "  ||Your Logout Was Successful||  ";
	cout << "\n""\n";


}


int main()
{
	int Option;
	cout << "\t" << " || Welcome To The Player Management System || " << "\n""\n";

	SavePlayerstoFile();

	while (true)
	{
		if (!loginStart)
		{
			cout << "\t" << " 01. LogIn : " << "\n""\n";
			cout << "\t" << " 06. Exit : " << "\n""\n";
			cout << "\t" << " Enter your Option Here : ";
			cin >> Option;
			cout << "\n""\n";
			if (Option == 1)
			{
				LogIn(); // call Login function
			}
			else
			{
				return 0;
			}
		}

		else
		{



			cout << "\t " << " 01. Add New Players : " << "\n""\n";

			cout << "\t " << " 02. Display Players : " << "\n""\n";

			cout << "\t " << " 03. Search Players : " << "\n""\n";

			cout << "\t " << " 04. Save Players Details : " << "\n""\n";

			cout << "\t " << " 05. LogOut : " << "\n""\n";

			cout << "\t " << " Put In Your Selection Here :";

			cin >> Option;
			cout << "\n""\n";

			switch (Option)
			{

			case 1:
				AddNewPlayer();
				break;

			case 2:
				DisplayPlayers();
				break;

			case 3:
				SearchPlayers();
				break;

			case 4:
				SavePlayerstoFile();
				break;

			case 5:
				LogOut();
				break;


			default:
				cout << "\t" << " || Not Valid Data || " << "\n""\n";

			}

		}
	}
	return 0;

}