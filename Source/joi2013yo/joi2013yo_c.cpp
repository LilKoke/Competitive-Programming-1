#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int n, answer = 0;
    bool flag = false;
    string name, panel;
    cin >> n >> name;
    REP(i, n){
        cin >> panel;
        for(int j = 1; (name.length() - 1) * j <= panel.length() - 1; j++){
            if(flag){
                break;
            }else{
                int k = 0, l = 0;
                while(1){
                    if(k == name.length()){
                        flag = true;
                        answer++;
                        break;
                    }else if(panel[l + k * j] != name[k]){
                        l++;
                        if(l == panel.length() - (name.length() - 1) * j){
                            break;
                        }
                        k = -1;
                    }
                    k++;
                }
            }
        }
        flag = false;
    }
    cout << answer << endl;
}
