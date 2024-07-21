#include <iostream>
#include <string.h>
#include <windows.h>
#include <ctime>
#include <sstream>
#include <conio.h>
#include <fstream>

using namespace std;

int file_handling();

class outline_box
{
protected:
	bool files[6];

public:
	outline_box()
	{
		for (int i = 0; i < 6; i++)
		{
			files[i] = true;
		}
	}

	void print_display(string temp[])
	{
		system("cls");
		for (int i = 0; i < 35; i++)
		{
			cout << "\t";
			if (i == 0 || i == 34)
			{
				for (int j = 0; j < 120; j++)
				{
					cout << "=";
				}
			}
			else
			{
				cout << "||";
				cout << temp[i];
				// cout<<"||";
			}
			cout << endl;
		}
	}

	void shutDown()
	{
		system("cls");
		for (int j = 0; j < 20; j++)
		{
			cout << endl;
		}
		cout << "\t\t\t\t\t\t\t\t\tShuting down ";
		for (int j = 0; j < 5; j++)
		{
			Sleep(500);
			cout << ". ";
		}
		for (int j = 0; j < 25; j++)
		{
			cout << endl;
		}
		system("cls");
	}

	void restart()
	{
		system("cls");
		for (int j = 0; j < 25; j++)
		{
			cout << endl;
		}
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tRestarting ";
		for (int j = 0; j < 7; j++)
		{
			Sleep(500);
			cout << ". ";
		}
		for (int j = 0; j < 25; j++)
		{
			cout << endl;
		}
		system("cls");
	}

	virtual int getCommand() = 0;
	virtual int print_display() = 0;
}; // end of outline_box class

class main_screen : public outline_box
{
private:
	int no_of_defined_commands;
	string entered_command, defined_commands[40];

public:
	main_screen()
	{
		no_of_defined_commands = 5;
		string temp[no_of_defined_commands] = {"shut_down",
											   "restart",
											   "setting",
											   "open_calc",
											   "create_file"};
		for (int i = 0; i < no_of_defined_commands; i++)
		{
			defined_commands[i] = temp[i];
		}
	}

