#ifndef debug
#include <iostream>
#include <string.h>
#include <queue>
#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#define lld long long
using namespace std;

int bin[31];
int main()
{
	lld k;
	scanf("%lld", &k);
	k += 1;
	int cnt = 0;
	while (k)
	{
		bin[cnt++] = k % 2;
		k /= 2;
	}
	reverse(bin, bin + cnt);
	for (int i = 1; i < cnt; i++)
	{
		if (!bin[i]) printf("4");
		else printf("7");
	}
}

#endif // !debug
