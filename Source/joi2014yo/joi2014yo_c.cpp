#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

int main(){
    int w, h, n, bx = 1, by = 1, nx, ny, answer = 0;
    cin >> w >> h >> n >> bx >> by;
    REP(i, n - 1){
        cin >> nx >> ny;
        if((nx -  bx) * (ny - by) > 0){
            if(abs(nx - bx) >= abs(ny - by)){
                answer += abs(nx - bx);
            }else{
                answer += abs(ny - by);
            }
        }else{
            answer += abs(nx - bx) + abs(ny - by);
        }
        bx = nx;
        by = ny;
    }
    cout << answer << endl;
}
