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


int arr[100001];
int dp[100001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    int sum = dp[0];
    // 처음의 sum에는 dp에 넣어줌
    
    for(int i=1;i<n;i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        // dp[i]에는 원래의 arr[i]와 그 전의 dp[i-1]와의 합과 비교
        // arr[i]와 비교하는 이유는 그 합이 줄어들지라도 arr[i]자체보다 크다면 계속 끌고가는 것이 더 높기때문이다
        
        sum = max(dp[i], sum);
        // dp[i]와 sum 중 비교
    }
    
    cout << sum;
    
    // 마이너스가 나와도 전과 비교해 줄 수 있게 템포러리한 배열인 dp가 필요한 것이다.
    // 두개의 배열을 사용해야 한다.
    
    return 0;

}
