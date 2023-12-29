

#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <deque>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h,w;

int arr[11];
int input[11];
bool check[11];

void DFS(int num){
    if(num == m){
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=0;i<n;i++){
        if(check[i])
            continue;
        // 중복되는 수열을 여러 번 출력하면 안되므로, check로 해서 한번 하면 넘어가게
        check[i] = true;
        arr[num] = input[i];
        DFS(num + 1);
        check[i] = false;
        
        
    }


}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    
    sort(input, input + n);
    
    DFS(0);
    
   
    

    return 0;
}


