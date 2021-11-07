
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



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<pair<int, int>>v;
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    
    sort(v.begin(), v.end());
    
    int sum = 0;
    for(int i=0;i<n;i++){
        
        sum += v[i].first * (n-i);
        // 귀찮으니까 그냥 이렇게 더하기
    }

    cout << sum;
    
    
    return 0;
}


// 1 12 123 1233 12334
// 1 3 6 9 13
// 32
