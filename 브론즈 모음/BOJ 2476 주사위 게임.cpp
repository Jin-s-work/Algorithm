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

    
    cin >> n;
    
    int tmp = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        tmp = 0;
        if(a == b && b == c && c == a){
            tmp = 10000 + a*1000;
            if(tmp > ans)
                ans = tmp;
        }
        else if(a == b && b != c){
            tmp = 1000 + a*100;
            if(tmp > ans)
                ans = tmp;
        }
        else if(a == c && b != c){
            tmp = 1000 + a*100;
            if(tmp > ans)
                ans = tmp;
        }
        else if(c == b && a != c){
            tmp = 1000 + c*100;
            if(tmp > ans)
                ans = tmp;
        }
        else if(a != b && b != c && c != a){
            int Max = max(max(a, b), c);
            tmp = 100 * Max;
            
            if(tmp > ans)
                ans = tmp;
        }
        
    }
    
    cout << ans;
    
    
    return 0;

}
