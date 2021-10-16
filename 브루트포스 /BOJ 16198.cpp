
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
int h;

vector<int>v;
int ans = 0;

void DFS(int sum){
    
    if(v.size() == 2){
        ans = max(ans, sum);
        return;
    }
    // 2개되면 비교 못하므로 비교하여 끝내기
    
    for(int i=1;i<v.size()-1;i++){
        int energy = v[i-1] * v[i+1];
        // 0부터 v.size()까지 이므로 1~v.size()-1
        int mid = v[i];
        
        v.erase(v.begin() + i);
        // v[i] 지우기
        DFS(sum + energy);
        v.insert(v.begin() + i, mid);
        // 지웠다가 다시 넣어줌..? 사실 재귀가 잘 이해가 가지 않는다.
    }
    
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    DFS(0);
    
    cout << ans;
    
    
    return 0;
}



