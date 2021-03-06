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
static const ll INF = 1000010000;
static const ll MOD = 1000000007;
 
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb push_back
#define mp make_pair
#define np next_permutation

//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};


int main(){

    ll n;
    cin >> n;

    vector<ll> a(n * 3);
    REP(i, n * 3) cin >> a[i];

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    priority_queue<ll, vector<ll>> bq;
    ll frontsum = 0, backsum = 0;
    ll fs[100010], bs[100010];

    REP(i, n){
       frontsum += a[i];
       pq.push(a[i]);
    }

    fs[0] = frontsum;
    
    REP(i, n){
        if(pq.top() < a[n + i]){
            frontsum = frontsum - pq.top() + a[n + i];
            pq.pop();
            pq.push(a[n + i]);
        }
        fs[i + 1] = frontsum;
    }

    
    REP(i, n){
        backsum += a[n * 2 + i];
        bq.push(a[n * 2 + i]);
    }

    bs[n] = backsum;

    for(ll i = n - 1; i >= 0; i--){
        if(bq.top() > a[n + i]){
            backsum = backsum - bq.top() + a[n + i];
            bq.pop();
            bq.push(a[n + i]);
        }
        bs[i] = backsum;
    }

    ll ans = -100000 * INF;

    REP(i, n + 1){
        ans = max(ans, fs[i] - bs[i]);
    }

    cout << ans << endl;

}
