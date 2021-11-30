#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0;i<n;i++){
        arr1[i] = arr1[i] | arr2[i];
        // 숫자 그 자체로 OR 연산을 하여 나머지로 한다.
        string st = "";
        
        while(st.size() != n){
            if(arr1[i] % 2 == 0){
                st += ' ';
            }
            else
                st += '#';
            
            arr1[i] /= 2;
        }
        
        reverse(st.begin(), st.end());
        // 밑에서 부터 거꾸로 하므로 reverse 해주어야 한다.
        answer.push_back(st);
        // 그 줄 자체를 answer에 넣어준다. for문 안에서
        
    }
    
    
    return answer;
}

// 하나라도 벽이면 전체도 벽
// 둘다 공백이면 둘다 공백












