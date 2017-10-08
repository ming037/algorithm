#ifndef debug
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <queue>
#include <stack>
#define lld long long
using namespace std;
int dx[] = { 0, 1, 0, -1 }; //오 아 왼 위
int dy[] = { 1,0, -1, 0 };
int map[101][101] = { 0, }; //1은 사과, 2는 뱀
int dir[101][101] = { 0, }; //방향 지도
struct point
{
	int x, y;
};

struct turn
{
	int a; //a초 후에 c방향
	char c;
};
int n,k,l; //맵크기n, 사과개수k, 방향변환l
queue<turn> change; //바뀌는 정보
queue<point> q;

int move()
{
	int cnt = 0;
	q.push({ 1,1});
	dir[1][1] = 0; //시작은 오른쪽
	map[1][1] = 2; //뱀
	while (!q.empty())
	{
		bool find = false;
		int size = q.size();
		int prev_dir;
		for(int i=1; i<=size; i++)
		{
			int fx = q.front().x;
			int fy = q.front().y;
			map[fx][fy] = 0; //뱀 지나감
			q.pop();
			if (!change.empty() && i == 1 && cnt == change.front().a) //머리의 방향 바꾸기
			{
				if (change.front().c == 'D') dir[fx][fy] = (dir[fx][fy] + 1) % 4;
				else dir[fx][fy] = (3 + dir[fx][fy]) % 4;
				change.pop();
			}
			int tx = fx + dx[dir[fx][fy]];
			int ty = fy + dy[dir[fx][fy]];
			if (map[tx][ty] == 2 || tx < 1 || tx > n || ty < 1 || ty > n)
				return cnt+1;
			if (map[tx][ty] == 1) find = true; //사과 이면
			q.push({ tx,ty });
			if(i==1) dir[tx][ty] = dir[fx][fy]; //머리는 길을 개척
			map[tx][ty] = 2;
			if (find && i == size) {
				q.push({ fx,fy });//꼬리 늘리기
				map[fx][fy] = 2;
			}
		}
		cnt++;
	}
}

int main()
{
	scanf("%d %d ", &n, &k);
	for (int i = 0,a,b; i < k; i++)
	{
		scanf("%d %d ", &a, &b);
		map[a][b] = 1;
	}
	scanf("%d ", &l);
	for (int i = 0; i < l ;i++)
	{
		int a;
		char b;
		scanf("%d %c ", &a, &b);
		change.push({ a,b });
	}
	printf("%d", move());
}

#endif // DEBUG
