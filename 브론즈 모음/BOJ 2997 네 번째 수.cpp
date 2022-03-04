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

    
    vector<int>v;
    for(int i=0;i<3;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    
    int d1 = v[1] - v[0];
    int d2 = v[2] - v[1];
    
    if(d1 == d2)
        cout << v[2] + d1 << '\n';
    else if(d1 > d2)
        cout << v[0] + d2 << '\n';
    else
        cout << v[1] + d1 << '\n';
    
    
    
    
    return 0;

}
