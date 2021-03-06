#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

static ll N = 100010;

int main(){
    ll n, m, table[N], a, b, c, from, to, ans = 0;
    cin >> n >> m >> from; from--;
    REP(i, N) table[i] = 0;
    REP(i, m - 1){
        cin >> to; to--;
        if(from < to){
            table[from]++;
            table[to]--;
        }else{
            table[to]++;
            table[from]--;
        }
        from = to;
    }
    REP(i, N){
        if(i == 0) continue;
        table[i] += table[i - 1];
    }
    REP(i, n - 1){
        cin >> a >> b >> c;
        if(table[i] * a < table[i] * b + c){
            ans += table[i] * a;
        }else{
            ans += table[i] * b + c;
        }
    }
    cout << ans << endl;
}
