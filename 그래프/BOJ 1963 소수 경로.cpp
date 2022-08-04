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


bool arr[10000];
bool check[10000];



int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> t;
    while(t--){
        int start, last;
        cin >> start >> last;
        
        memset(arr, true, sizeof(arr));
        memset(check, false, sizeof(check));
        
        for(int i=2;i<10000;i++){
            for(int j=2;i*j<10000;j++){
                arr[i*j] = false;
                // 곱해질 경우 false로 소수가 아님
            }
        }
        
        queue<pair<int, int>>q;
        q.push({start, 0});
        check[start] = true;
        
        bool flag = false;
        
        while(!q.empty()){
            int now = q.front().first;
            int num = q.front().second;
            q.pop();
            
            if(now == last){
                cout << num << '\n';
                flag = true;
                break;
            }
            
            for(int i=0;i<4;i++){
                int next;
                for(int j=0;j<10;j++){
                    string st = to_string(now);
                    // 현재의 수를 st에 넣어주고
                    st[i] = j + '0';
                    // string의 자리수를 j로 고치면서 확인한다.
                    next = stoi(st);
                    // 그러고 string을 int로 바꾸어 next를 검사한다.
                    
                    if(!arr[next])
                        continue;
                    // 소수가 아닐 경우 넘어감
                    if(check[next])
                        continue;
                    // 다음 수가 지나갔던 수일 경우 넘어감
                    if(next >= 10000 || next < 1000)
                        continue;
                    // 범위를 넘어갈 경우 그냥 넘어감
                    
                    // 위를 다 만족할 경우 true로 하고 queue에 넣어줌
                    check[next] = true;
                    q.push({next, num + 1});
                    
                }
            }
        }
        if(!flag)
            cout << "Impossible" << '\n';
        
    }

    
    
    return 0;
    
}

