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


//int fib(int n){
//
//    if(n == 0)
//        return 0;
//    else if(n == 1)
//        return 1;
//    else if(n == 2)
//        return 1;
//
//    return fib(n-2) + fib(n-1);
//}

// 위와 같은 함수를 쓰면 시간이 초과 됨 오래 걸림..


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    ll fib[101];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    
    for(int i=0;i<n-1;i++){
        fib[i+2] = fib[i] + fib[i+1];
    }
    
    cout << fib[n];
    
    
    
    return 0;

}

