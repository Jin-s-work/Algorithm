#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <functional>
#include <map>
#include <unordered_map>
#include <set>
#include <sstream>

// control i
#define MAX 987654321
#define mod 1000000000
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int arr[100001];
int dp[100001][2];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    // dp[0][1]의 경우도 사실 없다고 할 수 있지만 초기화 해놓지 않으면 dp[i-1][1]을 사용하는 과정에서 에러날듯
    // 하나를 삭제할 경우를 [1], 안 삭제한 경우를 [0]
    int sum = arr[0];
    // 처음의 sum도 arr[0]으로 해준다.
    // 왜냐하면, 밑에서 1-(n-1)까지를 탐색하기에 초기값을 arr[0]로 해주기
    // i-1을 쓰기 위해서 1-(n-1)로 하는 것
    
    for(int i=1;i<n;i++){
        
        // 삭제를 안할 경우
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
        // 전의 dp에 더해주던가 아니면 arr 그 자체로 새로운 시작
        
        // 삭제를 한 경우
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
        // 0을 한것은 그냥 넘어가서 [i][1]이 되는 것과
        // 원래 삭제를 한번 해서 그 다음으로 넘어가는 것을 비교
        
        sum = max(sum, max(dp[i][0], dp[i][1]));
    }
    
    cout << sum;
    
    
    return 0;
    
}
