#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

signed main(){
    int answer = 0, input;
    cin >> input;
    input = 1000 - input;
    while(input != 0){
        if(input >= 500){
            input -= 500;
            answer++;
        }else if(input >= 100){
            input -= 100;
            answer++;
        }else if(input >= 50){
            input -= 50;
            answer++;
        }else if(input >= 10){
            input -= 10;
            answer++;
        }else if(input >= 5){
            input -= 5;
            answer++;
        }else{
            input--;
            answer++;
        }
    }
    cout << answer << endl;
    return 0;
}
