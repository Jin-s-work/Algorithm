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

int arr[101];
ll dp[201][201] = {0};

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    
    dp[1][arr[1]] = 1;
    // dp[i][j] 는 0-i 사이에서 +나 -를 넣어서 j를 만드는 경우의 수이다.
    // i는 현재 위치이고, j는 결과값
    
    for(int i=2;i<n;i++){
        for(int j=0;j<=20;j++){
            if(dp[i-1][j]){     // 0이 아닐 경우 즉 이루어지는 경우에 대해서 이어가기 (나름 중요한 포인트)
                // j는 현재의 값이다. 즉 현재의 값에 arr[i]를 더했을 때 결과를 보며 비교하는 것
                if(j + arr[i] <= 20)  // j에 arr[i]를 더했을 때 20이하일 경우에 더하는 경우의 수를 더함
                    dp[i][j + arr[i]] += dp[i-1][j];
                
                if(j + arr[i] >= 0)   // j에 arr[i]를 더했을 때 0이상인 경우에 빼는 경우의 수를 더함
                    dp[i][j - arr[i]] += dp[i-1][j];
            }
        }
    }
    
    cout << dp[n-1][arr[n]];
    // 마지막에서 두번째 까지 이므로 n-1의 위치
    // 결과값도 arr[n]으로 끝나게
    
    
    return 0;
    
}
