#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <queue>
#include <stack>
#define lld long long
using namespace std;
struct point
{
	int x, y;
};
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int r, c; //세로, 가로
point k_st;//고슴도치
char map[51][51] = { 0, };
bool w_visit[51][51] = { 0, };
bool k_visit[51][51] = { 0, };
queue<point> wt;
queue<point> ka;
void spread()
{
	int size = wt.size();
	for (int i = 0; i < size; i++) {
		point front = wt.front();
		wt.pop();
		for (int j = 0; j < 4; j++)
		{
			int tx = front.x + dx[j];
			int ty = front.y + dy[j];
			if (!w_visit[tx][ty] && tx >= 0 && tx < r && ty >= 0 && ty < c)
			{
				if (map[tx][ty] != 'D' && map[tx][ty] != 'X')
				{
					wt.push({ tx,ty });
					w_visit[tx][ty] = 1;
					map[tx][ty] = '*';
				}
			}
		}
	}
}

int move()
{
	int cnt = 0;
	int flag = true;
	ka.push({ k_st.x, k_st.y });
	while (!ka.empty())
	{
		int size = ka.size();
		for (int i = 0; i < size; i++)
		{
			point front = ka.front();
			ka.pop();
			if (map[front.x][front.y] != '*') //물에 잡아 먹히지 않은 것만
			{
				for (int j = 0; j < 4; j++)
				{
					int tx = front.x + dx[j];
					int ty = front.y + dy[j];
					if (!k_visit[tx][ty] && tx >= 0 && tx < r && ty >= 0 && ty < c)
					{
						if (map[tx][ty] == 'D')
						{
							flag = false;
							break;
						}
						if (map[tx][ty] != '*' && map[tx][ty] != 'X')
						{
							k_visit[tx][ty] = 1;
							ka.push({ tx,ty });
							map[tx][ty] = 'S';
						}
					}
				}
			}
			if (!flag) break;
		}
		cnt++;
		if (!flag) break;
		spread();
	}
	if (!flag) return cnt;
	else return -1;
}


int main()
{
	scanf("%d %d ", &r, &c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%c ", &map[i][j]);
			if (map[i][j] == 'S') k_st = { i,j }, k_visit[i][j] =1;
			if (map[i][j] == '*') w_visit[i][j] = 1, wt.push({i,j});
		}
	}
	int res = move();
	if (res == -1) printf("KAKTUS");
	else printf("%d", res);



}
