#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    ll answer = 0, dp = 0, a[100010];
    REP(i, k){
        cin >> a[i];
        answer += a[i];
    }
    dp = answer;
    FOR(i, k, n){
        cin >> a[i];
        if(a[i] > a[i - k] && answer < dp + a[i] - a[i - k]){
            answer = dp + a[i] - a[i - k];
        }
        dp = dp + a[i] - a[i - k];
    }
    cout << answer << endl;
    return 0;
}
