#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int A[20];
int n,s,cnt;

int dfs(int num, int sum){
    if(num == n)
        return 0;
    if(sum + A[num] == s)
        cnt++;          // 같으면 경우의 수 증가
    dfs(num+1, sum);    // 받은 숫자를 더하지 않을 경우
    dfs(num+1, sum+A[num]);     // 받은 숫자를 더할 경우
    return 0;
}


int main(){
    
    
    cin >> n >> s;
    
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    cnt = 0;
    dfs(0,0);   // 0,0부터 시작하여 num+1과 sum+A[num]으로 증가
    
    cout << cnt << '\n';    // 경우의 수 출력
    
    return 0;
}
