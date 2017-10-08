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
int visit[100000] = { 0, };
struct num
{
	int n;
	lld res;
};
char dslr[] = "DSLR";
int L(int num)
{
	int temp = 0;
	temp += num / 1000;
	num = num % 1000;
	temp += num / 100 * 1000;
	num = num % 100;
	temp += num / 10 * 100;
	num = num % 10;
	temp += num * 10;
	return temp;
}
int R(int num)
{
	int temp = 0;
	temp += num / 1000 * 100;
	num = num % 1000;
	temp += num / 100 * 10;
	num = num % 100;
	temp += num / 10;
	num = num % 10;
	temp += num * 1000;
	return temp;
}
queue<num> q;
int bfs(int from, int to)
{
	q.push({ from,1 });
	visit[from] = 1;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			num f = q.front();
			int t_res = f.res;
			if (f.n == to) return t_res;
			q.pop();
			int d = (f.n * 2) % 10000;
			if (!visit[d]) {
				visit[d] = 1;
				q.push({ d,t_res*4 + 0 });
			}
			int s =  f.n - 1;
			if (s < 0) s = 9999;

			if (!visit[s]) {
				visit[s] = 1;
				q.push({ s,t_res* 4 + 1 });
			}
			int l = L(f.n);
			if (!visit[l]) {
				visit[l] = 1;
				q.push({ l,t_res* 4 + 2 });
			}
			int r = R(f.n);
			if (!visit[r]) {
				visit[r] = 1;
				q.push({ r,t_res* 4 + 3 });
			}
		}
	}
}

int main()
{
	int tc, from, to;
	scanf("%d ", &tc);
	while (tc--)
	{
		memset(visit, 0, sizeof(visit));
		while (!q.empty()) q.pop();
		scanf("%d %d ", &from, &to);
		int res = bfs(from, to);
		stack<char> output;
		while (res != 1)
		{
			output.push(dslr[res % 4]);
			res /= 4;
		}
		while (!output.empty())
		{
			printf("%c", output.top());
			output.pop();
		}
		printf("\n");
	}
}

#endif // DEBUG
