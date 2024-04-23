import Foundation

func solution(_ str_list:[String], _ ex:String) -> String {
    
    var ans = ""
    for k in str_list{
        if k.contains(ex){
            continue
        }
        else{
            ans.append(k)
        }
    }
    
    return ans
}