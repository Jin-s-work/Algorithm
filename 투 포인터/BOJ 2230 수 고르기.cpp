

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

ll arr[100001];
ll ans = 9876543210;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int left = 0;
    int right = 1;
    
    while(left < n){
        if(arr[right] - arr[left] < m){
            right++;
            continue;
        }
        // 차이가 m보다 작은 경우는 right을 올려주고 넘어간다.
        
        if(arr[right] - arr[left] == m){
            cout << m << '\n';
            return 0;
        }
        // m과 같은 경우는 m을 출력해준다.
        // 차이가 제일 작은 것을 찾아야 하므로, m일 경우이기에 그냥 여기서 바로 출력해주면 된다.
        
        ans = min(ans, arr[right] - arr[left]);
        left++;
        
        // 둘 다 아닐 경우 최소값과 차이를 비교하여 작은 것을 넣어주고
        // left를 올리면서 비교한다.
        
    }
    
    cout << ans << '\n';
    
    
    return 0;

}


