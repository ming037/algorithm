#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;


long long S, C;
long long L[1000005];
long long res = 0;
long long all = 0;
long long div(long long num) //개수 리턴
{
	long long result = 0;
	for (int i = 0; i<S; i++)
		result += (L[i] / num);
	return result;
}

void bst(long long st, long long end)
{
	if (st>end) return;
	long long mid = (st + end) / 2;
	long long check = div(mid);
	if (check < C) {
		bst(st, mid - 1);
	}
	else // 파를 더 크게
	{
		if (check >= C && check*mid <= all) res = max(res, mid);
		bst(mid + 1, end);
	}
}

int main()
{
	long long max = 0;
	cin >> S >> C;
	for (int i = 0; i<S; i++) {
		scanf("%lld", &L[i]);
		all += L[i];
		if (L[i] > max) max = L[i];
	}
	bst(1, max);
	printf("%lld", all - res*C);
}
