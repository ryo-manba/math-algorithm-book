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
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

// 素因数分解 O(sqrt(n))
// <素数, 割れる回数>
vector<pair<ll, ll>> prime_factor(ll n)
{
	vector<pair<ll, ll>> ret;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i != 0) continue;
		ll tmp = 0;
		while (n % i == 0) {
			tmp += 1;
			n /= i;
		}
		ret.push_back({i, tmp});
	}
	if (n != 1) ret.push_back({n, 1});
	return ret;
}

// SPFを利用
template <typename T>
struct PrimeFact {
	vector<T> spf;
	PrimeFact(T N) { init(N); }

	// 前処理 spfを求める
	void init(T N) {
		spf.assign(N + 1, 0);
		for (T i = 0; i <= N; i++) spf[i] = i;
		for (T i = 2; i * i <= N; i++) {
			if (spf[i] == i) {
				for (T j = i * i; j <= N; j += i) {
					if (spf[j] == j) {
						spf[j] = i;
					}
				}
			}
		}
	}

	// n の素因数分解を求める
	map<T, T> get(T n) {
		map<T, T> m;
		while (n != 1) {
			m[spf[n]] += 1;
			n /= spf[n];
		}
		return m;
	}
};


int main()
{
	ll n;
	cin >> n;

	ll ans = 0;
	PrimeFact pf(n);
	rep(i,1,n)
	{
		ll cnt = 1;
		auto p = pf.get(i);
		for (auto [k, v] : p)
		{
			cnt *= (1 + v);
		}
		ans += cnt * i;
	}
	cout << ans << endl;
	return 0;
}
