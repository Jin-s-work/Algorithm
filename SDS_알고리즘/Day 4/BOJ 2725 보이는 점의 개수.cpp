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

int dp[1001];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 3;
    // 처음에는 (1,1),(0,1),(1,0)
    // 즉 x축, y축, (1,1)인 부분을 처음부터 3개로 하고 시작
    
    for(int i=2;i<=1000;i++){
        int num = 0;
        // num은 i가 바뀔때마다 갱신해야 한다.
        for(int j=1;j<i;j++){
            if(gcd(i, j) == 1)
                num++;
        }
        // 작으니까 하나씩 해봐도 댐 ( 저번 풀이랑 똑같이 풀었다..)
        
        dp[i] = dp[i-1] + num * 2;
        // 양쪽에 있을 경우 2개 이므로 2배 곱해서 넣어준다.
        // 누적 합으로.. 더해 주어야 한다.
        // 그 부분만 하는 것이 아니기에
        // 합의 i일 때의 값들을 dp에 저장해주는 것
    }
    
    cin >> t;
    while(t--){
        
        cin >> n;
        
        cout << dp[n] << '\n';
        
    }
    
    
    

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
