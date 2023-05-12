#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <random>
#include <map>

using namespace std::filesystem;
using namespace std;

//help-function
void helpfunc()
{
	cout << "use `-program_name` to execute a program" << endl;
	cout << "currently installed programs:";
	cout << "•fim•imgv•inet•numrandom•termpad•" << endl;
}
//termpad-app
void termpadapp()
{
	{
		map<string, string> db;
		while (1)
		{
			cout << "[termpad]" << endl;
			cout << "Enter -c to create, -o to open or -l to list" << endl;
			cout << "Or enter -q to quit" << endl;
			cout << ">> ";
			string action;
			getline(cin, action);
			if (action == "-c")
			{
				string key;
				string data;
				cout << "Enter key: ";
				getline(cin, key);
				cout << "Enter data: ";
				getline(cin, data);
				db[key] = data;
			}
			if (action == "-o")
			{
				cout << "Enter key: ";
				string key;
				getline(cin, key);
				if (db.find(key) != db.end())
				{
					cout << "Your data: " << db[key] << endl;
				}
				else
					cout << "No such key" << endl;
			}
			if (action == "-l")
			{
				cout << "Content list:" << endl;
				for (auto it = db.begin(); it != db.end(); it++)
				{
					cout << it->first << ": " << it->second << endl;
				}
			}
			if (action == "-q")
			{
				cout << "Program terminated" << endl;
				break;
			}
			cout << endl;
		}
	}
}
//numrandom-app
void numrandomapp()
{
	cout << "Generate Random Number? (y/n)" << endl;
	cout << ">> ";
	string input;
	cin >> input;
	if (input == "y")
	{
		random_device rd;
		mt19937 rng(rd());
		uniform_real_distribution<double> dist(0.0, 2.0);
		cout << "Generating Number..." << endl;
		for (int i = 0; i < 1; i++)
			cout << dist(rng) << " ";
		cout << endl;
	}
	else if (input == "n")
	{
		cout << "program terminated" << endl;
	}
}

//filemanager-app
void fimapp()
{
	cout << "choose path:";
	string filepath;
	cin >> filepath;
	path p(filepath);

	if (!exists(p))
	{
		cout << p << " not found" << endl;
	}

	if (!is_directory(p))
	{
		cout << p << " is not a directory" << endl;
	}

	for (auto &d : directory_iterator(p))
	{
		cout << d.path() << endl;
	}
}

//imageviwer-app
void imgvapp()
{
	cout << "Enter image path (`.bmp` only): ";
	string filepath;
	cin >> filepath;

	// Open the file in binary mode
	ifstream file(filepath, ios::binary);

	// Read the BMP file header
	char header[54];
	file.read(header, 54);

	// Extract the width and height information from the header
	int width = *(int *)&header[18];
	int height = *(int *)&header[22];

	// Allocate memory for the image data
	unsigned char *data = new unsigned char[3 * width * height];

	// Read the image data
	file.read((char *)data, 3 * width * height);

	// Close the file
	file.close();

	// Display the image
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int offset = (y * width + x) * 3;
			cout << "\033[48;2;" << (int)data[offset] << ";" << (int)data[offset + 1] << ";" << (int)data[offset + 2] << "m ";
		}
		cout << "\033[0m\n";
	}

	// Free the memory
	delete[] data;
}

//internet-app
void inetapp()
{
	cout << "type your link:";
	string link;
	cin >> link;
	cout << "because of bad internet `" + link + "` could not be reached" << endl;
	cout << ":(" << endl;
}

//base-code
int main()
{
	string author = "nabir14";
	string version = "[version 1.0]";
	cout << "**********" << endl;
	cout << "* TermOS *" << endl;
	cout << "**********" << endl;
	cout << version << endl;
	cout << "[made by " + author + "]" << endl;
	cout << "[use `-help` to learn commands]" << endl;
	cout << ">> ";
	string program;
	cin >> program;
	if (program == "-help")
	{
		helpfunc();
	}
	else if (program == "-imgv")
	{
		imgvapp();
	}
	else if (program == "-inet")
	{
		inetapp();
	}
	else if (program == "-fim")
	{
		fimapp();
	}
	else if (program == "-numrandom")
	{
		numrandomapp();
	}
	else if (program == "-termpad")
	{
		termpadapp();
	}
	//resume-function-workinprogress
	//void resumefunc(){
	//	cout << ">> ";
	//	string program;
	//	cin >> program;
	//	if (program == "-help")
	//	{
	//		helpfunc();
	//	}
	//	else if (program == "-imgv")
	//	{
	//		imgvapp();
	//	}
	//	else if (program == "-inet")
	//	{
	//		inetapp();
	//	}
	//	else if (program == "-fim")
	//	{
	//		fimapp();
	//	}
	//		else if (program == "-numrandom")
	//	{
	//		numrandomapp();
	//	}
	//	}
}