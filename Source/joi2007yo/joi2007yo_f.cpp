#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    ll dp[19][19];
    REP(i, 18){
        REP(j, 18){
            dp[i][j] = 0;
        }
    }
    dp[0][1] = 1;
    int a, b, n, x, y;
    cin >> a >> b >> n;
    REP(i, n){
        cin >> x >> y;
        dp[x][y] = -1;
    }
    FOR(i, 1, b + 1){
        FOR(j, 1, a + 1){
            if(dp[j][i] == -1){
                dp[j][i] = 0;
            }else{
                dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}
