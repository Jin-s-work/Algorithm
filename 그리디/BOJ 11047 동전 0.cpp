
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
ll n,m,k;
int l,r,t;
int h, w;


vector<ll>v;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }
    
    ll num = 0;
    ll idx = n-1;
    while(idx >= 0){
        // 0일 때도 되야 한다.
        // 범위를 주의..!
        
        if(k - v[idx] >= 0){
            k = k - v[idx];
            num++;
        }
        else
            idx--;
        
    }
    
    cout << num;
    
    return 0;
}

// 그냥 끝에서부터 빼주면서 음수가 아닐 경우 계속 빼주면서 num을 증가시키고,
// 끝나면 인덱스를 줄여주면서 개수를 구했다.

// 맞네.. 그리디 많이 푸니까 먼가 익숙해짐
