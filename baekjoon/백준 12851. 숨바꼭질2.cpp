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
queue<int> q;
int n, k; //수빈위치n, 동생위치k
int cnt_res=-1;
int visit[max_pos+1] = { 0, };
int main()
{
	scanf("%d %d", &n, &k);
	q.push(n);
	int cnt = 0;
	lld tmp_cnt = 0;
	while (!q.empty())
	{
		if (cnt_res != -1) break;
		int size = q.size();
		tmp_cnt = 0;
		for (int i = 0; i < size; i++)
		{
			int pos = q.front();
			q.pop();
			visit[pos] = 1;
			if (pos == k)
			{
				visit[pos] = 0;
				cnt_res = cnt;
				tmp_cnt++;
			}
			if (pos * 2 <= max_pos && !visit[pos * 2]) q.push(pos * 2);
			if (pos -1 >= 0 && !visit[pos -1]) q.push(pos-1);
			if (pos +1 <= max_pos && !visit[pos + 1]) q.push(pos + 1);
		}
		cnt++;
	}
	printf("%d\n%lld", cnt_res, tmp_cnt);
}
