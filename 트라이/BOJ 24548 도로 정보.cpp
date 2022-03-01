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

    
    int n; cin >> n;
    string s; cin >> s;
    map<tuple<int, int, int, int>, ll> mp;
    ll ans = 0;
    int t = 0, g = 0, f = 0, p = 0;
    mp[make_tuple(0, 0, 0, 0)] ++;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') t++;
        else if (s[i] == 'G') g++;
        else if (s[i] == 'F') f++;
        else p++;
        
        ans += mp[make_tuple(t % 3, g % 3, f % 3, p % 3)];
        mp[make_tuple(t % 3, g % 3, f % 3, p % 3)]++;
    }
    cout << ans;
    
    
    return 0;

}
