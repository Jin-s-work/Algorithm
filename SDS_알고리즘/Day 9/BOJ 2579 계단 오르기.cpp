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

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int dp[301];
int arr[301];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    dp[1] = max(arr[0] + arr[1], arr[1]);
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
    
    if(n > 2){
        for(int i=3;i<n;i++){
            dp[i] = arr[i] + max(dp[i-3] + arr[i-1], dp[i-2]);
        }   // 그 앞 중에서 i-3과 계단 i-1을 더하거나 dp[i-2]를 해서
    }       // 거기다가 현재인 arr[i]를 더해주는 경우
    
    cout << dp[n-1];
    
    

    return 0;

}

