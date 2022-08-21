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

int dp[100001];
int arr[100001];

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    
    dp[0] = arr[0];
    int sum = dp[0];
    
    for(int i=1;i<n;i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        
        sum = max(sum, dp[i]);
    }
    
    // 한개를 건너뛰고 해서 검사하는 방법은 뒤의 수가 더 클 수 있으니 안 좋을 것 같다.
    // -> 이 논리는 틀린게 맞았는데
    
    // dp[i-1] + arr[i]과 arr[i]를 비교하는 과정에서는 이제까지의 합에 arr[i]를 더한 것과 arr[i]를
    // 비교하였을때, arr[i]를 더해 합이 줄더라도 dp[i-1] + arr[i]가 arr[i]보다 크면 계속 끌고 가도
    // 더 큰 값이기에 된다.
    // -> 그니까 그냥 새로이 다시 시작하는 것과 이어가는 것을 비교해서 한다고 했으니 원래 생각한 방법이 맞기는 하네..
    // 살짝 더 단순하게 생각하긴 햇는데 맞았던 것
    
    // 처음에 생각 없이 이런 식으로 계속 하였다면 이러한 포인트를 못 찾았을 것
    
    cout << sum;
    
    
    return 0;
    
}
