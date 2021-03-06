#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int cost[100010], ans = 0, x = 1, n, m, s, a;
    cost[1] = 0;
    cin >> n >> m;
    FOR(i, 2, n + 1){
        cin >> s;
        cost[i] = cost[i - 1] + s;
    }
    REP(i, m){
        cin >> a;
        if(a > 0){
            ans = (ans + cost[x + a] - cost[x]) % 100000;            
        }else{
            ans = (ans + cost[x] - cost[x + a]) % 100000;
        }
        x += a;
    }
    cout << ans << endl;
}
