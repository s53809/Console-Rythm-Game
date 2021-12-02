#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <string>
#include <cstdio>
#include "map.h"
using namespace std;

void game::inputDebugMessage(string message) {
	debugMessage = message;
}

string game::showDebugMessage() {
	if (debugMessage != "-1") {
		return debugMessage;
	}
	else {
		return "UNKNOWN";
	}
}

string game::showPanzongMessage() {
	if (PanzongMessage != "hello") {
		return PanzongMessage;
	}
	else {
		return "48656c6c6f204d696e73656f20746f204d696e73656f";
	}
}

void game::inputPanzongMessage(std::string message) {
	PanzongMessage = message;
}
 
void game::drawMenu() {
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 48; j++) {
			cout << menu[i][j];
		}
		cout << '\n';
	}
}

void game::inputStar() {
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 48; j++) {
			if (menu[i][j] == '^') {
				menu[i][j] = ' ';
			}
		}
	}
	int randX, randY;
	for (int i = 0; i < 10; i++) {
		randX = rand() % 13 + 1;
		randY = rand() % 47 + 1;
		if (menu[randX][randY] != ' ') {
			i--;
			continue;
		}
		else {
			menu[randX][randY] = '^';
		}
	}
}

void game::drawResult() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 48; j++) {
			cout << resultMap[stac][i][j];
		}
		cout << '\n';
	}
	stac++;
	if (stac == 10) {
		stac = 0;
	}
	cout << "\n\n            FINAL SCORE " << score << '\n';
	cout << "\n                                ESC 키를 꾹 눌러 종료 . . .";
}

void game::drawMap() {
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 48; j++) {
			char temp = map[i][j];
			if (temp == '0') {
				cout << " ";
			}
			if (temp == '1') {
				cout << "■";
			}
			if (temp == '2') {
				cout << "▒";
			}
			if (temp == '3') {
				cout << "#";
			}
			if (temp == '4') {
				cout << "=";
			}
		}
		cout << '\n';
	}
	cout << "                     Combo " << combo << '\n';
	cout << "                     " << showPanzongMessage() << '\n';
	cout << "                     Score " << score << '\n';
	//cout << "                     " << showDebugMessage() << '\n';
}

void game::inputNote(int N, int sec) {
	if (N == 1) {
		for (int i = 2; i <= 8; i++) {
			map[1][i] = '4';
		}
	}
	if (N == 2) {
		for (int i = 14; i <= 20; i++) {
			map[1][i] = '4';
		}
	}
	if (N == 3) {
		for (int i = 26; i <= 32; i++) {
			map[1][i] = '4';
		}
	}
	if (N == 4) {
		for (int i = 38; i <= 44; i++) {
			map[1][i] = '4';
		}
	}
}

void game::downNote() {
	
	for (int i = 11; i >= 1; i--) {
		for (int j = 2; j <= 8; j++) {
			map[i][j] = map[i - 1][j];
		}
		for (int j = 14; j <= 20; j++) {
			map[i][j] = map[i - 1][j];
		}
		for (int j = 26; j <= 32; j++) {
			map[i][j] = map[i - 1][j];
		}
		for (int j = 38; j <= 44; j++) {
			map[i][j] = map[i - 1][j];
		}
	}
}

void game::senseInput() {
	if (GetAsyncKeyState(0x44)) {
		inputZ = clock();
	}
	if (GetAsyncKeyState(0x46)) {
		inputX = clock();
	}
	if (GetAsyncKeyState(0x4A)) {
		inputDot = clock();
	}
	if (GetAsyncKeyState(0x4B)) {
		inputSlash = clock();
	}
	if (GetAsyncKeyState(VK_UP)) {
		menu[8][25] = '<';
		menu[10][25] = ' ';
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		menu[8][25] = ' ';
		menu[10][25] = '<';
	}
	if (GetAsyncKeyState(VK_RETURN)) {
		if (menu[8][25] == '<') {
			isStart = true;
		}
		if (menu[10][25] == '<') {
			isExit = true;
		}
	}
}

void game::checkPanzong(int N) {
	if (curNotes.empty()) {
		return;
	}
	queue<pair<int, clock_t>> qu;
	qu = curNotes;
	int NumberOfNote = curNotes.front().first;
	while (qu.front().second != curNotes.front().second) { // 동타판정일때 방지
		if (qu.front().first == N) {
			NumberOfNote = N;
			break;
		}
		qu.pop();
	}
	if (N == NumberOfNote) {
		clock_t app = clock();
		int dist = curNotes.front().second - (app - 50);
		if (-100 <= dist && dist <= 100) { //최소한 break는 아님
			combo++;
			inputDebugMessage(to_string(curNotes.front().second) + ' ' + to_string(app));
			curNotes.pop();
			if (-100 <= dist && dist <= -40) {
				inputPanzongMessage("SLOW GREAT");
				score += 50 * combo;
			}
			else if (-40 < dist && dist < 40) {
				inputPanzongMessage("PERFECT!");
				score += 100 * combo;
			}
			else {
				inputPanzongMessage("FAST GREAT");
				score += 50 * combo;
			}
		}
	}
}

void game::checkPressButton() {
	clock_t EndTime = clock();
	if ((double)(EndTime - inputZ) < 50 && inputZ != 0) {
		for (int i = 0; i < 11; i++) {
			map[11][i] = '3';
			isZ = true;
			checkPanzong(1);
		}
	}
	else {
		for (int i = 0; i < 11; i++) {
			map[11][i] = '2';
			isZ = false;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	if ((double)(EndTime - inputX) < 50 && inputX != 0) {
		for (int i = 12; i < 24; i++) {
			map[11][i] = '3';
			checkPanzong(2);
			isX = true;
		}
	}
	else {
		for (int i = 12; i < 24; i++) {
			map[11][i] = '2';
			isX = false;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	if ((double)(EndTime - inputDot) < 50 && inputDot != 0) {
		for (int i = 25; i < 36; i++) {
			map[11][i] = '3';
			checkPanzong(3);
			isDot = true;
		}
	}
	else {
		for (int i = 25; i < 36; i++) {
			map[11][i] = '2';
			isDot = false;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	if ((double)(EndTime - inputSlash) < 50 && inputSlash != 0) {
		for (int i = 37; i < 48; i++) {
			map[11][i] = '3';
			checkPanzong(4);
			isSlash = true;
		}
	}
	else {
		for (int i = 37; i < 48; i++) {
			map[11][i] = '2';
			isSlash = false;
		}
	}
}