#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define SORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
using ll = long long;
using namespace std;

#define MAX 200010

ll a[MAX], l, r, x, n, q, s, t, before, temp[MAX];

int main(){
	cin >> n >> q >> s >> t;
	t *= -1;
	cin >> before;
	a[0] = 0;
	temp[0] = 0;
	FOR(i, 1, n + 1){
		cin >> a[i];
		a[i] -= before;
		before = a[i] + before;
		if(a[i] >= 0){
			temp[0] -= a[i] * s;
		}else{
			temp[0] += a[i] * t;
		}
	}
	temp[n + 1] = 0;
	REP(i, q){
		cin >> l >> r >> x;
		temp[i + 1] = temp[i];
		if(a[l] < 0){
			temp[i + 1] -= a[l] * t;
		}else{
			temp[i + 1] += a[l] * s;
		}
		if(a[r + 1] < 0 && r != n){
			temp[i + 1] -= a[r + 1] * t;
		}else if(r != n){
			temp[i + 1] += a[r + 1] * s;
		}
		a[l] += x;
		a[r + 1] -= x;
		if(a[l] >= 0){
			temp[i + 1] -= a[l] * s;
		}else{
			temp[i + 1] += a[l] * t;
		}
		if(a[r + 1] >= 0 && r != n){
			temp[i + 1] -= a[r + 1] * s;
		}else if(r != n){
			temp[i + 1] += a[r + 1] * t;
		}
	}
	FOR(i, 1, q + 1){
		cout << temp[i] << endl;
	}
}
