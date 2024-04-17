#include "game_of_life.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool game_of_life::random_value() {
	int x = (rand() % 100) + 1;
	if (x <= 25) return 1;
	else return 0;
}
bool game_of_life::cell_taken(int i, int j) {
	int n = 0;
	for (int x = -1; x < 2; ++x) {
		for (int y = -1; y < 2; ++y) {
			if (x != 0 or y != 0) { 
				if (_generation[i + x][j + y] == 1) { ++n; }
			}
		}
	}
	if (n == 3) { return 1; }
	if (_generation[i][j] == 1 and n == 2) { return 1; }
	return 0;
}
game_of_life::game_of_life() {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			_generation[i][j] = random_value();
		}
	}
}
void game_of_life::next_generation() {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			_next_generation[i][j] = cell_taken(i, j);
		}
	}

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			_generation[i][j] = _next_generation[i][j];
		}
	}

}
void game_of_life::draw() {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			if (_generation[i][j]) { cout << "*"; }
			else { cout << "-"; }
		}
		cout << endl;
	}

}