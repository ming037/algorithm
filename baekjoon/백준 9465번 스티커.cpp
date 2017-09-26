#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n;
int sticky[2][100010] = { 0, };
int dp[2][100010] = { 0, };
int solve()
{
	for (int i = 2; i <= n+1; i++)
	{
		dp[0][i] = max(max(dp[0][i - 1], dp[1][i - 1] + sticky[0][i]), dp[1][i - 2] + sticky[0][i]);
		dp[1][i] = max(max(dp[1][i - 1], dp[0][i - 1] + sticky[1][i]), dp[0][i - 2] + sticky[1][i]);
	}
	return max(dp[0][n + 1], dp[1][n + 1]);
}
int main()
{
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (int i = 0; i < 2; i++)
			for (int j = 2; j <= n+1; j++) scanf("%d", &sticky[i][j]);
		printf("%d\n", solve());
	}
}
