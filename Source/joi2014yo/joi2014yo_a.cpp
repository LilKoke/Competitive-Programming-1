#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int tmp, sum = 0;
    REP(i, 5){
        cin >> tmp;
        if(tmp < 40){
            sum += 8;
        }else{
            sum += tmp / 5;
        }
    }
    cout << sum << endl;
}
