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

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s;
    string templa = "##";
    REP(i, m) templa += '#';
    s.push_back(templa);
    vector<P> place;
    REP(i, n){
        string tmp;
        cin >> tmp;
        REP(j, m){
            if(tmp[j] == '#'){
                place.push_back(P(i + 1, j + 1));
            }
        }
        s.push_back('#' + tmp + '#');
        place.push_back(P(i + 1, 0));
        place.push_back(P(i + 1, m + 1));
    }
    REP(i, m){
        place.push_back(P(0, 1 + i));
        place.push_back(P(n + 1, 1 + i));
    }
    s.push_back(templa);
    ll pre[4][2010][2010];
    REP(i, place.size()){
        P now = place[i];
        int sx = now.first, sy = now.second;
        REP(k, 4){
            int nx = sx; int ny = sy;
            ll ans = -1;
            while(true){
                if(k == 0){
                    ny--;
                }else if(k == 1){
                    ny++;
                }else if(k == 2){
                    nx--;
                }else{
                    nx++;
                }
                ans++;
                if(nx < 0 || ny < 0 || nx > n || ny > m || s[nx][ny] == '#') break;
                else pre[k][nx][ny] = ans;
            }
        }
    }
    ll ans = 0;
    FOR(i, 1, n + 1){
        FOR(j, 1, m + 1){
            if(s[i][j] == '#') continue;
            else ans += (pre[0][i][j] + pre[1][i][j]) * (pre[2][i][j] + pre[3][i][j]);
        }
    }
    cout << ans << endl;
}
