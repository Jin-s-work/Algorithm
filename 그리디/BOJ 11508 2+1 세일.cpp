
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

int arr[100001];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    sort(arr + 1, arr + n + 1, greater<int>());
    
    ll sum = 0;
    for(int i=1;i<=n;i++){
        if(i % 3 != 0)
            sum += arr[i];
        
    }
    
    cout << sum;
    
    return 0;
}

// 머야 진짜 대충 풀었는데 맞음...


