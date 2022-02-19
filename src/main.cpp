#include"../include/GUI.h"
#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

int main()
{
	int size;
	cout << "Manual: \n" << endl;
	cout << "Space: Pause\n" << "R: reset\n" << "Up: +playing speed\n" << "Down: -playing speed\n"<<"Esc: Exit\n";
	cout << "Please specify the grid size: ";
	cin >> size;
	while (size > 150) {
		cout << "Too big number, enter again...\n"; cin >> size;
	}
	

	cin.clear();
	cout << "Press ENTER to continue" << endl;

	cin.get();
	GUI gui;
	gui.rows = size;
	gui.cols = size;
	gui.run();
	
	return 0;
}