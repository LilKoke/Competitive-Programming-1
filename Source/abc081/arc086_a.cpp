#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k,b[200010]={};
    // 配列の初期化
    for(int i=0;i<200010;i++){
        b[i] = 0;
    }    
    cin >> n >> k;
    //入力 + 初めて登場(?)した数があれば種類(cnt)をインクリメント
    int tmp;
    int cnt = 0;
    for(int i=0;i<n;i++){
		cin >> tmp;
        if(b[tmp] == 0){
            cnt++;
        }
        b[tmp]++;
	}
    // ボールの数が少ない順にソート
	sort(b,b+200010);
    // もともとK種類以下なら0を出力
	if(cnt<=k){
		cout << 0 << endl;
		return 0;
	}
	int sum=0;
    // cntがKになるまでb[i]の値をsumに足していく
    int j = 0;
	while(cnt > k){
        //b[j] == 0の時ボールの種類(=cnt)は減らない
        if(b[j] != 0){
            sum += b[j];
            cnt--;
        }
        j++;
    }
	cout << sum << endl;
	return 0;
}

