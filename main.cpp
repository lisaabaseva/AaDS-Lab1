#include <iostream>
#include <conio.h>
#include "BrokenLine.h"

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int MainMenu()
{

	system("cls");
	while (true)
	{
		std::cout << "Hello! Select an action:\n1. View the line\n2. Rewrite the point value.\n";
		std::cout << "3. View point values.\n4. Adding a point to the beginning of the line.\n";
		std::cout << "5. Adding a point to the end of the line.\n6. The length of the line.\n";
		std::cout << "7. Checking for equality of lines.\n8. The sum of two lines (concatenation).\nEsc. Exit.\n";
		int key = GetKey();
		if (key == 27 || key >= 49 && key <= 56)
			return key;
	}
}

int ChoiceMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "Choose your line:\n\n1. First line\n2. Second line\n\nEsc. Return back" << std::endl;
		int key = GetKey();
		if ((key == 27) || (key == 49) || (key == 50)) return key;
	}
}

void RewriteTheVertexValue(BrokenLine &line)
{
	system("cls");
	std::cout << "Enter index of element: " << std::endl;
	int index;
	std::cin >> index;
	try
	{
		std::cout << "Your element: " << "[" << line[index]._x << ";" << line[index]._y << "]" << std::endl;
		std::cout << "Enter new value: " << std::endl;
		std::cin >> line[index]._x;
		std::cin >> line[index]._y;
		std::cin.get();

	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
		std::cin.get();
		std::cin.get();
	}
}

void ViewTheVertexValue(BrokenLine &line)
{
	system("cls");
	std::cout << "Enter index of element: " << std::endl;
	int index;
	std::cin >> index;
	try
	{
		std::cout << "Your element: " << "[" << line[index]._x << ";" << line[index]._y << "]" << std::endl;
		std::cin.get();
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
		std::cin.get();
		std::cin.get();
	}
}

void AddAVertexToTheBeginning(BrokenLine &line)
{
	system("cls");
	Point p;
	std::cout << "Enter the coordinates of the point" << std::endl;
	std::cout << "Enter x: " << std::endl;
	std::cin >> p._x;
	std::cout << "Enter y: " << std::endl;
	std::cin >> p._y;
	try
	{
		line = p + line;
		std::cin.get();
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
	}
	std::cin.get();
}

void AddAVertexToTheEnd(BrokenLine &line)
{
	system("cls");
	Point p;
	std::cout << "Enter the coordinates of the point" << std::endl;
	std::cout << "Enter x: " << std::endl;
	std::cin >> p._x;
	std::cout << "Enter y: " << std::endl;
	std::cin >> p._y; 
	try
	{
		line = line + p;
		std::cin.get();
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
	}
	std::cin.get();
}

void SizeLine(BrokenLine &line)
{
	system("cls");
	try
	{
		std::cout << line << std::endl;
		std::cout << "Line_1 lenght : " << line.SizeLine(line) << std::endl;
		std::cin.get();
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
	}
	std::cin.get();
}

void CheckingForEqualityOfLines(BrokenLine &line_1, BrokenLine &line_2)
{
	system("cls");
	if (line_1 == line_2) std::cout << "Polylines are equal" << std::endl;
	else std::cout << "Polylines aren't equal" << std::endl;
	std::cin.get();
}

void Concatenation(BrokenLine &line_1, BrokenLine &line_2)
{
	system("cls");
	line_1 = line_1 + line_2;
	std::cout << "Successfully" << std::endl;
	std::cin.get();
}

int Menu()
{
	BrokenLine line_1, line_2;
	while (true)
	{
		system("cls");
		int m = MainMenu();
		if (m == 27)
		{
			break;
		}
		if (m == 49)
		{
			while (true)
			{
				system("cls");
				int m1 = ChoiceMenu();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					system("cls");
					std::cout << line_1 << std::endl;
					std::cin.get();
				}
				if (m1 == 50)
				{
					system("cls");
					std::cout << line_2 << std::endl;
					std::cin.get();
				}
			}
		}
		if (m == 50)
		{
			while (true)
			{
				system("cls");
				int m1 = ChoiceMenu();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					RewriteTheVertexValue(line_1);
				}
				if (m1 == 50)
				{
					RewriteTheVertexValue(line_2);
				}
			}
		}
		if (m == 51)
		{
			while (true)
			{
				system("cls");
				int m1 = ChoiceMenu();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					ViewTheVertexValue(line_1);
				}
				if (m1 == 50)
				{
					ViewTheVertexValue(line_2);
				}
			}
		}
		if (m == 52)
		{
			while (true)
			{
				system("cls");
				int m1 = ChoiceMenu();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					AddAVertexToTheBeginning(line_1);
				}
				if (m1 == 50)
				{
					AddAVertexToTheBeginning(line_2);
				}
			}
		}
		if (m == 53)
		{
			while (true)
			{
				system("cls");
				int m1 = ChoiceMenu();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					AddAVertexToTheEnd(line_1);
				}
				if (m1 == 50)
				{
					AddAVertexToTheEnd(line_2);
				}
			}
		}
		if (m == 54)
		{
			while (true)
			{
				system("cls");
				int m1 = ChoiceMenu();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					SizeLine(line_1);
				}
				if (m1 == 50)
				{
					SizeLine(line_2);
				}
			}
		}
		if (m == 55)
		{
			CheckingForEqualityOfLines(line_1, line_2);
		}
		if (m == 56)
		{
			while (true)
			{
				system("cls");
				std::cout << "Select the first line:" << std::endl;
				int m1 = ChoiceMenu();
				if (m1 == 27) break;
				if (m1 == 49)
				{
					Concatenation(line_1, line_2);
				}
				if (m1 == 50)
				{
					Concatenation(line_2, line_1);
				}
			}
		}
	}
	return 0;
}

int main()
{
	int start = Menu();
}
