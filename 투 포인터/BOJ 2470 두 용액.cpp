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


vector<ll>v;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    
    for(int i=0;i<n;i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    // 먼저 정렬하고, 양끝에서 찾으면 되는걸.. 당연한걸 생각못함
    // 프로그래머스하다가 백준해서 갈팡질팡하는 느낌..
    
    int num = 0;
    int left = 0;
    int right = v.size() - 1;
    
    ll ans1, ans2;
    
    ll Min = 2000000000;
    while(left < right){
        int sum = v[left] + v[right];
        
        if(Min > abs(sum)){
            Min = abs(sum);
            // abs한 sum이 더 작을 경우 갱신한다.
            // Min은 제일 0에 가까운 합을 나타냄
            
            ans1 = v[left];
            ans2 = v[right];
            
            if(sum == 0)
                break;
            // 0이 나오면 아예 끝냄
            
        }
        
        if(sum < 0)
            left++;
        else
            right--;
        
        // 여기서 이게 상관이 없는게 이미 위에 더 작은것을 저장해 노아서 left++를 해도 더 커질 경우에도
        // 위에서 새로 갱신이 안되어서 상관없다... 따라서 이러한 left++ right-- 는 뒤에 해주는 것이 좋다.
        
        // sum이 0보다 작으면 더 크게해도 되니까 left를 증가시킨다.
        // 아닐 경우는 더 작게 하면 되니까 right를 줄인다.
    }
    
    cout << ans1 << " " << ans2;
    

    return 0;

}