	int print_display()
	{

		time_t now = time(0);
		char *dt;
		char ch[24];
		string in_box_display_content[35], str[] = {"D", "E", "V", "E", "L", "O", "P", "E", "R", " ", "M", "O", "D", "E"};
		string temp1;
		for (int i = 0; i < 35; i++)
		{
			for (int j = 0; j < 116; j++)
			{
				if (i == 1 && j == 1)
				{
					dt = ctime(&now);
					dt[strlen(dt) - 1] = '\0';
					for (int k = 0; k < 25; k++)
					{
						if (k == 25)
						{
							ch[k + 1] = '\0';
						}
						else
						{
							ch[k] = dt[k];
						}
					}

					in_box_display_content[i].append("  ");
					in_box_display_content[i].append(ch);
					j += 25;
				}
				else if (i == 1 && j == 96)
				{
					in_box_display_content[i].append("Restart | Shutdown");
					j += 17;
				}
				else if (i > 9 && i < 24 && j == 113)
				{
					in_box_display_content[i].append("" + str[i - 10]);
				}
				else if (i == 33 && j == 45)
				{
					in_box_display_content[i].append("Settings");
					j += 7;
				}
				else if (files[0] && (i > 4 && i < 10) && (j > 15 && j < 20))
				{
					if (i == 5 || i == 8)
					{
						in_box_display_content[i].append("-");
					}
					else if (i != 9 && (j == 16 || j == 19))
					{
						in_box_display_content[i].append("|");
					}
					else if (i != 9 && (j == 17 || j == 18))
					{
						in_box_display_content[i].append("/");
					}
					else if (i == 9 && j == 17)
					{
						in_box_display_content[i].append("01");
						j++;
					}
					else
					{
						in_box_display_content[i].append(" ");
					}
				}

				else if (files[1] && (i > 4 && i < 10) && (j > 96 && j < 101))
				{
					if (i == 5 || i == 8)
					{
						in_box_display_content[i].append("-");
					}
					else if (i != 9 && (j == 97 || j == 100))
					{
						in_box_display_content[i].append("|");
					}
					else if (i != 9 && (j == 98 || j == 99))
					{
						in_box_display_content[i].append("/");
					}
					else if (files[1] && i == 9 && j == 98)
					{
						in_box_display_content[i].append("02");
						j++;
					}
					else
					{
						in_box_display_content[i].append(" ");
					}
				}

				else if (files[2] && (i > 15 && i < 21) && (j > 15 && j < 20))
				{
					if (i == 16 || i == 19)
					{
						in_box_display_content[i].append("-");
					}
					else if (i != 20 && (j == 16 || j == 19))
					{
						in_box_display_content[i].append("|");
					}
					else if (i != 20 && (j == 17 || j == 18))
					{
						in_box_display_content[i].append("/");
					}
					else if (i == 20 && j == 17)
					{
						in_box_display_content[i].append("03");
						j++;
					}
					else
					{
						in_box_display_content[i].append(" ");
					}
				}
				else if (files[3] && (i > 15 && i < 21) && (j > 96 && j < 101))
				{
					if (i == 16 || i == 19)
					{
						in_box_display_content[i].append("-");
					}
					else if (i != 20 && (j == 97 || j == 100))
					{
						in_box_display_content[i].append("|");
					}
					else if (i != 20 && (j == 98 || j == 99))
					{
						in_box_display_content[i].append("/");
					}
					else if (i == 20 && j == 98)
					{
						in_box_display_content[i].append("04");
						j++;
					}
					else
					{
						in_box_display_content[i].append(" ");
					}
				}
				else if (files[4] && (i > 25 && i < 31) && (j > 15 && j < 20))
				{
					if (i == 26 || i == 29)
					{
						in_box_display_content[i].append("-");
					}
					else if (i != 30 && (j == 16 || j == 19))
					{
						in_box_display_content[i].append("|");
					}
					else if (i != 30 && (j == 17 || j == 18))
					{
						in_box_display_content[i].append("/");
					}
					else if (files[4] && i == 30 && j == 17)
					{
						in_box_display_content[i].append("05");
						j++;
					}
					else
					{
						in_box_display_content[i].append(" ");
					}
				}
				else if (files[5] && (i > 25 && i < 31) && (j > 96 && j < 101))
				{
					if (i == 26 || i == 29)
					{
						in_box_display_content[i].append("-");
					}
					else if (i != 30 && (j == 97 || j == 100))
					{
						in_box_display_content[i].append("|");
					}
					else if (i != 30 && (j == 98 || j == 99))
					{
						in_box_display_content[i].append("/");
					}
					else if (files[5] && i == 30 && j == 98)
					{
						in_box_display_content[i].append("01");
						j++;
					}
					else
					{
						in_box_display_content[i].append(" ");
					}
				}
				else
				{
					in_box_display_content[i].append(" ");
				}
			}
			in_box_display_content[i].append("||");
			if (i == 1)
			{
				in_box_display_content[i].append("        Valid commands:");
			}
			else if (i > 2 && i < no_of_defined_commands + 3)
			{
				in_box_display_content[i].append("        ");
				ostringstream str1;
				str1 << i - 2;
				in_box_display_content[i].append(str1.str());
				in_box_display_content[i].append(". ");
				in_box_display_content[i].append(defined_commands[i - 3]);
			}
		}
		outline_box::print_display(in_box_display_content);
		return getCommand();
	}
	int getCommand()
	{
		string entered_command;
		while (true)
		{
			cout << endl
				 << "command:->";
			cin >> entered_command;

			if (entered_command.compare("shut_down") == 0 || entered_command.compare("1") == 0)
			{
				shutDown();
				exit(0);
			}
			else if (entered_command.compare("restart") == 0 || entered_command.compare("2") == 0)
			{
				restart();
				system("cls");
				break;
			}
			else if (entered_command.compare("setting") == 0 || entered_command.compare("3") == 0)
			{
				return 1;
			}
			else if (entered_command.compare("open_calc") == 0 || entered_command.compare("4") == 0)
			{
				return 3;
			}
			else if (entered_command.compare("create_file") == 0 || entered_command.compare("5") == 0)
			{
				return 4;
			}
		}
		return 0;
	}
}; // end of main_screen class

class login_screen : public outline_box
{
private:
	int no_of_defined_commands;
	string entered_command, defined_commands[40];
	bool logged_in;
	string in_box_display_content[35];

public:
	login_screen()
	{
		logged_in = false;
		no_of_defined_commands = 3;
		string temp[no_of_defined_commands] = {"shut_down",
											   "restart",
											   "login"};
		for (int i = 0; i < no_of_defined_commands; i++)
		{
			defined_commands[i] = temp[i];
		}
	}

