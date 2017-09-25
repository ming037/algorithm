#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <utility>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#define lld long long
#define mp make_pair
#define point pair<int, int>
using namespace std;

int solve(int n, int num)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += min(n, num / i);
	return cnt;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int left = 1, right = k;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (solve(n, mid) < k) left = mid + 1;
		else right = mid - 1;
	}
	printf("%d", left);
}
