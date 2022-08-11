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
      

int arr[11];
bool check[11];

void DFS(int num){
    if(num == m){
        for(int i=0;i<m;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    // 숫자는 1부터 n까지
    for(int i=1;i<=n;i++){
        if(check[i])
            continue;
        
        // i가 아직 방문하지 않은 경우 true로 바꾸고, arr[num]에 현재 i를 넣어주고
        // num+1 을 해서 DFS로 들어간다.
        // num을 계속 증가시키면서 arr에 가능한 수들을 전부 넣어준다.
        check[i] = true;
        arr[num] = i;
        DFS(num+1);
        
        check[i] = false;
    }
    
}



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> m;
    
    DFS(0);
   
    
    
    
    return 0;
    
}
