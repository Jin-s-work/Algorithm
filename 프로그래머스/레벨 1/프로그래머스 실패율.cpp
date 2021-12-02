#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<double, int>v1, pair<double, int>v2){
    // 여기서는 이미 vector가 있기에 pair로만 받아서 정렬해주는 역할이다.
    if(v1.first == v2.first){
        if(v1.second < v2.second)
            return true;
        else
            return false;
    }   // first가 서로 같으면 뒤에가 클 수록 true
    else if(v1.first > v2.first){
        return true;
    }   // first가 앞에가 크면 true
    else        // 위에 들이 아닐 경우 false
        return false;
        
}


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<pair<double, int>>v;
    sort(stages.begin(), stages.end());
    
    for(int k=1;k<=N;k++){
        int play = 0;
        int stay = 0;
        
        for(int i=0;i<stages.size();i++){
            if(stages[i] >= k)
                play++;
            if(stages[i] == k)
                stay++;
            // 만약 클 경우 play를 증가시켜주고, 거기서 멈추는 경우 stay'도' 증가시켜준다.
        }
        
        if(stay == 0){
            v.push_back({0, k});
            // stay가 없다면 실패율은 0이므로 0을 넣는다.
        }
        else{
            v.push_back({(double)stay / play, k});
        }   // 0이 아닌 경우 stay / play 즉 실패율을 k와 함께 넣어준다.
    }
    
    sort(v.begin(), v.end(), cmp);
    // 위의 cmp에 따라 정렬해준다.
    
    for(int i=0;i<N;i++){
        answer.push_back(v[i].second);
        // second가 답이므로 정렬함에 따라 넣어준다.
    }
    // 어떻게 생각하는지 쉬운데 생각 자체를 하기에 힘들거 같은데 더 더 많이 풀어보자.
    
    return answer;
}
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//bool compare(pair<double, int>a, pair<double, int>b){
//    if(a.first == b.first){
//        if(a.second < b.second)
//            return true;
//        else
//            return false;
//    }
//    else if(a.first > b.first)
//        return true;
//    else
//        return false;
//}
//
//vector<int> solution(int N, vector<int> stages) {
//    vector<int> answer;
//
//    int m = stages.size();
//    vector<pair<double,int>> v;     // 처음엔 확률, stage 난이도로 저장
//
//    sort(stages.begin(), stages.end()); // 처음에 오름차순으로 하여 편하게
//
//    for(int k=1;k<=N;k++){      // 각각 stage 난이도 마다 해보는것!
//        int play = 0;
//        int stay = 0;
//
//        for(int i=0;i<m;i++){
//            if(stages[i] >= k)  // 각 stage인 k를 볼때
//                play++;         // 일정이상 크면 play를 증가
//            if(stages[i] == k)
//                stay++;         // 같으면 stay를 증가
//        }
//
//        if(stay == 0)       // stay가 0이란 것은 실패율이 0이므로
//            v.push_back({0,k});     // 0과 k를 넣어준다.
//        else
//            v.push_back({(double)stay/play, k}); // 아닐경우 확률과 k
//
//    }
//
//    sort(v.begin(), v.end(), compare);
//
//    for(int i=0;i<v.size();i++){
//        answer.push_back(v[i].second);
//        // 각각 stage들을 answer에 push해준다.
//        cout << v[i].first << '\n';
//        // 출력은 실패율들을 출력해준다.
//    }
//
//    return answer;
//}
//
//
//
//
//
//
//
