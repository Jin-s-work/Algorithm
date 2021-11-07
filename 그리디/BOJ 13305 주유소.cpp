
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


ll dist[100001];
ll price[100001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    ll Max = 1000000000;
    ll sum = 0;
    
    for(int i=0;i<n-1;i++){
        cin >> dist[i];
    }
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    
    for(int i=0;i<=n;i++){
        if(Max > price[i]){
            Max = price[i];
        }
        // 가격이 만약에 최소값일 경우, 그에 대해서 곱해서 더해준다.
        // 아닐경우도 해당하는 거리에 따라 곱하는데, 앞에서 충전하나 지금 충전하나 시간이 주어지지 않으므로
        // 위와 같이 해도 된다.
        
        sum += Max * dist[i];
    }
    
    cout << sum;
    
    return 0;
}

