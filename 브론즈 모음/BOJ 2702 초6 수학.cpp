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


int gcd(int a, int b){
    
    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << " " << gcd(a, b) << '\n';
    }
    
    return 0;

}
