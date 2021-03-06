#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;



int main(){
    ll n;
    ll a[100010], dp[100010];
    cin >> n;
    REP(i, n){
        cin >> a[i];
    }
    REP(i, 100010){
        dp[i] = 0;
    }
    dp[0] = 0;
    dp[1] = llabs(a[1] - a[0]);
    FOR(i, 2, n){
        dp[i] = min(dp[i - 2] + llabs(a[i] - a[i - 2]), dp[i - 1] + llabs(a[i] - a[i - 1]));
    }
    cout << dp[n - 1] << endl;
}
