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
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int arr[1001];
int dp[1001];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    int ans = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<n;i++){
        dp[i] = 1;
        // 처음에는 모두 1이 기본값이다.
        
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
            // j를 i 전까지 하여 i와 비교하며
            // 만약 그 다음 i에 관하여 더 크다면, dp[j] + 1과 dp[i]를 비교하여 큰 값을 넣어주기
            
            // 즉 j에서 이어주면서 그 값에 대한 값을 1씩 더해서 이어주기
        }
        
        ans = max(ans, dp[i]);
        
    }
    
    cout << ans;
    
    
    return 0;
    
}
