
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

bool sosu(int n){
    
    if(n == 0 || n == 1)
        return false;
    
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0)
            return false;
    }
    return true;
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    cout << sosu(n);
    
    
    
    return 0;
}


