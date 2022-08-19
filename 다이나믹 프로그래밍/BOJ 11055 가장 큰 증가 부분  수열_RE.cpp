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
        dp[i] = arr[i];
        // dp를 arr의 값으로 처음 시작해주고, 전의 문제처럼 1로 하거나 이렇게 더하지 않고
        // 각각의 arr 값들을 더해준다.
        
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
            // 여기서는 뒤에 있는 arr[i]가 더 클 경우 dp[j]에서 arr[i]가 더해졌을 때의 크기를 비교해준다.
        }
        
        ans = max(ans, dp[i]);
        
        
    }
    
    cout << ans;
    
    
    return 0;
    
}
