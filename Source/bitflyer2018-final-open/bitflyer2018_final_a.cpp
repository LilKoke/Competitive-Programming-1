#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <bitset>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
static const int INF = 1000010000;
static const int NIL = -1;
static const int MOD = 1000000007;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

int main(){
    int n;
    cin >> n;
    int ans = 10;
    REP(i, n){
        int p;
        cin >> p;
        int cnt = 0;
        while(1){
            if(p < 10 || p % 10 != 0) break;
            else cnt += 1;
            p /= 10;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

