#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    string a, b, c;
    char flag = 'a';
    cin >> a >> b >> c;
    while(1){
        if(flag == 'a'){
            if(a.length() == 0){
                cout << "A" << endl;
                break;
            }
            flag = a[0];
            a = a.substr(1, a.length() - 1);
        }else if(flag == 'b'){
            if(b.length() == 0){
                cout << "B" << endl;
                break;
            }
            flag = b[0];
            b = b.substr(1, b.length() - 1);
        }else{
            if(c.length() == 0){
                cout << "C" << endl;
                break;
            }
            flag = c[0];
            c = c.substr(1, c.length() - 1);
        }
    }
    return 0;
}
