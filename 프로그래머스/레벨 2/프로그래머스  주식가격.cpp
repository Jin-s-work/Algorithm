#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0;i<prices.size()-1;i++){
        // 다음에서 끝까지 하므로 얘는 그 전까지만
        int time = 0;
        for(int j=i+1;j<prices.size();j++){
            if(prices[i] <= prices[j]){
                time++;
            }
            else{
                time++;
                break;
            }
        }
        answer.push_back(time);
    }
    answer.push_back(0);
    
    
    return answer;
}






#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int n = prices.size();
    
    for(int i=0;i<n-1;i++){
        int num = 0;
        for(int j=i+1;j<n;j++){
            if(prices[i] <= prices[j])  // 가격이 안떨어진 경우
                num++;
            else{       // 가격이 떨어졌을 경우
                num++;
                break;
        }}
        answer.push_back(num);
    }
    answer.push_back(0);
    
    return answer;
}
