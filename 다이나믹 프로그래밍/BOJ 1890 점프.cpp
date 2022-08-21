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

ll dp[101][101];        // dp의 경우 합이 커져서 2^63 - 1 까지 가므로 롱롱
int arr[101][101];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    dp[0][0] = 1;
//    int cnt = arr[0][0];
//    dp[cnt][0] = 1;
//    dp[0][cnt] = 1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(dp[i][j] == 0 || (i == n-1 && j == n-1))
                continue;
            // 생각하였던 식은 다 맞는데 여기서 n-1이고 n-1일 때
            // 그냥 지나가는 부분을 간과하여 값이 나오지 않았다
            
            // dp[i][j] == 0 의 경우에도 만약 0이 나올 경우 본인의 값을 계속 더해주기에
            // 지나가야한다.
            
            // 예시의 dp[3][3] == 0 이어서 계속 반복하였던 것 같다.
            // 둘이 똑같은 조건이다.
            
            if(i + arr[i][j] < n)
                dp[i + arr[i][j]][j] += dp[i][j];
            
            if(j + arr[i][j] < n)
                dp[i][j + arr[i][j]] += dp[i][j];
            
            // 움직였을 때의 dp의 그 전의 dp와 더해서 중첩시켜준다.
        }
    }

    cout << dp[n-1][n-1];
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << '\n';
//    }
    
    
    return 0;
    
}
