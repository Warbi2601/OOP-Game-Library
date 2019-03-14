#include "Menu.h"

using namespace std;

Menu::Menu(const string& title, Application* app) : title_(title), app(app)
{
}

void Menu::Paint()
{
	bool readyToGoBack = false;

	while (!readyToGoBack)
	{
		Header();
		OutputOptions();
		Line();
		Option('B', "Back");
		Footer();

		char choice = Utils::getCharFromUser();

		if (choice == 'B')
		{
			readyToGoBack = true;
		}
		else
		{
			readyToGoBack = HandleChoice(choice);
		}
	}
}

void Menu::Line()
{
	cout << '\n';
}

void Menu::Line(const string& text)
{
	cout << "  " << text << "\n";
}

void Menu::Option(char id, const string& option)
{
	cout << "  " << id << ") " << option << '\n';
}

void Menu::Option(int id, const string& option)
{
	// shift the integer value up to the correct position in the ascii table
	char ascii = id + '0';
	Option(ascii, option);
}

string Menu::Question(const string& question)
{
	cout << "  " << question << ": ";
	return Utils::getLineFromUser();
}

void Menu::Header()
{

#if defined _WIN32 || defined _WIN64
	// we are running on windows so use CLS to clear the screen
	system("CLS");
#else
	// we are running on mac or linux so use CLEAR to clear the screen
	system("CLEAR");
#endif

	cout << '\n';

	cout << "  -= " << title_ << " =-  \n";
	cout << '\n';
}

void Menu::Footer()
{
	cout << '\n';
	cout << '\n';
	cout << "  >>> ";
}