	int print_display()
	{

		for (int i = 0; i < 35; i++)
		{
			//	in_box_display_content[i].append("||");

			for (int j = 0; j < 116; j++)
			{
				// PIXEL OS print
				if (j == 55 && i == 2)
				{
					in_box_display_content[i].append("PIXEL OS");
					j += 7;
				}
				else if (j == 53 && i == 3)
				{
					in_box_display_content[i].append("-----------");
					j += 10;
				}
				else
				{
					in_box_display_content[i].append(" ");
				}

				// Login box
				if (j == 35 && (i == 15 || i == 26))
				{
					for (int k = 0; k < 46; k++)
					{
						in_box_display_content[i].append("-");
					}
					j += 46;
				}
				else if ((j == 35 || j == 80) && (i > 15 && i < 26))
				{
					in_box_display_content[i].append("|");
					j++;
				}

				// Username
				if (j == 38 && i == 18)
				{
					in_box_display_content[i].append("Username: ");
					j += 10;
				}

				// Username box
				if (j == 50 && (i == 17 || i == 19))
				{
					for (int k = 0; k < 26; k++)
					{
						in_box_display_content[i].append("-");
					}
					j += 26;
				}
				else if ((j == 50 || j == 75) && (i > 17 && i < 19))
				{
					in_box_display_content[i].append("|");
					j++;
				}

				// Password
				if (j == 38 && i == 23)
				{
					in_box_display_content[i].append("Password: ");
					j += 10;
				}

				// Password box
				if (j == 50 && (i == 22 || i == 24))
				{
					for (int k = 0; k < 26; k++)
					{
						in_box_display_content[i].append("-");
					}
					j += 26;
				}
				else if ((j == 50 || j == 75) && (i > 22 && i < 24))
				{
					in_box_display_content[i].append("|");
					j++;
				}

				// Login word
				if (j == 55 && i == 10)
				{
					in_box_display_content[i].append("LOGIN");
					j += 5;
				}

				// login word box
				if (j == 52 && (i == 9 || i == 11))
				{
					for (int k = 0; k < 11; k++)
					{
						in_box_display_content[i].append("-");
					}
					j += 11;
				}
				else if ((j == 52 || j == 62) && (i > 9 && i < 11))
				{
					in_box_display_content[i].append("|");
					j++;
				}

				// Shutdown
				if (j == 95 && i == 33)
				{
					in_box_display_content[i].append("Restart | shutdown");
					j += 18;
				}
			}
			in_box_display_content[i].append("||");

			// commands
			if (i == 1)
			{
				in_box_display_content[i].append("        Valid commands:");
			}
			else if (i > 2 && i < no_of_defined_commands + 3)
			{
				in_box_display_content[i].append("        ");
				ostringstream str1;
				str1 << i - 2;
				in_box_display_content[i].append(str1.str());
				in_box_display_content[i].append(". ");
				in_box_display_content[i].append(defined_commands[i - 3]);
			}
		}
		outline_box::print_display(in_box_display_content);
		return getCommand(/*obj2*/);
	}

	void login()
	{
		string username, password;
		bool WrongLogin;
		cout << endl
			 << endl
			 << "\t\t\t\t\t\t--ENTER YOUR LOGIN CREDENTIALS HERE--";

		do
		{
			WrongLogin = true;
			cout << "\n\n\tEnter your username: ";
			cin.ignore();
			// getline(cin, username);
			cin >> username;
			cout << "\n\tEnter your Password: ";
			// getline(cin, password);
			cin >> password;

			if (username != "student" || password != "student")
			{
				cout << "\n\n\tInvalid username or password..Enter again!";
			}
			else
			{
				WrongLogin = false;
			}
		} while (WrongLogin);
		logged_in = true;
	}

	bool user_validity()
	{
		return true;
	}

	int getCommand(/*main_screen &obj1*/)
	{
		string entered_command;
		do
		{
			cout << endl
				 << "command:->";
			cin >> entered_command;

			if (entered_command.compare("shut_down") == 0 || entered_command.compare("1") == 0)
			{
				shutDown();
				exit(0);
			}
			else if (entered_command.compare("restart") == 0 || entered_command.compare("2") == 0)
			{
				restart();
				system("cls");
				break;
			}
			else if (entered_command.compare("login") == 0 || entered_command.compare("3") == 0)
			{
				login();
				return 2;
			}
			// else if(entered_command.compare("shut_down")==0)
		} while (true);
		return 0;
	}
};

class setting_screen : public outline_box
{
private:
	int no_of_defined_commands;
	string entered_command, defined_commands[40];
	string in_box_display_content[35];
	bool bluetooth, airplane, wifi;
	int sound;

public:
	setting_screen()
	{

		no_of_defined_commands = 9;
		string temp[no_of_defined_commands] = {"shut_down",
											   "restart",
											   "turn_on_bluetooth",
											   "turn_off_bluetooth",
											   "turn_on_wifi",
											   "turn_off_wifi",
											   "increase_sound",
											   "decrease_sound",
											   "back"};
		for (int i = 0; i < no_of_defined_commands; i++)
		{
			defined_commands[i] = temp[i];
		}
		bluetooth = false;
		wifi = false;
		sound = 5;
		airplane = false;
	}

