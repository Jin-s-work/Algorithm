
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


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    vector<pair<int, int>>v;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        v.push_back({i, a});
    }
    
    while(!v.empty()){
        
        cout << v.front().first << " ";
        int k = v.front().second;
        v.erase(v.begin());
        // 그러고 처음을 없애줌
        // 보통은 queue로 pop을 하지만 이때에는 특정부분을 지우므로 vector가 맞는 것 같다.
        
        if(k < 0){      // 이동 하는 부분이 음수일 경우
            for(int i=0;i<abs(k);i++){              // k만큼
                v.insert(v.begin(), v.back());
                v.erase(v.end() - 1);           // 맨 뒤 원소를 앞에 넣고, 맨 뒤를 지운다.
                // 맨 마지막을 지우면 안되고 1 빼주어서 지워야 한다.
            }
            // insert(vector 삽입할 위치, 삽입 시작 위치, 삽입 끝 위치)
            // 여기서는 v의 마지막 원소를 v의 제일 앞에 넣어주는 것.
        }
        else{           // k가 양수일 떄
            for(int i=0;i<k-1;i++){
                v.push_back(v.front());
                v.erase(v.begin());         // 맨 앞 원소를 삭제 후 맨 뒤에 삽입
            }                           // 삭제 하기전 먼저 front를 push해주고 erase한다.
        }                           // 여기서 이렇게 하면서 옮겨 가는 것이다..
        // 어떻게 생각한거디... 싱기
        
        // 즉 여기서 각각 음수일때는 abs(k)번, 양수일 때는 k-1번까지 해주면서 (그 만큼 이동함을 의미)
        // 그 때 딱 끝내면서 그 때 vector를 출력해줌
    }
    
    
    return 0;

}


// erase를 위하여 vector를 사용할 경우, 인덱스 옮겨갈 때 매번 제일 앞을 뒤로 옮기거나
// 제일 뒤를 앞으로 옮기면서 왼쪽 오른쪽으로 이동한다... 싱기
