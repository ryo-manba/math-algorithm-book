// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define rep1(n)       for (int rep1_i= 0; rep1_i < n; rep1_i++)
#define rep2(i, n)    for (int i = 0; i < n; i++)
#define rep3(i, m, n) for (int i = m; i <= n; i++)
#define overload3(o1, o2, o3, name, ...) name
#define rep(...) overload3(__VA_ARGS__, rep3,rep2,rep1)(__VA_ARGS__)
#define INF ((1<<30)-1)
#define INFL ((1LL<<62)-1)
#define MOD 998244353
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
int dx[]={0, 0, -1, 1};
int dy[]={1, -1, 0, 0};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define debug(var)  do{std::cout << "[L:" << __LINE__ << "] " << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

const ll mod = 1e9 + 7;

ll modpow(ll a, ll b)
{
	ll res = 1;

	while (b > 0)
	{
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

ll division(ll a, ll b)
{
	return (a * modpow(b, mod - 2)) % mod;
}

ll solve(ll a, ll b)
{
	ll bunshi = 1, bunbo = 1;
	rep(i,1,a+b) {
		bunshi *= i;
		bunshi %= mod;
	}
	rep(i,1,a) {
		bunbo *= i;
		bunbo %= mod;
	}
	rep(i,1,b) {
		bunbo *= i;
		bunbo %= mod;
	}
	return division(bunshi, bunbo);
}

int main()
{
	ll x, y;
	cin >> x >> y;

	// 当差の最大で2倍
	if (max(x, y) / 2 > min(x, y)) {
		cout << 0 << endl;
		return 0;
	}

	// 何回ずつ操作が必要なのかを調査する
	// 差が大きい方を進める

	ll a = 0, b = 0;
	ll cnt_a = 0, cnt_b = 0;
	bool f = false;
	while (x >= a && y >= b)
	{
		if (x == a && y == b) {
			f = true;
			break;
		}
		// xの方が差が大きい場合
		if ((x - a) > (y - b)) {
			a += 2;
			b += 1;
			cnt_a += 1;
		} else {
			a += 1;
			b += 2;
			cnt_b += 1;
		}
	}

	if (f) cout << solve(cnt_a, cnt_b) << endl;
	else cout << 0 << endl;

	return 0;
}
