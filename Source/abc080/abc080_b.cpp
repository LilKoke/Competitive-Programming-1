#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    char tmp, cnt = 0;
    int n = 0, waru = 0;
    int arr[10];
    while(cin >> tmp){
        waru += tmp - 48;
        arr[cnt] = tmp - 48;
        cnt++;
    }
  cnt--;
  	int j = 0;
    while(cnt >= 0){
        int ten = 1;
        REP(i, cnt){
            ten *= 10;
        }
        n += arr[j] * ten;
        cnt--;
      	j++;
    }
    if(n % waru == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
