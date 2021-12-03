

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int>st;
    
    for(int i=0;i<moves.size();i++){
        int num = moves[i] - 1;
        for(int j=0;j<board.size();j++){
            if(board[j][num]){
                if(!st.empty() && st.top() == board[j][num]){
                    st.pop();
                    answer += 2;
                }
                else
                    st.push(board[j][num]);
                board[j][num] = 0;
                break;
                // 0으로 만들고 break 시키고 다음 i를 진행한다.
            }
        }
    }
    
    return answer;
}

// 00000
// 00103
// 02501
// 42442
// 35131

// 1 5 3 5 1 2 1 4

// 생각한 대로 푸는게 맞아서 신기하다... 카카오 문제를 푸니까 느는 느낌
// stack을 활용할때 empty를 꼭 체크 해주고, 그 다음에 top과 맞는지 확인..!
// 그리고 0으로 바꾸어서 밑에 부분을 체크 할 수 있게 해야 한다.




