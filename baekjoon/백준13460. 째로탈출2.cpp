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
#define found -1
using namespace std;
struct point
{
	int rx, ry ,bx, by;
	bool rflag,bflag;
};
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;
char map[11][11];
bool visit[11][11][11][11] = { 0, };
queue<point> q;

point tilt(point p, int d)
{//p에서, d방향으로 기울인다.
	int rx = p.rx, ry = p.ry;
	int bx = p.bx, by = p.by;
	bool rflag=false, bflag=false;
	while (1)
	{
		bool rmv = false, bmv = false; //움직이면 true
		//red 움직임
		while (!rflag && map[rx + dx[d]][ry + dy[d]] != '#' && (rx + dx[d] != bx || ry + dy[d] != by))
		{
			rx += dx[d];
			ry += dy[d];
			if (map[rx][ry] == 'O') {
				rx = found, ry = found;
				rflag = true;
			}
			rmv = true;
		}
		//blue 움직임
		while (!bflag && map[bx + dx[d]][by + dy[d]] != '#' && (bx + dx[d] != rx || by + dy[d] != ry))
		{
			bx += dx[d];
			by += dy[d];
			if (map[bx][by] == 'O') {
				bx = found, by = found;
				bflag = true;
			}
			bmv = true;
		}
		if (!rmv && !bmv) break; //둘 다 움직이지 않았으면
	}
	return { rx,ry,bx,by, rflag, bflag };
}

int bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		if (cnt >= 10) return -1;
		int size = q.size();
		while (size--)
		{
			point f = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				point after = tilt(f, i);
				if (after.bflag) continue;
				if (!after.bflag && after.rflag) return cnt+1;
				if (after.rx > 0 && after.rx < n - 1 && after.ry>0 && after.ry < m - 1
					&& after.bx>0 && after.bx < n - 1 && after.by>0 && after.by < m - 1)
				{
					if (!visit[after.rx][after.ry][after.bx][after.by])
					{
						visit[after.rx][after.ry][after.bx][after.by] = 1;
						q.push(after);
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
	point tmp;
	tmp.rflag = false, tmp.bflag = false;
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			scanf("%1c ", &map[i][j]);
			if (map[i][j] == 'R') tmp.rx = i, tmp.ry= j;
			if (map[i][j] == 'B') tmp.bx = i, tmp.by = j;
		}
	}
	q.push(tmp);
	visit[tmp.rx][tmp.ry][tmp.bx][tmp.by] = 1;
	printf("%d", bfs());

}

#endif // DEBUG
