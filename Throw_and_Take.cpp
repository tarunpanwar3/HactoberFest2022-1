//#define ASC
//#define DBG_LOCAL

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("popcnt")


#define int long long

#define all(X) (X).begin(), (X).end()

#define pb push_back
#define endl '\n'
#define fi first
#define se second

const int mod = 1e9 + 7;
// const int mod=998'244'353;


const long long INF = 2e18 + 10;
// const int INF=1e9+10;

#define readv(x, n)   \
    vector<int> x(n); \
    for (auto &i : x) \
        cin >> i;



template <typename T>
    using v = vector<T>;

template <typename T>
    using vv = vector<vector<T>>;

template <typename T>
    using vvv = vector<vector<vector<T>>>;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<vector<double>> vvd;

typedef pair<int, int> pii;



int multiply(int a, int b, int in_mod) { return (int)(1LL * a * b % in_mod); }
int mult_identity(int a) { return 1; }



const double PI = acosl(-1);


auto power(auto a, auto b, const int in_mod)
{

    auto prod = mult_identity(a);
    auto mult = a ;
    while (b != 0)
    {
        if (b % 2)
        {
            prod = multiply(prod, mult, in_mod);
        }
        if(b/2)
        mult = multiply(mult, mult, in_mod);
        b /= 2;
    }
    return prod;
}
auto mod_inv(auto q, const int in_mod)
{
    return power(q, in_mod - 2, in_mod);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define stp cout << fixed << setprecision(20);

 
const int MAXN=4e6+10;
vector<int> fac(MAXN);
vector<int> infac(MAXN);
void build_factorial()
{
    fac[0]=1;
    infac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    infac[MAXN-1] = power(fac[MAXN -1], mod - 2,mod);
 
    for(int i= MAXN-2;i>=0;i--)
    {
        infac[i] = infac[i+1] *(i + 1)%mod;
    }
}
int ncr(int n, int r)
{
    if(n<r)
        return 0;
    return 1LL*fac[n] * infac[r]%mod  * infac[n-r]%mod;
}
 
void solv()
{
	int n;
	cin>>n;

	readv(c,n);
	readv(v,n);

	for(auto &i:c)
		i = i %2;


	vvi dp (n + 1, vi(2, 0));



	set<int> table_a;
	table_a.insert(0);

	set<int> table_b;
	table_b.insert(0);
	for(int i = n-1;i>=0;i--)
	{
		dp[i][0] = -INF;
		dp[i][1] =  INF;
		table_a.insert(c[i] * v[i] + dp[i+1][1]);
		table_b.insert(-c[i] * v[i] + dp[i+1][0]);

		dp[i][0] = *table_a.rbegin();
		dp[i][1] = *table_b.begin();


	}

	cout<<dp[0][0]<<endl;
}




void solve()
{
	build_factorial();
    // solvi();

    int t = 1;
    cin>>t;
    // t = 1;
    for(int i = 1;i<=t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solv();
    }

}




signed main()
{



    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);


#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);
    }
#endif
    auto clk = clock();
    // -------------------------------------Code starts here---------------------------------------------------------------------

    signed t = 1;
    // cin >> t;

    for (signed test = 1; test <= t; test++)
    {
        // cout<<"Case #"<<test<<": ";
        // cout<<endl;

        solve();
    }

    // -------------------------------------Code ends here------------------------------------------------------------------

    clk = clock() - clk;

    #ifndef ONLINE_JUDGE
    cerr << fixed << setprecision(6) << "\nTime: " << ((float)clk) / CLOCKS_PER_SEC << "\n";
    #endif
    return 0;
}
