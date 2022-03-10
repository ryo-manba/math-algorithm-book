#include <iostream>
using namespace std;

/**
 * base 2, number = 1011
 * 8 * 1 = 8
 * 4 * 0 = 0
 * 2 * 1 = 2
 * 1 * 1 = 1
 * ans = 11
 */
// 2~9進法から10進法に変換する
long long base_conv(int base, string number)
{
	long long ans = 0;
	long long t = 1;
	reverse(number.begin(), number.end());
	for (auto c : number)
	{
		ans += (t * (c - '0'));
		t *= base;
	}
	return ans;
}

/**
 * base 2, number = 11
 * 11 / 2 = 5 mod 1
 * 5  / 2 = 2 mod 1
 * 2  / 2 = 1 mod 0
 * 1  / 2 = 0 mod 1
 * ans = 1101
 */
// 10進法から2~9進法に変換する
string decimal_conv(int base, long long number)
{
	string ans;
	while (number > 0)
	{
		ans += (number % base + '0');
		number /= base;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(void)
{
	int	base;
	string s;
	long long n;
	cin >> base >> s >> n;
	cout << base_conv(base, s) << endl;
	cout << decimal_conv(base, n) << endl;
	return 0;
}
