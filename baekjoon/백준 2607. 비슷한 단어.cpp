#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

string input[100];
int standard[26] = { 0, };
int cmp[26] = { 0, };
int main()
{
	int n,res =0;
	cin >> n;
	for(int i=0; i<n; i++) cin >> input[i];
	int size = input[0].size();
	for (int i = 0; i < size; i++) standard[input[0][i] - 'A'] += 1;
	for (int i = 1; i < n; i++)
	{
		int need = 0, d_need =0;
		size = input[i].size();
		memset(cmp, 0, sizeof(cmp));
		for (int j = 0; j < size; j++) cmp[input[i][j] - 'A'] += 1;
		for (int j = 0; j < 26; j++) {
			if (standard[j] && !cmp[j]) need+= standard[j];
			if (standard[j] && cmp[j])
			{
				if (standard[j] > cmp[j]) need += (standard[j] - cmp[j]);
				else d_need += (cmp[j] - standard[j]);
			}
			if (!standard[j] && cmp[j]) d_need+= cmp[j];
		}	
		if (max(need, d_need) <= 1) res++;
	}
	cout << res;
}