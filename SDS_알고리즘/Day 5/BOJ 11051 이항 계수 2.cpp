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
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}


ll c[1001][1001];
// nCk + nC(k+1) = (n+1)C(k+1)
// 파스칼의 법칙을 사용해야 한다.

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> k;
    
    c[0][0] = c[1][0] = c[1][1] = 1;
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            if((i == j) || (j == 0))
                c[i][j] = 1;
            // i와 j와 같으면 무조건 1이고, j가 0이어도 무조건 1
            else if((j == 1) || (j == i-1))
                c[i][j] = i;
            // j가 1이면 그냥 i가 나오고, j도 i와 1차이 나면 그냥 i 그 자체
            else
                c[i][j] = ((c[i-1][j]) + (c[i-1][j-1])) % mod;
            // 다 아닐 경우 파스칼의 법칙을 사용하여 나눈다.
        }
        // Combination의 성질
    }
    
    cout << c[n][k];

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

//
//
