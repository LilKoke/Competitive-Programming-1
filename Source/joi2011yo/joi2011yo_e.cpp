#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

typedef pair <int,int> P;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(){
  int h, w, n;
  char mas[1010][1010];
  int pointx[10], pointy[10];
  int cost[1010][1010];
  cin >> h >> w >> n;
  REP(i, h){
    REP(j, w){
      cin >> mas[i][j];
      int tmp = (int)(mas[i][j] - '0');
      if(tmp > 0 && tmp <= 9){
        pointy[tmp] = i;
        pointx[tmp] = j;
      }
      if(mas[i][j] == 'S'){
        pointy[0] = i;
        pointx[0] = j;
      }
    }
  }
  int ans = 0;
  queue<P> que;
  REP(i, n){
    memset(cost, -1, sizeof(cost));
    que.push(P(pointy[i], pointx[i]));
    cost[pointy[i]][pointx[i]] = 0;
    while(!que.empty()){
      auto p = que.front(); que.pop();
      int y = p.first; int x = p.second;
      REP(j, 4){
        int ny = y + dy[j]; int nx = x + dx[j];
        if(ny < 0 || nx < 0 || ny >= h || nx >= w || mas[ny][nx] == 'X') continue;
        if(cost[ny][nx] == -1){
          cost[ny][nx] = cost[y][x] + 1;
          que.push(P(ny, nx));
        }
      }
    }
    ans += cost[pointy[i + 1]][pointx[i + 1]];
  }
  cout << ans << endl;
}
