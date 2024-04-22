import Foundation

func solution(_ my_string:String, _ n:Int) -> String {
    
    var arr = ""
    
    for k in my_string{
        for i in 0..<n{
            arr.append(k)
        }
    }
    
    return arr
}