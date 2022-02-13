

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
ll ans = 3000000003;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    ll a, b, c;
    
    
    int left = 0;
    int right = n - 1;
    // 양 끝을 두 포인터로 잡고
    
    while(left < right){
        ll num = arr[left] + arr[right];
        // 더 한 수를 num
        if(abs(num) < ans){
            // 절대값으로 해서 ans 보다 작을 경우
            ans = abs(num);
            b = arr[left];
            c = arr[right];
            
            // 그 값을 갱신하고 저장해준다.
            // 0에 제일 가까워야 하므로 절대값으로 해서 제일 작은 것을 구해야 한다.
        }
        
        if(num < 0)
            left++;
        else
            right--;
    }
    
    
    
    
    cout << b << " " << c;
    
    
    
    return 0;

}


