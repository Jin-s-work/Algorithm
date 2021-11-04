
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
int h, w;


int arr[101][101];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][k] && arr[k][j])
                    arr[i][j] = 1;
            }
        }
    }
    // 즉 arr[i][j]가 그냥 바로 1이 아닐지라도 i-k, k-j가 둘다 1일 경우에는
    // i-j도 연결되므로, 1을 넣어준다.
    // 생각해보면 되게 간단한 그래프 문제( 플로이드 - 와샬 알고리즘 )
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    
    
    return 0;
}

// 처음에 문제를 읽을 때 당연한 소리인 줄 알았는데, i->j를 가는 길이 없어도 k를 거쳐서 갈 수 있을 경우
// 갈 수 있다고 생각해주는 것이었다.
