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

double dist(double ax, double ay, double bx, double by)
{
	return sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
}
int main()
{
	int n;
	cin >> n;
	vector<pair<double, double> > p(n);
	rep(i,n) cin >> p[i].first >> p[i].second;

	double ans = INF;
	rep(i,n)
	{
		for (int j = i + 1; j < n; j++)
		{
			chmin(ans, dist(p[i].first, p[i].second, p[j].first, p[j].second));
		}
	}
	cout << ans << endl;
	return 0;
}
