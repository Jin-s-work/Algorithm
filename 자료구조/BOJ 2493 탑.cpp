
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
    
    cin >> n;
    
    stack<pair<int, int>>st;
    
    for(int i=1;i<=n;i++){
    
        cin >> k;
        
        while(!st.empty()){
            if(st.top().second > k){
                cout << st.top().first << " ";
                break;
            }
            // 스택이 비어있지 않을 때 원래 있던 탑의 높이가 들어온 것 보다 클 경우 인덱스를 출력해준다.
            // 그리고 끝내줌
            
            st.pop();
        }   // 들어온 값이 원래 있던 값 이상일 경우 pop해주고 들어오는 값을 스택에 넣어준다.
            // pop해주면서 k가 더 작을 경우를 찾는다. 없을 경우 다 없어지고 k가 스택에 들어오게 됨
            
            // 예를 들어 먼저 6이 있다가 9가 들어오면, 9가 더 크므로, st.pop() 해주면 없어지고
            // 9가 그 자리에 들어가게 됨. 그러고 9보다 작은 원소가 들어오면, 9의 인덱스를 출력하고 다음으로 넘어감
            // 인덱스는 곧 앞에 있는 탑들의 수를 의미
        
        if(st.empty()){
            cout << "0" << " ";
        }
        
        st.push({i, k});
    
    }
    
    
    
    return 0;

}

// stack을 이용해서 풀었는데, 어디선가 메모리 오류가 났다..

// 값을 입력 받을 경우 스택을 체크하여 비어잇으면 그 왼쪽에는 탑이 없는 것으로 0을 출력한다.
// 탑이 만약 있을 경우, 현재 입력받은 탑의 높이와 스택에 들어잇는 top의 탑의 높이를 비교하여
// 만약 값의 크기가 현재보다 작으면 그것은 pop하여 넘어가고 다음 값을 비교한다.

// 그와 다르게 저장된 높이 값이 같거나 클 경우, 혹은 비어있을 경우까지 반복한다.
// 그때는 top의 인덱스를 출력하고, 비었을 경우 0을 출력한다.
// 그 다음 현재 입력받은 값을 탑의 인덱스와 같이 push한다.

// 입력받을 때는 pair를 사용하여 인덱스와 같이 삽입

// while(!s.empty()) 를 많이 고려해서 자주 써야겠다.

