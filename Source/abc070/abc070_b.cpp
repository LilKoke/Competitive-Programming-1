#include <iostream>

using namespace std;

int main(){
    int a, b, c, d, i;
    cin >> a >> b >> c >> d;
    int answer = 0;
    for(i = 0; i < 101; i++){
        if(a <= i && i <= b && c <= i && i <= d){
            answer++;
        }
    }
    if(answer){
        answer--;
    }
    cout << answer << endl;
}
