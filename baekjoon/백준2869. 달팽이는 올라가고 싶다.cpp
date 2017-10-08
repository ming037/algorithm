#ifndef debug
#include <iostream>
#include <string.h>
#include <queue>
#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#define lld long long
using namespace std;

int main()
{
	int a,b,v;
	scanf("%d %d %d", &a, &b, &v);
	int diff = a - b;
	double tmp = (double)v - a;
	tmp /= (double)diff;
	int res = ceil(tmp);
	printf("%d", res + 1);
}

#endif // !debug
