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


bool close[501];
bool check[501];
int arr[501][501];
int ans = 0;


// BFS로 하는거 보다 그냥 하는게 낫네..

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    
    for(int i=2;i<=n;i++){
        if(arr[1][i] > 0){
            check[i] = true;
            close[i] = true;        // 1과 바로 가까이 있을 경우에만 close를 true로 해준다.
        }
    }
    
    for(int i=2;i<=n;i++){
        if(close[i]){                 // i에 대해서 즉 친구인지를 확인한다. 즉, 친구인지 확인
            for(int j=1;j<=n;j++){    // 친구의 친구까지만 되므로
                if(arr[i][j])         // 연결되어 있을 경우 check를 true로 해준다.
                    check[j] = true;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(check[i])        // check의 개수의 따라 ans를 늘린다.
            ans++;
    }
    
    
    cout << ans;
    
    
    return 0;

}


