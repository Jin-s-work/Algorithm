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


char arr[1025][1025];
int dp[1025][1025];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] - '0';
        }
    }
    
    int Max = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j] == 1){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                // 최소값을 하나 해서 거기에 1더 해줘야한다. (제일 최소인 것을 사용해야 한다.)
                
                if(dp[i][j] > Max)     // dp가 num보다 클 경우
                    Max = dp[i][j];    // 즉 최대값을 구하는 것
                                       // 돌면서
            }
        }
    }
    
    
    cout << Max * Max;
    
    
    

    return 0;

}

