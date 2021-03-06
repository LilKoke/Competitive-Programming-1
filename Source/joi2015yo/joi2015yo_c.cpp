#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    string str;
    int h, w, j, time[110][110];
    REP(i, 110){
        REP(j, 110){
            time[i][j] = -1;
        }
    }
    cin >> h >> w;
    REP(i, h){
        cin >> str;
        REP(j, w){
            if(str[j] == 'c'){
                time[i][j] = 0;
                int k = 1;
                while((time[i][j + k] > k || time[i][j + k] == -1) && j + k < 110){
                    time[i][j + k] = k;
                    k++;
                }
            }
        }
    }
    REP(i, h){
        REP(j, w){
            if(j == w - 1){
                cout << time[i][j] << endl;
            }else{
                cout << time[i][j] << " ";
            }
        }
    }
    return 0;
}
