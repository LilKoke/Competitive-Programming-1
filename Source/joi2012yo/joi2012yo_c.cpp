#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int n, a, b, c, temp, cal;

int main(){
    vector<int> cal;
    cin >> n >> a >> b >> c;
    REP(i, n){
        cin >> temp;
        cal.pb(temp);
    }
    sort(cal.begin(), cal.end(), greater<int>());
    int ca = c, ne = a;
    int ans = c / a;
    REP(i, n){
        ca += cal[i];
        ne += b;

        ans = max(ans, ca / ne);
    }
    cout << ans << endl;
}
