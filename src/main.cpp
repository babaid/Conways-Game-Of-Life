#include"../include/GUI.h"
#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

int main()
{
	int row, col;
	cout << "Manual: \n" << endl;
	cout << "Space: Pause\n" << "R: reset\n" << "Up: +playing speed\n" << "Down: -playing speed\n"<<"Esc: Exit\n";
	cout << "Please specify the grid size!\nRows: ";
	cin >> row;
	while (row > 150) {
		cout << "Too big number, enter again...\n"; cin >> row;
	}
	cout << "Columns: ";
	cin >> col;
	while (col > 150) {
		cout << "Too big number, enter again...\n"; cin >> col;
	}

	cin.clear();
	cout << "Press ENTER to continue" << endl;

	cin.get();
	GUI gui;
	gui.rows = row;
	gui.cols = col;
	gui.run();
	
	return 0;
}