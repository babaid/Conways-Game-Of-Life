#include"../include/GUI.h"
#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

int main()
{
	int row, col;
	cout << "Help: \n" << endl;
	cout << "Space: pause\n" << "R: reset\n" << "Up: +playing speed\n" << "Down: -playing speed\n"<<"Esc: Exit\n";
	cout << "How many columns?\n";
	cin >> col;
	while (col > 150) {
		cout << "Too big number, enter again...\n"; cin >> col;
	}
	cin.clear();
	
	cout << "Press ENTER to continue" << endl;

	cin.get();
	GUI gui;
	gui.rows = col;
	gui.cols = col;
	gui.run();
	
	return 0;
}