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


vector<int>v;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans = 0;
    while(1){
        if(sum >= m)        // 같은 경우에도 빠져 나가야 하므로 밑의 연산을 진행한다.
            sum = sum - v[left++];
        // 합이 구하고자 하는 합인 m보다 큰 경우에는 맨 앞의 v[left]값을 빼주고, left를 ++하며 옆으로 옮긴다.
        else if(right == n)
            break;
        // 끝을 마주하면 멈춘다.
        else{
            sum = sum + v[right++];
            // 아직 sum이 m 미만일 경우 v[right]의 값을 더해다 주고 나서 right++를 통하여 오른쪽을 이동한다.
        }
        
        if(sum == m)
            ans++;
        // 맞을 경우 ans를 증가
    }
    
    cout << ans;
    
    
    
    return 0;
    
}

