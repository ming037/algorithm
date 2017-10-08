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
	int x, y, wall;
};
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0,1, 0, -1 };
int map[1001][1001] = { 0, };
int visit[1001][1001][11] = { 0, };
int n, m, k;
queue<point> q;
int bfs()
{
	int cnt = 1;
	q.push({ 0,0 });
	visit[0][0][0] = 1;
	while (!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			point front = q.front();
			int wall = front.wall;
			q.pop();
			if (front.x == n - 1 && front.y == m - 1)
			{
				printf("%d", cnt);
				exit(0);
			}
			for (int i = 0; i < 4; i++)
			{
				int tx = front.x + dx[i];
				int ty = front.y + dy[i];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m)
				{
					if (map[tx][ty] == 1 && wall + 1 <= k && !visit[tx][ty][wall + 1]) {
						visit[tx][ty][wall + 1] = 1;
						q.push({ tx,ty,wall + 1 });
					}
					if (map[tx][ty] == 0 && !visit[tx][ty][wall]) {
						visit[tx][ty][wall] = 1;
						q.push({ tx,ty,wall });
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
	scanf("%d %d %d ", &n, &m, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)scanf("%1d ", &map[i][j]);
	int res = bfs();
	if (res == -1) printf("-1");
}
