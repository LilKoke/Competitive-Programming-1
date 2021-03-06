#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int n, c, s, t, hoge;
    cin >> n >> c;
    int table[100010];
    bool flag[31][100010];
    REP(i, 31){
        REP(j, 100010){
            flag[i][j] = false;
        }
    }
    REP(i, 100010){
        table[i] = 0;
    }
    REP(i, n){
        cin >> s >> t >> hoge;
        table[s - 1]++;
        table[t]--;
        if(flag[hoge][s]){
            table[s - 1]--;
            table[s]++;
        }
        if(flag[hoge][t]){
            table[t]++;
            table[t - 1]--;
        }
        flag[hoge][s] = flag[hoge][t] = true;
    }
    REP(i, 100010){
        if(i == 0) continue;
        table[i] += table[i - 1];
    }
    int ans = 0;
    REP(i, 100001){
        if(ans < table[i]){
            ans = table[i];
        }
    }
    cout << ans << endl;
}
