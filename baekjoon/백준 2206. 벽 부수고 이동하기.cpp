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
	int x, y, cnt;
};
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0,1, 0, -1 };
int map[1001][1001] = { 0, };
int visit[1001][1001]= { 0, };
int b_visit[1001][1001]{ 0, };
int n, m;
queue<point> q;
int bfs()
{
	int cnt = 1;
	q.push({ 0,0 });
	visit[0][0] = 1;
	b_visit[0][0] = 1;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			point front = q.front();
			q.pop();
			if (front.cnt == 1) b_visit[front.x][front.y] = 1;
			else visit[front.x][front.y] = 1;
			if (front.x == n - 1 && front.y == m - 1)
			{
				printf("%d", cnt);
				exit(0);
			}
			for (int j = 0; j < 4; j++)
			{
				int tx = front.x + dx[j];
				int ty = front.y + dy[j];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m)
				{
					if (front.cnt == 0)
					{//이 전까지 안 부순 경우
						if (map[tx][ty] == 1 && !b_visit[tx][ty])
							q.push({ tx,ty,1 });
						if (map[tx][ty] != 1 && !visit[tx][ty])
							q.push({ tx,ty,0 });

					}
					else
					{
						if (map[tx][ty] != 1 && !b_visit[tx][ty])
							q.push({ tx,ty,1 });
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
		for (int j = 0; j < m; j++)scanf("%1d ", &map[i][j]);
	int res = bfs();
	if (res == -1) printf("-1");
}
