#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    string str;
    cin >> str;
    REP(i, str.length()){
        char c;
        c = str[i];
        if((int)c <= 67){
            c = (char)((int)c + 23);
            cout << c;
        }else{
            c = (char)((int)c - 3);
            cout << c;
        }
    }
    cout << endl;
    return 0;
}