	int print_display()
	{
		for(int k=0;k<35;k++)
		{
			in_box_display_content[k]="";
		}
		system("cls");
		for (int i = 0; i < 35; i++)
		{
			for (int j = 0; j < 116; j++)
			{
				if (i == 1 && j == 54)
				{
					in_box_display_content[i].append("Settings");
					j += 7;
				}
				else if (i == 3 && j == 2)
				{
					in_box_display_content[i].append("1. Wifi");
					j += 6;
				}
				else if (i == 3 && j == 35)
				{
					if (wifi)
					{
						in_box_display_content[i].append("ON");
						j++;
					}
					else
					{
						in_box_display_content[i].append("OFF");
						j += 2;
					}
				}
				else if (i == 5 && j == 2)
				{
					in_box_display_content[i].append("2. Sound");
					j += 7;
				}
				else if (i == 5 && j == 35)
				{
					int k;
					for (k = 0; k < sound; k++)
					{
						in_box_display_content[i].append("*");
					}
					j += --k;
				}
				else if (i == 7 && j == 2)
				{
					in_box_display_content[i].append("3. Bluetooth");
					j += 11;
				}
				else if (i == 7 && j == 35)
				{
					if (bluetooth)
					{
						in_box_display_content[i].append("ON");
						j++;
					}
					else
					{
						in_box_display_content[i].append("OFF");
						j += 2;
					}
				}
				else if (i == 9 && j == 2)
				{
					in_box_display_content[i].append("4. Airplane Mode");
					j += 15;
				}
				else if (i == 9 && j == 35)
				{
					if (airplane)
					{
						in_box_display_content[i].append("ON");
						j++;
					}
					else
					{
						in_box_display_content[i].append("OFF");
						j += 2;
					}
				}
				else if (i == 11 && j == 2)
				{
					in_box_display_content[i].append("5. Updates");
					j += 9;
				}
				else if (i == 11 && j == 35)
				{
					in_box_display_content[i].append("Your system is up to date");
					j += 24;
				}
				else if (i == 13 && j == 2)
				{
					in_box_display_content[i].append("6. Notification");
					j += 14;
				}
				else if (i == 13 && j == 35)
				{
					in_box_display_content[i].append("No pending notification");
					j += 22;
				}
				else
				{
					in_box_display_content[i].append(" ");
				}
			}
			in_box_display_content[i].append("||");
			if (i == 1)
			{
				in_box_display_content[i].append("        Valid commands:");
			}
			else if (i > 2 && i < no_of_defined_commands + 3)
			{
				in_box_display_content[i].append("        ");
				ostringstream str1;
				str1 << i - 2;
				in_box_display_content[i].append(str1.str());
				in_box_display_content[i].append(". ");
				in_box_display_content[i].append(defined_commands[i - 3]);
			}
		}
		outline_box::print_display(in_box_display_content);
		return getCommand();
	}

	int getCommand()
	{
		while (true)
		{
			cout << endl
				 << "command:->";
			cin >> entered_command;

			if (entered_command.compare("shut_down") == 0 || entered_command.compare("1") == 0)
			{
				shutDown();
				exit(0);
			}
			else if (entered_command.compare("restart") == 0 || entered_command.compare("2") == 0)
			{
				restart();
				system("cls");
				break;
			}
			else if (entered_command.compare("turn_on_bluetooth") == 0 || entered_command.compare("3") == 0)
			{
				if (!bluetooth)
				{
					bluetooth = true;
				}
				return 1;
			}
			else if (entered_command.compare("turn_off_bluetooth") == 0 || entered_command.compare("4") == 0)
			{
				if (bluetooth)
				{
					bluetooth = false;
				}
				return 1;
			}
			else if (entered_command.compare("turn_on_wifi") == 0 || entered_command.compare("5") == 0)
			{
				if (!wifi)
				{
					wifi = true;
				}
				return 1;
			}
			else if (entered_command.compare("turn_off_wifi") == 0 || entered_command.compare("6") == 0)
			{
				if (wifi)
				{
					wifi = false;
				}
				return 1;
			}
			else if (entered_command.compare("increase_sound") == 0 || entered_command.compare("7") == 0)
			{
				if (sound != 10)
				{
					sound++;
				}
				return 1;
			}
			else if (entered_command.compare("decrease_sound") == 0 || entered_command.compare("8") == 0)
			{
				if (sound != 0)
				{
					sound--;
				}
				return 1;
			}
			else if (entered_command.compare("back") == 0 || entered_command.compare("9") == 0)
			{
				return 2;
			}
		}
		return 0;
	}
};

