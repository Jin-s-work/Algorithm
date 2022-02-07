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

int arr[15001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    // 1 2 3 4 5 7
    
    ll left = 0;
    ll right = n-1;
    ll ans = 0;
    // left 와 right를 양끝으로 설정하여주고
    
    while(left < right){
        if(arr[left] + arr[right] == m){
            ans++;
            left++;
            right--;
        }
        // 더한 것이 m일 경우 ans를 증가시켜 경우의 수를 세주고,
        // 이미 사용하였으므로, 양끝을 하나씩 당긴다.
        else if(arr[left] + arr[right] < m)
            left++;
        // 더한 합이 m보다 작을 경우 더 크게 해줘야 하므로, left를 늘려준다.
        else if(arr[left] + arr[right] > m)
            right--;
        // 더한 합이 m보다 클 경우 줄여야 하므로, right를 줄여준다.
        
    }
    
    cout << ans;
    
    
    return 0;

}


// 가장 기본적인 이분탐색 문제
