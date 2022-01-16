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

    
        
    while(cin >> n){
        
        int num = 0;
        for(int i=1;i<=n;i++){
            num = num * 10 + 1;     // num을 1에서 11, 11에서 111 와 같은 식으로 늘려줌
            num %= n;
            
            
            if(num == 0){
                cout << i << '\n';
                break;
                
            }
        }
    }
    
    // x mod n = (x mod n) mod n 을 이용한다.
    // 숫자가 매우 커질 때 이를 이용하여 줄일 수가 있다.

    return 0;

}


