#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <queue>
#include <stack>
#define max_pos 100000
#define lld long long
using namespace std;

int n, k; //수빈위치n, 동생위치k
int cnt_res=-1;
int visit[max_pos+1] = { 0, };
queue<int> q;
stack<int> track;
int main()
{
	memset(visit, -1, sizeof(visit));
	scanf("%d %d", &n, &k);
	q.push(n);
	visit[n] = 987654321;
	int cnt = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int pos = q.front();
			q.pop();
			if (pos == k)
			{
				printf("%d\n", cnt);
				if (n >= k) for (int i = n; i >= k; i--) printf("%d ", i);
				else
				{
					int tmp = k;
					while (tmp != 987654321)
					{
						track.push(tmp);
						tmp = visit[tmp];
					}
					while (!track.empty()) {
						printf("%d ", track.top());
						track.pop();
					}
				}
				exit(0);
			}
			if (pos * 2 <= max_pos && visit[pos * 2] ==-1){
				q.push(pos * 2);
				visit[pos * 2] = pos;
			}
			if (pos - 1 >= 0 && visit[pos - 1] == -1){
				q.push(pos - 1);
				visit[pos -1] = pos;
			}
			if (pos + 1 <= max_pos && visit[pos + 1] == -1) {
				q.push(pos + 1);
				visit[pos +1 ] = pos;
			}
		}
		cnt++;
	}

}
