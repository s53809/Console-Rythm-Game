#pragma once
#include <queue>
#include <string>

class game {
private:
	char menu[14][48] = {
	{"                                               "},
	{"                                               "},
	{"    RRRR  Y   Y  TTTTTTT  H  H  MM   MM        "},
	{"    R   R  Y Y      T     H  H  M M M M        "},
	{"    RRRR    Y       T     HHHH  M  M  M        "},
	{"    R  R    Y       T     H  H  M     M        "},
	{"    R   R   Y       T     H  H  M     M        "},
	{"                                               "},
	{"                   START <                     "},
	{"                                               "},
	{"                   EXIT                        "},
	{"                                               "},
	{"                                               "}
	};
	char map[14][48] = {
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"},
	{"22222222222122222222222122222222222122222222222"},
	{"00000000000100000000000100000000000100000000000"},
	{"00000000000100000000000100000000000100000000000"}
	};
	char resultMap[10][9][48] = {
		{
			{"                                               "},
			{"                                               "},
			{"     ccccc  l     eeeee     a     rrrr         "},
			{"    c       l     e       a   a   r   r        "},
			{"    c       l     eeeee   aaaaa   rrrr         "},
			{"    c       l     e      a     a  r   r        "},
			{"     ccccc  lllll eeeee  a     a  r   r        "},
			{"                                               "}
		},
		{
			{"                                               "},
			{"                                               "},
			{"     ccccc  l     eeeee     a     rrrr         "},
			{"    c       l     e       a   a   r   r        "},
			{"    c       l     eeeee   aaaaa   rrrr         "},
			{"    c       l     e      a     a  r   r        "},
			{"     ccccc  lllll eeeee  a     a  r   r        "},
			{"                                               "}
		},
		{
			{"                                               "},
			{"                                               "},
			{"     ccccc  l     eeeee     a     rrrr         "},
			{"    c       l     e       a   a   r   r        "},
			{"    c       l     eeeee   aaaaa   rrrr         "},
			{"    c       l     e      a     a  r   r        "},
			{"     ccccc  lllll eeeee  a     a  r   r        "},
			{"                                               "}
		},
		{
			{"                                               "},
			{"                                               "},
			{"     cCCCc  l     eeeee     a     rrrr         "},
			{"    c       l     e       a   a   r   r        "},
			{"    C       l     eeeee   aaaaa   rrrr         "},
			{"    C       l     e      a     a  r   r        "},
			{"     Ccccc  lllll eeeee  a     a  r   r        "},
			{"                                               "}
		},
		{
			{"                                               "},
			{"                                               "},
			{"     ccccc  L     eeeee     a     rrrr         "},
			{"    c       L     e       a   a   r   r        "},
			{"    c       L     eeeee   aaaaa   rrrr         "},
			{"    c       l     e      a     a  r   r        "},
			{"     cCCCc  lllll eeeee  a     a  r   r        "},
			{"                                               "}
		},
		{
			{"                                               "},
			{"                                               "},
			{"     ccccc  l     eeeEE     a     rrrr         "},
			{"    c       l     e       a   a   r   r        "},
			{"    c       l     EEEee   aaaaa   rrrr         "},
			{"    c       l     E      a     a  r   r        "},
			{"     ccccc  llLLl eeeee  a     a  r   r        "},
			{"                                               "}
		},
		{
			{"                                               "},
			{"                                               "},
			{"     ccccc  l     eeeee     A     rrrr         "},
			{"    c       l     e       A   a   r   r        "},
			{"    c       l     eeeee   Aaaaa   rrrr         "},
			{"    c       l     e      a     a  r   r        "},
			{"     ccccc  lllll eeeEE  a     a  r   r        "},
			{"                                               "}
		},
		{
			{"                                               "},
			{"                                               "},
			{"     ccccc  l     eeeee     a     Rrrr         "},
			{"    c       l     e       a   A   r   r        "},
			{"    c       l     eeeee   aaAAA   rrrr         "},
			{"    c       l     e      a     a  r   r        "},
			{"     ccccc  lllll eeeee  A     a  r   r        "},
			{"                                               "}
		},
		{
			{"                                               "},
			{"                                               "},
			{"     ccccc  l     eeeee     a     rrRR         "},
			{"    c       l     e       a   a   R   r        "},
			{"    c       l     eeeee   aaaaa   RRrr         "},
			{"    c       l     e      a     A  r   r        "},
			{"     ccccc  lllll eeeee  a     A  r   r        "},
			{"                                               "}
		},
		{
			{"                                               "},
			{"                                               "},
			{"     ccccc  l     eeeee     a     rrrr         "},
			{"    c       l     e       a   a   r   r        "},
			{"    c       l     eeeee   aaaaa   rrrr         "},
			{"    c       l     e      a     a  r   R        "},
			{"     ccccc  lllll eeeee  a     a  r   R        "},
			{"                                               "}
		},
	};
	clock_t inputZ = 0;
	clock_t inputX = 0;
	clock_t inputDot = 0;
	clock_t inputSlash = 0;
	bool isZ = false;
	bool isX = false;
	bool isDot = false;
	bool isSlash = false;
	int score = 0;
	int stac = 0;
	std::queue<clock_t> critical;
	std::string debugMessage = "-1";
	std::string PanzongMessage = "hello";
public:
	std::queue<std::pair<int,clock_t>> curNotes;
	void drawMap();
	void drawMenu();
	void drawResult();
	void inputNote(int N, int ms);
	void inputStar();
	void senseInput();
	void checkPressButton();
	void downNote();
	void checkPanzong(int N);
	std::string showDebugMessage();
	void inputDebugMessage(std::string message);
	std::string showPanzongMessage();
	void inputPanzongMessage(std::string message);
	int combo = 0;
	bool isStart = false;
	bool isExit = false;
};