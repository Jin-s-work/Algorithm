import Foundation

func solution(_ my_string:String, _ s:Int, _ e:Int) -> String {
    
    var ans = ""
    var tmp = ""
    var end = ""
    for (i, st) in my_string.enumerated(){
        if i >= s && i <= e{
            tmp.append(st)
        }
        else if i > e{
            end.append(st)
        }
        else{
            ans.append(st)
        }
    }
    tmp = String(tmp.reversed())
    
    
    return String(ans + tmp + end)
}