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




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    while(1){
        
        int a;
        cin >> a;
        
        if(a == 0)
            break;
        
        if(a % n == 0)
            cout << a << " is a multiple of " << n << ".\n";
        else
            cout << a << " is NOT a multiple of " << n << ".\n";
    }
    
    
    
    

    return 0;

}
