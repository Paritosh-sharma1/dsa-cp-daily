/*
    Author : Paritosh Sharma
*/
#include <bits/stdc++.h>
using namespace std;

// Speed
#define fastio() ios::sync_with_stdio(0); cin.tie(0);

// Macros
#define endl "\n"
#define no  cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for(int i = 1; i <= b; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

// Enable Debug
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
    #define debug(x)
#endif

// Constants
const int MOD = 1e9 + 7;

// Typedefs
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef set<int> stt;

// Debugging print functions
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

// Maths
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

void printFactors(int n, vector<int>& fact) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            fact.push_back(i);
            if (i != n / i)
                fact.push_back(n / i);
        }
    }
}

long long lcm(ll a, ll b) {
    return (1LL * a * b) / __gcd(a, b);
}

bool isPerfectSquare(long long n) { 
    long long root = sqrt(n);
    return root * root == n;
}

bool isq(ll n) {
    return ceil(sqrtl(n)) == floor(sqrtl(n));
}

long long fact(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Practice Guidelines
// 1. Practice
// 2. Solve problems with editorials
// 3. Solving problems slightly above your level.
// 4. Solve an optimal number of problems like 200-400, not 2000-4000
// 5. Don't get stuck for long hours

void paritosh() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n + 1);
    vector<long long> odds, evens;
    
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if (i % 2 != 0) {
            odds.push_back(a[i]);
        } else {
            evens.push_back(a[i]);
        }
    }
    
    vector<int> x(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> x[i];
    }
    
    sort(odds.begin(), odds.end(), std::greater<long long>());
    sort(evens.begin(), evens.end(), std::greater<long long>());
    
    size_t ptr_odd = 0, ptr_even = 0;
    
    bool has_marked_odd = false, has_marked_even = false;
    
    for (int i = 0; i < m; ++i) {
        if (x[i] % 2 != 0) { 
            if (ptr_odd < odds.size()) {
                if (odds[ptr_odd] > 0 || !has_marked_odd) {
                    has_marked_odd = true;
                    ptr_odd++; 
                }
            }
        } else { 
            if (ptr_even < evens.size()) {
                if (evens[ptr_even] > 0 || !has_marked_even) {
                    has_marked_even = true;
                    ptr_even++;
                }
            }
        }
    }
    
    long long unmarked_sum = 0;
    for (size_t i = ptr_odd; i < odds.size(); ++i) {
        unmarked_sum += odds[i];
    }
    for (size_t i = ptr_even; i < evens.size(); ++i) {
        unmarked_sum += evens[i];
    }
    
    cout << unmarked_sum << "\n";
}

int main() {
    fastio();
    freopen("error.txt", "w", stderr);
    int t;
    cin >> t;
    while (t--) {
        paritosh();
    }
    return 0;
}