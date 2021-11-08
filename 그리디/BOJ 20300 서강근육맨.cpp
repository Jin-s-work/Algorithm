
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <map>
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;

ll arr[10001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    ll ans = 0;
    
    if(n % 2 == 1){
        ans = arr[n-1];
        n--;
        // n이 홀수일 경우 가장 큰 것을 그냥 마지막으로 놓으면 된다.
        // 홀수는 즉, 맨 마지막을 ans로 놔주고, 줄여서 짝수로 만들어서 해주는 것
    }
    
    // 짝수일 경우 ans는 0부터 시작
    // 원래 홀수 였을 경우, ans가 원래의 arr[n-1]로 되어있고, 이걸 빼준 상태에서 짝수로 더해본다.
    
    for(int i=0;i<n/2;i++){
        ll sum = arr[i] + arr[n - 1 - i];
        // 중간까지 하려면 i가 n/2까지 여야 줄어들면서 해줌
        // 줄어들면서 Min과 ans를 비교하여 Min 중 최대를 넣어준다.
        
        if(sum > ans)       // 새로 계산한 sum이 ans보다 클 경우,
            ans = sum;      // 새로 갱신해준다.
        // 즉 최대의 최소화 이기 때문
    }
    // 양끝으로 해서 더해야 최대한 작게 할 수 있긴 함
    
    cout << ans;
    
    return 0;
}

// 최대의 최소화 문제

