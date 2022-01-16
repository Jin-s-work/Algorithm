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


int arr[501][501];
int dp[501][501];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    cin >> arr[1][1];
    dp[1][1] = arr[1][1];
    
    for(int i=2;i<=n;i++){          // 처음에 1을 그래서 빼놓고 함
        for(int j=1;j<=i;j++){      // j는 i개 만큼 (2개, 3개, 4개,,,,)
            cin >> arr[i][j];
            dp[i][j] += arr[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    
    for(int i=1;i<=n;i++){
        dp[n][0] = max(dp[n][0], dp[n][i]);
    }
    
    cout << dp[n][0] << '\n';
    
    

    return 0;

}
