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

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    priority_queue<int>big;
    // 최대 힙  ( 오름 차순 )
    priority_queue<int, vector<int>, greater<int>> small;
    // 최소 힙  ( 내림 차순 )
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        
        if(big.empty())
            big.push(a);
        else{
            if(big.size() > small.size())
                small.push(a);
            // big가 더 클 경우 small에 넣어준다.
            // 즉 각각 하나씩 넣어주는 식
            else
                big.push(a);
            // big이 더 작을 경우 big에 넣어줌
            
            if(big.top() > small.top()){
                int Btop = big.top();
                int Stop = small.top();
                
                big.pop();
                small.pop();
                
                big.push(Stop);
                small.push(Btop);
                
            }
            // 최대 힙의 top ( 최대값 ) 이 최소 힙의 top ( 최솟값 ) 보다 크면 값을 교환한다.
            // 이것을 계속 하면서 맞추어줌
            
            // 즉, small이나 big에 값을 넣어 주었을 경우에
            // 그 우선순위 큐들의 top을 비교하여 big에 더 큰 값이 있을 경우 small에 작은 값과
            // 바꾸어 주어야 big에는 작은 수들,, small에는 큰 수들이 나온다.
            
        }
        
        cout << big.top() << '\n';
        // 그러면 big의 top이 중간값이 된다.
        
        // 여기서는 먼저 big에 넣어주고 크로스로 들어가므로 항상 big의 사이즈가 small의 사이즈 이상이므로
        // 홀수 일 경우에는 big.top이 제일 가운데 일 것이고, 짝수일때도 big.top이 제일 가운데 일것이다.
        
    }
    
    
    
    
    

    return 0;

}


// 그냥 정렬된다고 생각하지말고 두개의 힙을 구현하여 거기서 해주어야 한다.
// 시간 제한이 0.1초 이므로 우선 순위 큐를 사용하여 풀어야 한다.

// 예를 들어 1, 5, 2, 10, -99, 7, 6이 들어왔을 때

// Big 1    Big 1       Big 1, 2    Big 1, 2
// Small    Small 5     Small 5     Small 5, 10

// Big -99, 1, 2    Big -99, 1, 2       Big -99, 1, 2, 6
// Small 5, 10      Small 5, 7, 10      Small 5, 7, 10    ( 여기서 5보다 6이 더 크므로)

// Big -99, 1, 2, 5
// Small 6, 7, 10           // 따라서 5가 중간 값이 됨


// 생각하기는 어려웠지만 이해가 되었다..! 어떻게 다들 이거 생각하는거디
