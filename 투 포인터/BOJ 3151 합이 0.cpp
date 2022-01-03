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
int n,m,k;
int l,r,t;
int h;

ll Max = 20000;
ll arr[40001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    vector<int>v(n);
    
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += arr[Max - v[i]];
        
        for(int j=0;j<i;j++)
            arr[Max + v[i] + v[j]]++;
    }
    
    cout << ans;
    

    return 0;

}


// 세개의 포인터..?
// 그나마 참조한 것중에 제일 간단한 걸루...
// 솔직히 정확히는 이해가 안간다...

