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
#include <sstream>

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


bool check[10];
int dp[10];
int arr[10];
int Max = -1;

void DFS(int num){
    if(num == n){
        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans += abs(dp[i] - dp[i+1]);
        }
        
        if(ans > Max)
            Max = ans;
        
        // 깊이가 주어진 n에 다다랐을 경우 ans를 구해서 제일 클 경우 갱신한다.
        // DFS를 통하여 전수조사 하여 제일 큰 값을 구한다.
        
        return;
    }
    
    for(int i=0;i<n;i++){
        if(check[i])
            continue;
        // 중복은 피하기 위하여
        
        dp[num] = arr[i];

        check[i] = true;
        DFS(num+1);
        check[i] = false;
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    
    DFS(0);
    
    cout << Max;
    
    return 0;

}

