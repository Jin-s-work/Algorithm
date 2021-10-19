
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
int h;

vector<int>v;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    cin >> m;
    ll num = 0;
    
    while(m--){
        int c;
        cin >> c;
        num += c * pow(a, m);
    }
    
    
    while(num){
        v.push_back(num % b);
        num /= b;
    }
    
    // 50
    
    for(int i=v.size()-1;i>=0;i--){
        cout << v[i] << " ";
    }
    cout << '\n';
    
    
    return 0;
}


