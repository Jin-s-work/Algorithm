
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


void rev(stack<char> & s){
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    // stack이 없어질때까지 s를 출력하고, pop해줌
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> t;
    
    while(t--){
        
        string st;
        cin >> st;
        cin >> k;
        
        vector<int>arr(26);
        for(int i=0;i<st.size();i++){
            arr[st[i] - 'a']++;
        }
        // 알파벳 별로 하나씩 늘려줌 개수 세주는 것
        
        int ans1 = MAX;
        int ans2 = -1;
        
        for(int i=0;i<st.length();i++){
            if(arr[st[i] - 'a'] < k)
                continue;
            // 알파벳 마다 조사해서 k보다 작으면 그냥 넘어감
            
            // 넘을 경우
            int num = 0;
            for(int j=i;j<st.length();j++){
                if(st[i] == st[j])
                    num++;
                // 같은 스트링일 경우 num을 늘림
                
                if(num == k){
                    ans1 = min(ans1, j - i + 1);
                    ans2 = max(ans2, j - i + 1);
                    break;
                }
                // num이 k가 되면, 최대 최소 찾아줌
                // 길이 이므로 마지막의 j의 인덱스 - 제일 처음인 i의 인덱스 + 1
            }
        }
        // 가장 짧은 k개 포함하는 연속 문자열이므로, 3번 답 또한 같은 거로 시작해서 끝나야 최소이다.
        // 따라서 여기서 최대 최소를 구하면 댄다.
        
        if(ans1 == MAX || ans2 == -1)
            cout << "-1" << '\n';
        else
            cout << ans1 << " " << ans2 << '\n';
        
        // 둘 중 하나라도 안 바뀌면 없는 것이므로 -1
        
    }
    
    
    
    return 0;

}


// 고민하다가 찾았는데, 좋은 풀이 인것 같다..
// 비슷하게 생각하기도 했고, 풀수도 있었겠지만 부족함을 느낌
