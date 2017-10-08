#ifndef debug
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
	int x, y, key;
};
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;
char map[51][51];
bool visit[51][51][1<<6] = { 0, }; //key는 6개
queue<point> q;
point st; //시작 위치

int get_key(int curr, char key)
{//curr 에 key 추가
	return curr | (1 << (key - 'a'));
}
bool has_key(int curr, char door)
{//curr에 door의 key가 있는지
	return curr & (1 << (door - 'A'));
}
int bfs()
{
	int cnt = 0;
	q.push(st);
	visit[st.x][st.y][st.key] = 1;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			point f = q.front();
			if (map[f.x][f.y] == '1' ) return cnt;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int tx = f.x + dx[i];
				int ty = f.y + dy[i];
				if (map[tx][ty]!='#' && tx >= 0 && tx < n && ty >= 0 && ty < m)
				{
					if (map[tx][ty] >= 'a' && map[tx][ty] <= 'f') //열쇠 일 때
					{
						int new_key = get_key(f.key, map[tx][ty]);
						if (!visit[tx][ty][new_key])
						{
							q.push({ tx,ty, new_key });
							visit[tx][ty][new_key] = 1;
						}

					}
					else if (map[tx][ty] >= 'A' && map[tx][ty] <= 'F') //문 일 때
					{
						if (has_key(f.key, map[tx][ty]) && !visit[tx][ty][f.key])
						{
							q.push({ tx,ty,f.key });
							visit[tx][ty][f.key] = 1;
						}
					}
					else // 그 외..
					{
						if (!visit[tx][ty][f.key])
						{
							q.push({ tx,ty,f.key });
							visit[tx][ty][f.key] = 1;
						}
					}
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main()
{
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			scanf("%1c ", &map[i][j]);
			if (map[i][j] == '0') st = {i,j,0};
		}
	}
	printf("%d", bfs());
}

#endif // DEBUG
