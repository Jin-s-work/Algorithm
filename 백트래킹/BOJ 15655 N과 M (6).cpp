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
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;
      

int arr[10001];
bool check[10001];
int ans[10001];

void DFS(int num, int cnt){
    if(num == m){
        for(int i=0;i<m;i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=cnt;i<n;i++){
        if(check[i])
            continue;
        
        
        check[i] = true;
        ans[num] = arr[i];
        DFS(num+1, i+1);
        // 전에 (2)? 에서 오름차순으로 풀듯이 하여 DFS에 한개의 변수를 더 넣었다.
        // 숫자가 올라갈 수록 전에 했던 것들을 넣어주는 느낌이다
        
        check[i] = false;
        
    }
    
}



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    DFS(0,0);
    
    
    return 0;
    
}
