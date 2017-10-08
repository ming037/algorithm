#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <queue>
#define max_pos 100000
#define lld long long
using namespace std;
struct point {
	int n, tel;
};
queue<point> q;
int n, k; //수빈위치n, 동생위치k
int cnt_res=-1;
int visit[max_pos+1] = { 0, };

int main()
{
	scanf("%d %d", &n, &k);
	q.push({ n , 0});
	int cnt = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int pos = q.front().n;
			int tel = q.front().tel;
			q.pop();
			visit[pos] = 1;
			if (pos == k)
			{
				printf("%d\n", cnt - tel);
				exit(0);
			}
			if (pos * 2 <= max_pos && !visit[pos * 2]){
				q.push({ pos * 2, tel + 1 });
				visit[pos * 2] = 1;
			}
			if (pos - 1 >= 0 && !visit[pos - 1]){
				q.push({ pos - 1,tel });
				visit[pos -1] = 1;
			}
			if (pos + 1 <= max_pos && !visit[pos + 1]) {
				q.push({ pos + 1,tel });
				visit[pos +1 ] = 1;
			}
		}
		cnt++;
	}

}
