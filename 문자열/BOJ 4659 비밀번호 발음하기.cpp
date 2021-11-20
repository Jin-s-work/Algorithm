
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
    
    
    while(1){
        
        string st;
        cin >> st;
        bool check = true;
        
        if(st == "end")
            break;
        
        if(st.find("a") == string::npos && st.find("e") == string::npos && st.find("i") == string::npos && st.find("o") == string::npos && st.find("u") == string::npos)
            check = false;
        // st.find("문자열") == string::npos 이면 그 문자열이 없다는 뜻
        // 즉 없을 때 string::npos를 출력한다.
        
        for(int i=0;i<st.length()-1;i++){
            if(st[i] == st[i+1] && st[i] != 'e' && st[i] != 'o')
                check = false;
        }
        
        int num1 = 0;
        int num2 = 0;
        for(int i=0;i<st.length();i++){
            
            if(st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u'){
                num1++;
                num2 = 0;
            }
            else{
                num2++;
                num1 = 0;
            }
            
            if(num1 >= 3 || num2 >= 3)
                check = false;
            
        }
        
        
        if(check)
            cout << "<" << st << "> is acceptable." << '\n';
        else
            cout << "<" << st << "> is not acceptable." << '\n';

        
    }
    
    
    
    
    return 0;

}



// 문자열 노가다해서 맞았다..!
// 싱기.. 더 열심히 하자
