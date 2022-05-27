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

#define PI acos(-1)
/**
 * 時間: h, 分: m
 * 360 / 12 = 30
 * 360 / 60 = 6
 *
 * abs(30 * h - 6 * m) = 角度
 * 余弦定理から
 * c^2 = a^2 + b^2 -2ab cos C
 */

/**
 * @brief 度をラジアンに変換する。
 * @param degree 度
 * @return ラジアン
 */
double deg2rad(double degree)
{
    return degree * PI / 180.0;
}
int main()
{
	double a, b, h, m;
	cin >> a >> b >> h >> m;

	double hx, mx;

	hx = 30 * h + 0.5 * m;
	mx = 6 * m;

	double deg = abs(hx - mx);
	double rad = deg2rad(deg);
	double ans = (a*a) + (b*b) - 2*a*b * cos(rad);
	cout << sqrt(ans) << endl;
	return 0;
}
