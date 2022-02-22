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

    
    cin >> n >> m;
    
    for(int i=m;i<=100;i++){
        int num = n - i*(i+1)/2;
        
        if(num % i == 0){       // num이 i로 나누어 떨어지는 시점부터
            int add = (num / i) + 1;
            // add는 몫에다가 1더해준 값
            
            if(add >= 0){
                for(int k=0;k<i;k++){
                    cout << k + add << " ";
                    // x + 1 부터 x + m 까지 출력하는 것이다.
                }
                cout << '\n';
                return 0;
            }
        }
    }
    
    cout << "-1" << '\n';
    
    
    return 0;

}
