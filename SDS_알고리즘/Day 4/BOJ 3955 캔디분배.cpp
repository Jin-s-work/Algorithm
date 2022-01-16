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

int modu(int a, int m){
    return ((a % m) + m) % m;
    // mod 해준 것
}

int exEuclid(int a, int b, int &x, int &y){
    int xx = y = 0;
    int yy = x = 1;
    
    // b가 0이 될때까지 반복한다.
    while(b){
        int q = a / b;
        int t = b;
        b = a % b;
        a = t;
        
        t = xx;
        xx = x - q * xx;
        x = t;
        
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    
    // gcd(a, b)를 리턴한다.
    return a;
}

int Inverse(int b, int m){
    int x, y;
    int d = exEuclid(b, m, x, y);
    // 역원은 확장유클리드를 통해 d를 구하고
    
    if(d != 1)
        return -1;
    // 1이 아니면 -1을 리턴 (안되면 발견하기 위하여)
    
    // b*x + m*y == 1 이므로 (mod m)를 하여 b*x == 1 (mod m)인 x를 구한다.
    
    return modu(x, m);
    // x,m의 mod를 구해준다.
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> t;
    
    while(t--){
        
        int a, b;
        cin >> a >> b;
        
        // b*y = a*x + 1
        // b * y = 1(mod a)
        ll ans = Inverse(b, a);
        // 역원을 구하는 문제이므로 구해서 ans에 넣어준다.
        
        if(ans == -1){
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }       // -1이면 안댐
        
        while(b * ans <= a)
            ans += a;
        // b*ans가 a이하일 동안 ans에 a를 더해준다.
        // 즉 ans를 a씩 더해주면서 크게 해주는 것
        
        if(ans > 1000000000)
            cout << "IMPOSSIBLE" << '\n';
        // 1e9를 넘으면 불가능이고
        else
            cout << ans << '\n';
        // 아니면 그냥 출력한다.
    }
    
    // by = ax + 1
    // 5y = 10x + 1
    // 7y = 10x + 1
    // 3     2       따라서 3
    
    

    return 0;

}


// 확장 유클리드 호제법... 잘 모르겟는데 쓸 일이 있을런지..









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
