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
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;

int gcd(int a, int b){
    
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int a, b;
    cin >> a >> b;
    
    int c, d;
    cin >> c >> d;
    
    int x = a * d + b * c;
    int y = b * d;
    
    int g = gcd(x, y);
    x = x / g;
    y = y / g;
    // 생각해보니 각각 gcd(x, y)로 나누어주면 위에서 x가 바뀌어서 안댐.. 바보
    
    
    cout << x << " " << y;
    

    return 0;

}
















//
//
//
//
//cin >> n >> k;
//
//priority_queue<int>pq;
//vector<int>v;
//
//for(int i=0;i<n;i++){
//    int a;
//    cin >> a;
//    v.push_back(a);
//}
