#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
static const int INF = 1000010000;
static const ll MOD = 1000000007;
 
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue
 

//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

int gcd(int x, int y) {
    return x ? gcd(y % x, x) : y;
}

int rev(int x){
    if(x < 10){
        return x;
    }else if(x < 100){
        return (x % 10) * 10 + x / 10;
    }else{
        return (x % 10) * 100 + (x % 100 - x % 10) + x / 100;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    FOR(i, 1, n + 1) FOR(j, 1, m + 1){
        ans++;
        int x = i, y = j;
        int f = 0;
        while(f < 1500){
            if(x == 0 || y == 0){
                ans--;
                break;
            }
            if(x <= y) x = rev(x);
            else y = rev(y);
            if(x <= y) y = y - x;
            else x = x - y;
            f++;
        }
    }
    cout << ans << endl;
}
