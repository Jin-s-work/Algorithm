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
#define mod1 1000000000
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
unsigned long long n,m,k;
int l,r,t;
int h;



vector<ll>v;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    
    cin >> n >> m;
    // n개의 줄, 사람이 m명
    
    for(int i=0;i<n;i++){
        unsigned long long a;
        cin >> a;
        v.push_back(a);
    }
    
    unsigned long long left = 0;
    unsigned long long right = m * v[0];
    // 심사 기간이 제일 적은 곳에 모든 사람이 검사하는 경우가 최대이다.
    unsigned long long ans = 0;
    
    while(left <= right){
        unsigned long long mid = (left + right) / 2;
        
        unsigned long long num = 0;
        
        for(int i=0;i<n;i++){
            num += ll((mid / v[i]));
        }
        
        if(num >= m){
            if(ans > mid || ans == 0){
                ans = mid;
            }
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
           
    cout << ans;
    
    
    
    return 0;
    
}



