#include <iostream>
#include <time.h>
#include <windows.h>
#include "map.h"
#include <algorithm>
#include <queue>
#include "chaebo.h"
#include <time.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	system("mode con cols=60 lines=20 | title NOT RYTHM : DEMO");
	srand((unsigned int)time(NULL));
	game gameInstaller;
	while (1) {
		gameInstaller.drawMenu();
		gameInstaller.inputStar();
		gameInstaller.senseInput();
		if (gameInstaller.isStart) {
			break;
		}
		if (gameInstaller.isExit) {
			return 0;
		}
		Sleep(20);
		system("cls");
	}
	clock_t startTime = clock();
	queue<pair<int, clock_t>> notes;
	for (int i = 0; i < MAX_CHAEBO_SIZE; i++) { //채보 불러와서 배열에 저장하기
		notes.push(make_pair(chaebo[i][0], chaebo[i][1] + startTime));
	}
	while (1) {
		gameInstaller.senseInput();
		gameInstaller.checkPressButton();
		gameInstaller.drawMap();
		gameInstaller.downNote();
		if (!notes.empty()) {
			clock_t curTime = clock();
			while (notes.front().second <= curTime) {
				pair<int, clock_t> temp;
				temp = notes.front();
				gameInstaller.curNotes.push(make_pair(temp.first, (int)(temp.second + 500)));
				notes.pop();
				gameInstaller.inputNote(temp.first, temp.second);
				if (notes.empty()) {
					break;
				}
			}
		}
		if (!gameInstaller.curNotes.empty()) {
			clock_t curTime = clock();
			while (gameInstaller.curNotes.front().second + 100 < curTime) {
				gameInstaller.curNotes.pop();
				gameInstaller.inputPanzongMessage("BREAK T^T");
				gameInstaller.combo = 0;
				if (gameInstaller.curNotes.empty()) {
					break;
				}
			}
		}
		if (notes.empty() && gameInstaller.curNotes.empty()) {
			break;
		}
		Sleep(20);
		system("cls");
	}
	system("cls");
	while (1) {
		gameInstaller.drawResult();
		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
		Sleep(100);
		system("cls");
	}
}