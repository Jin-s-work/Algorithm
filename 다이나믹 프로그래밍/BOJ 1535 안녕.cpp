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

// control i
#define MAX 987654321
#define mod 1000000000
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int lost[25];
int gain[25];
int dp[110];


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;

    
    for(int i=1;i<=n;i++){
        cin >> lost[i];
    }
    
    for(int i=1
        ;i<=n;i++){
        cin >> gain[i];
    }
    
    // 전에 완전탐색으로 풀려고 했으나, DP로 풀면 쉽게 가능하다.
    for(int i=1;i<=n;i++){
        for(int j=100;j>lost[i];j--){
            dp[j] = max(dp[j], dp[j - lost[i]] + gain[i]);
        }
    }
    // i는 1부터 올려주고, j의 경우에는 100에서 lost[i]까지 줄어드는 식으로 해본다.
    // dp[j]이거나 dp[j-lost[i]] + gain[]를 해준 경우를 비교해서 max를 찾아준다.
    // lost[i]까지 하는 이유는 어차피 그보다 작으면 할 수가 없기에
    
    cout << dp[100];
    
    
    
    return 0;
    
}

//  왜 안되는지 아직 잘 모르겠는 DFS 풀이...
 
//int Max = 0;
//void DFS(int num, int health, int happy){
//
//    if(health <= 0 || num >= n){
//        if(Max < happy)
//            Max = happy;
//        cout << Max << '\n';
//        return;
//    }
//
//    DFS(num+1, health - lost[num], happy + gain[num]);
//    DFS(num+1, health, happy);
//}
//
//int main(){
//
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//
//    cin >> n;
//
//
//    for(int i=0;i<n;i++){
//        cin >> lost[i];
//    }
//
//    for(int i=0;i<n;i++){
//        cin >> gain[i];
//    }
//
//    DFS(0,100,0);
//
//    cout << Max;
//
//    return 0;
//
//}
