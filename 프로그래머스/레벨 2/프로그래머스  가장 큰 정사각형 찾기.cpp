

#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    
    for(int i=1;i<board.size();i++){
        for(int j=1;j<board[0].size();j++){
            if(board[i][j] == 1){
                board[i][j] = 1 + min({board[i-1][j-1], board[i][j-1], board[i-1][j]});
                answer = max(answer, board[i][j]);
            }
        }
    }
    
    

    return answer*answer;
}

// 처음에는 내가 첫 점, 오른쪽 점과 밑의 점이 1, 대각선 밑도 1일 경우에 그 대각선 밑의 수를
// 증가시키려고 했는데, seg 에러가 떠서

// 다음 방법은 min을 활용하여 +1,0 0,+1 +1,+1을 이용하는 것

// 좀 더 많이 풀어보자













