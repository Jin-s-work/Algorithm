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


int arr[100001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int left = 0;
    int right = n - 1;
    int ans = 0;
    
    while(left < right){        // left가 작은 동안
        ans = max(ans, (right - left - 1) * min(arr[left], arr[right]));
        // ans와 구하는 값을 이용하여 구함
        
        if(arr[left] < arr[right])
            left++;
        // 오른쪽의 값이 더 크면 왼쪽을 옮김
        else
            right--;
        // 왼쪽의 값이 더 크면 오른쪽을 줄임
        
        // 즉 양 끝 중 더 작은 값을 찾아 그 값을 이동하여 min을 크게 만든다.
    }
    
    cout << ans;
    
    
    return 0;

}


