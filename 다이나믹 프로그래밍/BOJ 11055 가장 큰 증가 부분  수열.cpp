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

// control i처
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
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int sum = 0;
    for(int i=0;i<n;i++){
        dp[i] = arr[i];
        
        for(int j=0;j<i;j++){       // ** 이게 가장 중요한 포인트 **
            if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
            // arr 또한 증가하는 수열이어야 하므로 더 큰 것도 만족해야 하고, dp에 더해준 값도 더 커야한다.
            // 그럴 경우에 dp[i]에 dp[j]+ arr[i]와 비교해서 넣어주기
            // 점프가 되므로 j의 경우에는 i보다 작은 모든 값에 대해서 가능하다.
            // 그러므로, 가능한 모든 j와 비교해 주는 것이다.
        }
        
        sum = max(sum, dp[i]);
    }
    
    cout << sum;
    
    return 0;

}
