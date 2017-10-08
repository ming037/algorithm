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

int visit[10000] = { 0, };
bool isprime(int num)
{
	bool res = true;
	if (num == 1) res = false;
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) {
			res = false;
			break;
		}
	}
	return res;
}

int change(int num, int pos, int to)
{//num의 pos를 to로
	int tmp[4];
	for (int i = 0; i < 4; i++)
	{
		tmp[3 - i] = num % 10;
		num /= 10;
	}
	int res = 0;
	tmp[pos] = to;
	for (int i = 0; i < 4; i++)
	{
		res += tmp[i];
		res *= 10;
	}
	return res/10;
}

queue<int> q;
int solve(int from, int to)
{
	int cnt = 0;
	q.push(from);
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int front = q.front();
			q.pop();

			if (front == to) return cnt;
			for (int pos = 0; pos < 4; pos++)
			{
				for (int j = 0; j <= 9; j++)
				{
					int tmp = change(front, pos, j);
					if (!visit[tmp] && tmp >= 1000 && isprime(tmp))
					{
						visit[tmp] = 1;
						q.push(tmp);
					}
				}
			}
		}
		cnt++;
	}
}

int main()
{
	int tc;
	scanf("%d ", &tc);
	while (tc--)
	{
		memset(visit, 0, sizeof(visit));
		while (!q.empty()) q.pop();
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", solve(a, b));
	}

}
