#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

#define INF 100000000

int cost[101][101];
int d[101];
bool used[101];
int V;

void dijkstra(int s){
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;
    while(1){
        int v = -1;
        REP(u, V){
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;
        REP(u, V){
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
}

int main(){
    int n, k, r, a, b, c, di, e;
    cin >> n >> k;
  	REP(i, 101){
    	REP(j, 101){
        	cost[i][j] = INF;
        }
    }
    V = n;
    REP(i, k){
        cin >> r;
        if(r){
            cin >> c >> di >> e;
            c--; di--;
            if(cost[c][di] > e){
                cost[c][di] = cost[di][c] = e;
            }
        }else{
            cin >> a >> b;
            a--; b--;
            dijkstra(a);
            if(d[b] < INF){
                cout << d[b] << endl;
            }else{
                cout << -1 << endl;
            }
        }
    }
}
