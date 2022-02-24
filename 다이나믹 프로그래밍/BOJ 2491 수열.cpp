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
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    
    int ans = 1;
    int a = 1;
    int b = 1;
    
    for(int i=1;i<n;i++){
        if(arr[i] <= arr[i+1])
            a++;
        else
            a = 1;
        if(arr[i] >= arr[i+1])
            b++;
        else
            b = 1;
        
        int res = max(a, b);
        ans = max(res, ans);
    }
    
    cout << ans;
    
    return 0;

}
