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
	int n;
	cin >> n;
	vector<int> t(n), x(n), y(n);
	REP(i, n){
		cin >> t[i] >> x[i] >> y[i];
	}
	int prex = 0, prey = 0, pret = 0;
	bool flag = true;
	REP(i, n){
		int dist = abs(x[i] - prex) + abs(y[i] - prey);
		if(dist <= t[i] - pret && (t[i] - pret - dist) % 2 == 0){
			
		}else{
			flag = false;
		}
		prex = x[i];
		prey = y[i];
		pret = t[i];		
	}
	if(flag){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}
