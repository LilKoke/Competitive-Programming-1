#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
 
typedef long long ll;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)

int main(){
    string str;
    cin >> str;
    int ans = 0;
    REP(i, str.length()){
        ans += str[i] - '0';
    }
    ans = max(ans, ((int)str.length() - 1) * 9);
    if(str[0] != '1'){
        ans = max(ans, ((int)str.length() - 1) * 9 + str[0] - '1');
    }
    cout << ans << endl;
}

