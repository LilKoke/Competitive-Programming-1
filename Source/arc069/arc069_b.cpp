#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
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

//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};

int main(){
    int num;
	cin >> num;
	string s;
	cin >> s;
	REP(p, 2){
		REP(q, 2){
			vector<int> ans;
			ans.push_back(p), ans.push_back(q);
			REP(i, num){
				if(s[i] == 'o') ans.push_back(ans[i] ^ ans[i + 1]);
				else ans.push_back(ans[i] ^ ans[i + 1] ^ 1);
			}
			if(ans[num] == p && ans[num + 1] == q){
				FOR(i, 1, num + 1){
					if(ans[i]) cout << "W";
					else cout << "S";
				}
				cout << '\n';
				return 0;
			}
		}
	}
	cout << -1 << endl;
}
