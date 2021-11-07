
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
    int num = 0;
    
    while(n>0){
        if(n % 5 == 0){
            cout << n/5 + num;
            return 0;
        }       // 그러다가 5로 나누어 지면, 거기다가 이제까지 해준 숫자를 더해준다.
        num++;
        n -= 2;
        // 5로 안나누어지면, 횟수를 늘리고, 2를 빼준다.
    }
    
    cout << num;
    
    
    return 0;
}

