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
static const int MOD = 1000000007;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation
#define pq priority_queue

int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

struct UnionFind{
    vector< int > data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if(x == y) return(false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return(true);
    }

    int find(int k)
    {
        if(data[k] < 0) return(k);
        return(data[k] = find(data[k]));
    }

    int size(int k)
    {
        return(-data[find(k)]);
    }
};

int main(){
    int n;
    cin >> n;
    vector<bool> dp(10010), ndp(10010), tmp(10010);
    REP(i, 10010) tmp[i] = false;
    tmp[0] = true;
    dp = ndp = tmp;
    REP(i, n){
        int p;
        cin >> p;
        ndp[p] = true;
        REP(j, 10010){
            if(dp[j]) ndp[j + p] = true;
        }
        dp = ndp;
    }
    int ans = 0;
    REP(i, 10010){
        if(dp[i]) ans++;
    }
    cout << ans << endl;
}

