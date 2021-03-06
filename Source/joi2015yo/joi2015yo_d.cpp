#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

#define MAX 10000000000

ll n, m, c[1010], d[1010], dp[1010][1010];

int main(){
    cin >> n >> m;
    REP(i, n){
        cin >> d[i];
    }
    REP(i, m){
        cin >> c[i];
    }
    REP(i, 1010){
        REP(j, 1010){
            dp[i][j] = MAX;
        }
        dp[i][0] = 0;
    }
    FOR(i, 1, m + 1){
        FOR(j, 1,  n + 1){
            if(m - i >= n - j && i >= j){
                if(dp[i - 1][j - 1] + c[i - 1] * d[j - 1] <= dp[i - 1][j]){
                    dp[i][j] = dp[i - 1][j - 1] + c[i - 1] * d[j - 1];
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    cout << dp[m][n] << endl;
}
