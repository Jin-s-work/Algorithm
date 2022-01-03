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

string st;
vector<int>v;

int calc(string st){
    int sum = 0;
    for(int i=0;i<st.size();i++){
        sum *= 10;
        sum += (st[i] - '0');
    }
    return sum;
}
// 문자열인 s를 int로 바꾸는 함수

void BFS(string st){
        
    queue<string>q;
    q.push(st);
    
    int num = 0;
    int ans = 0;
    
    while(!q.empty() && num < k){
        
        int qs = q.size();
        set<string> check;
        // set을 이용하여 똑같은 수를 바꾸는 것을 막는다. 메모리 초과 막기
        // 중복을 막는 set을 사용하는 것이 핵심
        
        for(int l=0;l<qs;l++){
            string cur = q.front();
            q.pop();
            
            // 여기서의 st.length()를 함수 전에 m으로 넣어주면 왜 안되는지는 오늘 생각해보아야겠다.
            for(int i=0;i<st.length()-1;i++){
                for(int j=i+1;j<st.length();j++){
                    if(i == 0 && cur[j] == '0')
                        continue;
                    
                    swap(cur[i], cur[j]);
                    
                    if(!check.count(cur)){
                        if(num == k-1)
                            ans = max(ans, calc(cur));
                        
                        q.push(cur);
                        check.insert(cur);
                    }
                    
                    swap(cur[i], cur[j]);
                }
            }
        }
        
        num++;
    }
    
    if(num != k)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
    
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> st >> k;
    
    int m = st.length();
    
    if(m == 1 || (m == 2 && calc(st) % 10 == 0))
        cout << "-1" << '\n';
    // 숫자가 한자리 수이거나 두자리 수 이면서 뒷자리가 0일 때 바꿀 수 없으므로 -1을 출력한다.
    else
        BFS(st);
    
    
    
    return 0;

}
