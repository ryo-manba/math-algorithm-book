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

/**
 * 円a, b の中心間の距離を d とすると
 * 以下の5パターンに分けられる
 * 条件 r1 > r2
 *
 * [1]　一方の円が他方の円を完全に含み、2 つの円は接していない
 *  d < r1 - r2
 * [2]　一方の円が他方の円を完全に含み、2 つの円は接している
 *  d = r1 - r2
 * [3]　2 つの円が互いに交差する
 *  r1 - r2 < d < r1 + r2
 * [4]　2 つの円の内部に共通部分は存在しないが、2 つの円は接している
 *  d = r1 + r2
 * [5]　2 つの円の内部に共通部分は存在せず、2 つの円は接していない
 *  d > r1 + r2
 */
int main()
{
	pair<double, double> a, b;
	double r1, r2;
	cin >> a.first >> a.second >> r1;
	cin >> b.first >> b.second >> r2;

	if (r1 < r2) swap(r1, r2);
	double d;
	d = sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));

	int ans = 0;
	if (d < r1 - r2) ans = 1;
	if (d == r1 - r2) ans = 2;
	if (r1 - r2 < d && d < r1 + r2) ans = 3;
	if (d == r1 + r2) ans = 4;
	if (d > r1 + r2) ans = 5;
	cout << ans << endl;
	return 0;
}
