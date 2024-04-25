import Foundation

func solution(_ my_string:String) -> String {
    
    var unique = Set<Character>()
    var ans = ""
    
    for k in my_string{
        if !unique.contains(k){
            unique.insert(k)
            ans.append(k)
        }
    }
    
    
    return ans
}