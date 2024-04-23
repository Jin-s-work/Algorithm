import Foundation

func solution(_ my_string:String, _ is_prefix:String) -> Int {
    
    let n = is_prefix.count
    
    if my_string.prefix(n) == is_prefix{
        return 1
    }
    else{
        return 0
    }
    
    
    return 0
}