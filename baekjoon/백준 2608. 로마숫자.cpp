#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int conv[26];
conv['I' - 'A'] = 1;
conv['V' - 'A'] = 5;
conv['X' - 'A'] = 10;
conv['L' - 'A'] = 50;
conv['C' - 'A'] = 100;
conv['D' - 'A'] = 500;
conv['M' - 'A'] = 1000;

int getnum(string& s)
{
	int num = 0;
	int size = s.size();
	for (int i = 0; i < size;)
	{
		if (s[i + 1] == 'a') num += conv[s[i] - 'A'];
		else
		{
			if (conv[s[i + 1]] > conv[s[i]]) {
				num += (conv[s[i + 1]] - conv[s[i]]);
				i += 2;
			}
			else {
				num += (conv[s[i]]);
				i += 1;
			}
		}
	}
	return num;
}
int main()
{
	string a, b;
	int num1 = 0, num2 = 0;
	cin >> a >> b;
	a.push_back('a');
	b.push_back('a');
	num1 = getnum(a);
	num2 = getnum(b);
	cout << num1 + num2;

}