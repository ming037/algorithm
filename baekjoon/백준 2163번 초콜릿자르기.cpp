#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[90001];
int solve(int num)
{
	if (num == 1) return 0;
	if (num == 2) return 1;
	int &val = dp[num];
	if (val != -1) return val;
	val = 1+ solve(num / 2) + solve(num - num / 2);
	return val;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));
	printf("%d", solve(n*m));
}