class calc //: public outline_box
{
	/*private:
		int operant1, operant2;
		int no_of_defined_commands;
		string entered_command, defined_commands[40];
		string in_box_display_content[35];*/

public:
	/*calc()
	{
		no_of_defined_commands=8;
		string temp[no_of_defined_commands]={	"shut_down",
												"restart",
												"turn_on_bluetooth",
												"turn_off_bluetooth",
												"turn_on_wifi",
												"turn_off_wifi",
												"increase_sound",
												"decrease_sound"};
		for(int i=0;i<no_of_defined_commands;i++)
		{
			defined_commands[i]=temp[i];
		}

	}*/

	int run_calc()
	{
		system("cls");
		char op;
		float num1, num2;

		cout << "Enter operator: +, -, *, /: ";
		cin >> op;

		cout << "Enter two operands: ";
		cin >> num1 >> num2;

		if (num2 == 0)
		{
			cout << "Mathematical error..Division by ZERO!!";
		}
		else
		{
			switch (op)
			{

			case '+':
				cout << num1 << " + " << num2 << " = " << num1 + num2;
				break;

			case '-':
				cout << num1 << " - " << num2 << " = " << num1 - num2;
				break;

			case '*':
				cout << num1 << " * " << num2 << " = " << num1 * num2;
				break;

			case '/':
				cout << num1 << " / " << num2 << " = " << num1 / num2;
				break;

			default:
				// If the operator is other than +, -, * or /, error message is shown
				cout << "Error! operator is not correct";
				break;
			}
		}
		getch();
		return 2;
	}

	/*int print_display()
	{
		for(int i=0; i<35; i++)
		{
			for(int j=0; j<116; j++)
			{
				if(i==2 && j==53)
				{
					in_box_display_content[i].append("Calculator");
					j+=9;
				}
				else if(i==6 && j>10 )
				{

				}
				else
				{
					in_box_display_content[i].append(" ");
				}
			}
		}
	}*/
};

class run_os : public main_screen, public login_screen, public setting_screen, public calc
{
public:
	void getting_started()
	{
		// Loading screen
		for (int i = 0; i < 16; i++)
		{
			cout << endl;
		}
		cout << "\t\t\t\t\t\t\t\tWelcome to PIXEL OS..\n";
		Sleep(500);
		cout << "\t\t\t\t\t\t\t\t\t." << endl;
		Sleep(500);
		cout << "\t\t\t\t\t\t\t\t\t." << endl;
		Sleep(500);
		cout << "\t\t\t\t\t\t\t\t\t." << endl;
		Sleep(500);
		cout << "\t\t\t\t\t\t\t\tLoading PIXEL OS..\n";
		Sleep(500);
		cout << "\t\t\t\t\t\t\t\t\t." << endl;
		Sleep(500);
		cout << "\t\t\t\t\t\t\t\t\t." << endl;
		Sleep(500);
		cout << "\t\t\t\t\t\t\t\t\t." << endl;
		Sleep(500);
		cout << "\t\t\t\t\t\t\t\tLoaded PIXEL OS successfully";
		Sleep(2000);
		// Loading screen over
		system("cls");
		int n = login_screen::print_display();
		/// 5<4
		if (user_validity())
		{

			while (true)
			{
				system("cls");
				if (n == 1)
				{
					n = setting_screen::print_display();
				}
				else if (n == 2)
				{
					n = main_screen::print_display();
				}
				else if (n == 3)
				{
					n = calc::run_calc();
				}
				else if (n == 4)
				{
					n = file_handling();
				}
				else if(n == 0)
				{
					break;
				}
			}
		}
	}
};

int file_handling()
{
	string file_name, file_data;

	cout << "Enter file name u want to create: ";
	cin >> file_name;

	// create and open a text file
	ofstream myFile1(file_name);

	// write to file
	cout << "Enter data to enter in file: ";
	cin >> file_data;

	myFile1 << file_data;

	// close the file
	myFile1.close();

	string read_file;
	int choice;
	cout << "Do you want to read the file(enter 1 if yes): ";
	cin >> choice;
	if (choice == 1)
	{
		ifstream myReadFile(file_name);
		while (getline(myReadFile, read_file))
		{
			cout << read_file;
		}

		myReadFile.close();
		getch();
	}
	
	return 2;
}

int main()
{
	run_os obj;
	while (true)
	{
		obj.getting_started();
	}

	return 0;
} // end of main function
