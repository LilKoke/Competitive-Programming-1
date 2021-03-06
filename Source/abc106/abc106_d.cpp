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

#define all(c) (c).begin(), (c).end()

ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}


int main(){
  int n, m, q;
  cin >> n >> m >> q;
  int imos[500];
  int start[500];
  int end[500];
  int rui[500];
  int data[500][500];
  memset(data, 0, sizeof(data));
  REP(i, 500){
    imos[i] = start[i] = end[i] = rui[i] = 0;
  }
  REP(i, m){
    int l, r;
    cin >> l >> r;
    l--;
    imos[l]++;
    imos[r]--;
    rui[l]++;
    start[l]++;
    data[l][r - l - 1]++;
  }
  REP(i, 499){
    REP(j, 499){
      data[i+1][j] += data[i][j+1];
    }
  }
  REP(i, 500){
    REP(j, 499){
      data[i][j+1] +=data[i][j];
    }
  }
  REP(i, 499){
    imos[i + 1] += imos[i];
  }
  REP(i, 499){
    rui[i + 1] += rui[i];
  }
  /*
  REP(i, n){
    cout << imos[i] << endl;
  }
  cout << endl;
  REP(i, n){
    cout << start[i] << endl;
  }
  cout << endl;
  REP(i, n){
    cout << rui[i] << endl;
  }
  cout << endl;
  */
  REP(i, q){
    int l, r;
    cin >> l >> r;
    l--; r--;
    if(l == 0 && r == n - 1){
      cout << rui[r] << endl;
    }else if(l == 0){
      cout << rui[r] - (imos[r + 1] - start[r + 1]) << endl;
    }else if(r == n - 1){
      cout << rui[r] - rui[l - 1] << endl;
    }else{
      cout << rui[r] - (imos[r + 1] - start[r + 1]) - rui[l - 1] + data[l-1][499] - data[l-1][r-l+1] << endl;
    }
  }
  /*
  REP(i, n){
    REP(j, n){
      cout << data[i][499] - data[i][j - 1];
    }
  }
  */
}
