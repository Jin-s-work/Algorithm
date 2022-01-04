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
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
ll n,m,k;
int l,r,t;
int h;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    cin >> n >> m;
    
    vector<int>v;
    ll Max = 0;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
        if(a >= Max)
            Max = a;
        
    }
    
    ll ans = 0;
    ll left= 1;
    ll right = Max;
    ll sum = 0;
    ll mid = 0;
    
    
    while(left <= right){
        
        sum = 0;
        mid = (left + right) / 2;
        
        for(auto k : v){
            if(k - mid > 0)
                sum += (k - mid);
        }
        
        if(sum < m){        // 아직 m보다 작은 경우
            right = mid - 1;
        }
        // 왼쪽으로 가기 가운데 기준으로 right를 간다.
        // 즉 무조건 작아지기에 뺄셈의 합을 구하므로 값이 커지므로 이러한 식으로 해야한다.
        else{
            ans = max(ans, mid);
            left = mid + 1;
        }
        // m보다 크거나 같을 경우에는 mid의 최대를 ans에 넣어주고,
        // 가운데를 기준으로 오른쪽으로 간다.
        // 오른쪽으로 가면 mid가 조금 작아지므로 줄여볼수가 있다.
        // 그 중에서 최대 구하기
        
        // 더 줄이는 것과 덜 줄이는 것의 차이
    }
    
    
    cout << ans;
    
    return 0;

}


// 이진 탐색으로 푸는 문제..

// 사실 mid를 사용해서 왜 하는 것인지 정확하게 이해는 가지가 않는다.
// 모든 값들의 중간값을 사용하는게 가장 효율적인 거 같기는 한데..

// 하지만 엄청 나게 큰 값은 항상 고려해 줘야하는 대상이고, 엄청 작은 값은 고려 안해도 되기에
// 이분탐색을 통해서 계속 범위를 줄여나가는게 맞는 거 같긴하다.
// 기준점을 구하는 것이기에 ( 90% 정도는 이해가 갔지만, 다른 문제도 위를 활용하여 풀 수 있을까?)
