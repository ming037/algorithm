#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <utility>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#define lld long long
#define mp make_pair
#define point pair<int, int>
using namespace std;

int map[9][9];
vector<point> blank;
bool found = false;
void find(int pos, int cnt)
{
	if (cnt == 0)	{
		found = true;
		return;
	}
	point tmp_pos = blank[pos];
	int group_x = (tmp_pos.first / 3) * 3;
	int group_y = (tmp_pos.second / 3) * 3;
	for (int i = 1; i <= 9; i++)
	{//1부터 9까지 확인
		bool ch = true;
		for (int j = 0; j < 9; j++)
		{
			if (map[tmp_pos.first][j] == i) {//가로
				ch = false;
				break;
			}
			if (map[j][tmp_pos.second] == i) {//세로
				ch = false;
				break;
			}
		}
		if (ch)
		{//정사각형 확인
			for (int j = group_x; j <= group_x + 2; j++) {
				for (int k = group_y; k <= group_y + 2; k++) {
					if (map[j][k] == i) {
						ch = false;
						break;
					}
				}
			}
		}
		if (ch)
		{
			map[tmp_pos.first][tmp_pos.second] = i;
			find(pos + 1, cnt - 1);
			if (found) return;
			map[tmp_pos.first][tmp_pos.second] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d ", &map[i][j]);
			if (!map[i][j]) blank.push_back(mp(i, j));
		}
	}
	int size = blank.size();
	find(0, size);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}
