
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
    
    
    cin >> t;
    
    while(t--){
        
        string st;
        cin >> st;
        
        bool check = false;
        if(st[0] == 'A' || st[0] == 'B' || st[0] == 'C' || st[0] == 'D' || st[0] == 'E' || st[0] == 'F')
            check = true;
        
        if(!check){
            cout << "Good" << '\n';
            continue;
        }
        // false에서 true로 바꾸는 과정이므로, 아닌 경우 바로바로 하는 것이 유익함
        
        check = false;
        
        int n = st.size();
        if(st[n-1] == 'A' || st[n-1] == 'B' || st[n-1] == 'C' || st[n-1] == 'D' || st[n-1] == 'E' || st[n-1] == 'F')
            check = true;
        
        if(!check){
            cout << "Good" << '\n';
            continue;
        }
        
        char ch = 'S';
        // 처음은 시작이므로 그냥 S로 잡아줌
        
        for(int i=1;i<st.size()-1;i++){
            if(st[i-1] != st[i]){       // 계속 나오므로 다를 때까지 찾아준다.
                if(st[i-1] == 'B' || st[i-1] == 'D' || st[i-1] == 'E'){
                    if(ch == 'S' && st[i] == 'A')   // 전에가 BDE인 경우에는 ch가 처음이고,
                        ch = 'A';                   // 무조건 A여야 한다. 아닐 경우 빠짐
                    else{
                        check = false;
                        cout << "Good" << '\n';
                        break;
                    }
                }
                else if(st[i-1] == 'A'){        // 전에가 A일 경우
                    if((ch == 'S' || ch == 'A') && st[i] == 'F')  // ch에 있는게 S,A 그리고 F
                        ch = 'F';       // 여기서 ch가 S일 수도 있는 것은
                    else{               // 문자열이 처음에 0개로 시작하고, A가 나왔을 경우 다음이 F 가능
                        check = false;  // 여기가 포인트 인듯..? 어렵다.
                        cout << "Good" << '\n';
                        break;
                    }
                }
                else if(st[i-1] == 'F'){        // 전에가 F일 경우
                    if(ch == 'F' && st[i] == 'C')   // F가 들어와있어야 하고, C여야
                        ch = 'C';
                    else{
                        check = false;
                        cout << "Good" << '\n';
                        break;
                    }
                }
                else if(st[i-1] == 'C'){        // 전에가 C일 경우
                    if(ch == 'C' && (st[i] == 'A' || st[i] == 'B' || st[i] == 'C' || st[i] == 'D' || st[i] == 'E' || st[i] == 'F')){
                    }       // 확인 해주고 아닐 경우에는 false일 경우 나간다.
                    else{
                        check = false;
                        cout << "Good" << '\n';
                        break;
                    }
                }
                else{       // st[i-1]가 A,B,C,D,E,F가 아닐 경우는 바로 Good
                    check = false;
                    cout << "Good" << '\n';
                    break;
                }
            }
            
        }
        
        if(check)
            cout << "Infected!" << '\n';
        // 다 넘어왔으면 감염됨
        
    }
    
    
    
    
    return 0;

}


// 고려해야 할 것이 너무 많다...
// 다른 풀이를 보니 되게 간단하게 해준 것도 많다..
// stage로 나누어서 하는 것도 괜찮네
