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


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v1.push_back(a);
    }
    for(int i=0;i<m;i++){
        int b;
        cin >> b;
        v1.push_back(b);
    }
    
    sort(v1.begin(), v1.end());
    
//    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    
    for(auto k : v1)
        cout << k << " ";


    return 0;

}

// 괜히 유니크 썼다가 틀림 안써도 된다.
