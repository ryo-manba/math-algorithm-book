#include <bits/stdc++.h>
#define rep1(n)       for (int rep1_i= 0; rep1_i < n; rep1_i++)
#define rep2(i, n)    for (int i = 0; i < n; i++)
#define rep3(i, m, n) for (int i = m; i < n; i++)
#define overload3(o1, o2, o3, name, ...) name
#define rep(...) overload3(__VA_ARGS__, rep3,rep2,rep1)(__VA_ARGS__)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
const int INF = (int)1e9;
const ll INFL = (ll)1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
int dx[]={0, 0, -1, 1};
int dy[]={1, -1, 0, 0};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

ll cross(ll ax, ll ay, ll bx, ll by)
{
	return ax * by - ay * bx;
}

int main()
{
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	cin >> x4 >> y4;

	// cross(ab, ac) を計算
	ll ans1 = cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
	ll ans2 = cross(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
	ll ans3 = cross(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
	ll ans4 = cross(x4 - x3, y4 - y3, x2 - x3, y2 - y3);

	// すべて一直線上に並んでいる場合
	if (ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0) {
		pair<ll, ll> a = make_pair(x1, y1);
		pair<ll, ll> b = make_pair(x2, y2);
		pair<ll, ll> c = make_pair(x3, y3);
		pair<ll, ll> d = make_pair(x4, y4);
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		// a   b
		// -----
		//    -----
		//    c   d
		// 半開区間が共通部分を持つ必要十分条件
		if (max(a, c) <= min(b, d)) cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}

	// isAB：線分 AB が点 C, D を分けるか?
	// isCD：線分 CD が点 A, B を分けるか?
	bool isAB = false, isCD = false;
	if (ans1 >= 0 && ans2 <= 0) isAB = true;
	if (ans1 <= 0 && ans2 >= 0) isAB = true;
	if (ans3 >= 0 && ans4 <= 0) isCD = true;
	if (ans3 <= 0 && ans4 >= 0) isCD = true;

	if (isAB == true && isCD == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
