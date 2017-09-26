#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100010] = { 0, };
int dp[100010] = { 0, };
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	int res = arr[1];
	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i-1] + arr[i], arr[i]);
		res = max(res, dp[i]);
	}
	printf("%d", res);
}
