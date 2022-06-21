

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int>music;
    map<string, map<int, int>> list;
    for(int i=0;i<genres.size();i++){
        music[genres[i]] += plays[i];
        // music에는 장르들의 합을 넣어줌
        
        list[genres[i]][i] = plays[i];
        // list에는 장르들과 각각의 값을 넣어줌
    }
    
    while(music.size() > 0){
        
        string genre = "";
        int Max = 0;
        
        for(auto k : music){
            if(Max < k.second){
                Max = k.second;
                genre = k.first;
            }
        }       // Max 값이 갱신되면 그 값을 string인 genre에 갱신
        
        for(int i=0;i<2;i++){       // 2개씩 모아 출시하므로 2개
            int MaxVal = 0;
            int idx = -1;
            
            for(auto k : list[genre]){   // 두번째로 장르 내에서 많이 재생된 노래를 찾으므로
                if(MaxVal < k.second){    // 찾아놓았던 genre사용
                    MaxVal = k.second;
                    idx = k.first;
                }
            }
            
            if(idx == -1)
                break;
            answer.push_back(idx);      // 정답인 idx 즉 고유 번호를 리턴
            list[genre].erase(idx);     // 사용하였으므로 그 장르와 인덱스를 삭제한다.
        }
        
    music.erase(genre);
    // 장르와 관련하여 끝나면 지우기
           
    }
    
    return answer;
}

// 솔직히 조금 많이 보고 하긴 하였다.
// Map에 조금 더 익숙하고 좀 더 생각하였다면 풀만 했을 거 같긴 한데 한 골드나 실버1 정도 될듯


//  #include <string>
// #include <vector>
// #include <map>

// using namespace std;

// vector<int> solution(vector<string> genres, vector<int> plays) {
//     vector<int> answer;
    
//     map<string, int>music;
//     map<string, map<int, int>> lists;
    
//     for(int i=0;i<genres.size();i++){
//         music[genres[i]] += plays[i];
//         // 장르 마다 각각 plays를 더해준다.
//         // 장르[i]가 곧 인덱스로 작용되고 그 부분에 plays를 더해주는 것.
        
//         lists[genres[i]][i] = plays[i];
//         // 리스트에 노래번호와 플레이 횟수를 추가해준다.
//     }
    
//     while(music.size() > 0){
//         string genre = "";
//         int Max = 0;
        
//         for(auto k : music){
//             if(Max < k.second){
//                 Max = k.second;
//                 genre = k.first;
//             }
//             // music에서 music.second가 최대보다 클때 갱신해주고
//             // 그 때 최대일 때의 장르를 genre에 넣어준다.
//         }
        
//         for(int i=0;i<2;i++){
//             int value = 0;
//             int idx = -1;
            
//             for(auto k : lists[genre]){
//                 if(value < k.second){
//                     value = k.second;
//                     idx = k.first;
//                 }
//                 // lists에서 music의 값이 최대 일 때의 genre에 대하여
//                 // 그 중에서 제일 클 경우 value에 저장해주고,
//                 // 그 때의 인덱스는 idx에 저장해준다.
//             }
            
//             if(idx == -1)
//                 break;
//             // 그 때의 인덱스가 -1이면 그냥 break
            
//             answer.push_back(idx);
//             lists[genre].erase(idx);
//             // 아닐 경우 answer에 넣어주고, list에서 idx를 지워준다.
//         }
//         music.erase(genre);
//         // music에서도 지워준다.
//         // 그 다음 최대를 알기 위하여
//     }
    
    
//     return answer;
// }

// // 속한 노래가 많은 장르를 먼저
// // 장르 안에 많이 재생된 노래를 먼저
// // 장르 내 재생 횟수가 같으면 고유 번호가 낮은 것을 먼저













