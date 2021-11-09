
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
int n,k;
int l,r,t;
int h, w;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    ll a, b;
    cin >> a >> b;
    
    ll num = 0;
    while(1){
        if(b % 10 == 1){
            b /= 10;
            num++;
        }
        else if(b % 2 == 0){
            b /= 2;
            num++;
        }
        else{
            cout << "-1";
            break;
        }
        // 1로도 안끝나고, 2로도 안나누어지면 바로 그냥 끝내주어야 시간 초과가 안뜬다.
        
        if(a == b){
            cout << num + 1;
            break;
        }
        if(a > b){
            cout << "-1";
            break;
        }
        
        
    }
    
    
    return 0;
}


// 뒤에서 거꾸로 생각하는 부분은 바로 하였으나,
// 1로도 안끝나고, 2로 나누어지지 않을 경우에 바로 안끝내면 계속 돌기에 시간 초과가 날것..
// 왜냐하면 조건을 만족하지 않으면, b가 작아질 수 없기 때문이다.
