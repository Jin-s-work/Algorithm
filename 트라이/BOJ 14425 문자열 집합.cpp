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





int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    map<string, bool> mp;
    cin >> n >> m;
    int ans = 0;
    
    for(int i=0;i<n;i++){
        string st;
        cin >> st;
        
        mp[st] = true;
    }
    for(int i=0;i<m;i++){
        string st;
        cin >> st;
        
        if(mp[st])
            ans++;
    }
    
    cout << ans;
    
    
    return 0;

}
