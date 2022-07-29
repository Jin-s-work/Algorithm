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


string st[501];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> st[i];
    }
    
    bool check = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(st[i][j] == 'S'){        // 양일 경우
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    // 넘어가는 nx가 범위를 넘으면 continue
                    
                    if(st[nx][ny] == 'W')
                        check = true;
                    // 양에서 바로 다음으로 넘어가는 부분이 W면 check를 true로
                }
            }
        }
    }
    
    if(check)
        cout << 0 << '\n';
    // 양 바로 옆에 있으면 무조건 안됨
    else{
        cout << 1 << '\n';
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(st[i][j] == 'S'){
                    for(int k=0;k<4;k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        
                        if(st[nx][ny] == '.')
                            st[nx][ny] = 'D';
                        // .일 경우 그것을 D로 바꾸어 막아줌
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            cout << st[i] << '\n';
            
        }
        
    }
    
    
    return 0;

}

