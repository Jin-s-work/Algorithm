import Foundation

func solution(_ a:Int, _ b:Int) -> Int {
    
    let st = Int(String(a) + String(b)) ?? 0
    
    if st < 2 * a * b{
        return 2 * a * b
    }
    else{
        return st
    }
    
    return 0
}