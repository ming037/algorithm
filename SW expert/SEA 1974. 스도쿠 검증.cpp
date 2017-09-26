#include <iostream>
#include <cstdio>
using namespace std;

int map[9][9];
bool check()
{
	bool ch1[9][9] = { 0, }; //가로
	bool ch2[9][9] = { 0, }; //세로
	bool ch3[9][9] = { 0, }; //정사각형
	int cur_j, prev_j = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			ch1[i][map[i][j] - 1] = 1;
			ch2[map[j][i] - 1][i] = 1;
		}

		int cur_i = (i / 3) * 3;
		for (int t_i = cur_i; t_i < cur_i + 3; t_i++)
			for (cur_j = prev_j; cur_j < prev_j + 3; cur_j++)
				ch3[i][map[t_i][cur_j] - 1] = 1;
		prev_j = (prev_j + 3) % 3;
	}
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) if (!ch1[i][j] || !ch2[i][j] || !ch3[i][j]) return false;
	return true;
}
int main()
{
	int tc;
	scanf("%d ", &tc);
	for (int t = 1; t <= tc; t++)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) scanf("%d", &map[i][j]);
		printf("#%d %d\n", t, check());
	}
}
