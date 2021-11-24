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
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;


int arr[4001];
int order[4001][3];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            arr[b] = c;
        }
        else if(a == 2){
            for(int j=b;j<=c;j++){
                arr[j] = !arr[j];
            }
        }
        else if(a == 3){
            for(int j=b;j<=c;j++){
                arr[j] = 0;
            }
        }
        else if(a == 4){
            for(int j=b;j<=c;j++){
                arr[j] = 1;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        cout << arr[i] << " ";
    }
    cout << '\n';
    
    
    return 0;

}



