#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define INF 100010

using namespace std;

typedef pair<ll, int> P;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> c[11];
    REP(i, n){
        int x, y;
        cin >> x >> y;
        c[y].pb(x);
    }
    FOR(i, 1, 11){
        c[i].pb(INF);
        sort(c[i].begin(), c[i].end(), greater<int>());
    }
    FOR(i, 1, 11){
        FOR(j, 2, c[i].size()) c[i][j] += c[i][j - 1];
        FOR(j, 2, c[i].size()) c[i][j] += (j - 1) * j;
        c[i][0] = 0;
    }
    int cnt = 0;
    int dp[11][2010];
    REP(i, 11) fill(dp[i], dp[i] + 2010, 0);
    FOR(i, 1, 11){
        REP(j, c[i].size()){
            REP(m, cnt + 1){
                dp[i][j + m] = max(dp[i][j + m], max(dp[i - 1][m] + c[i][j], dp[i - 1][j + m]));
            }
        }
        REP(j, 2010) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        cnt += c[i].size() - 1;
    }
    cout << dp[10][k] << endl;
 }
