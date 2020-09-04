//
//  짝지어제거하기.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/31.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>

using namespace std;
int main(void){
    int answer = 0;
    string s= "baabaa";
    
    stack<char> tmp;
    tmp.push(s[0]);
    
    for(int i=1; i<s.size(); i++){
        if(!tmp.empty() && tmp.top() == s[i]){
            tmp.pop();
        }else {
            tmp.push(s[i]);
        }
        
    }
    
    if(tmp.empty()){
        answer = 1 ;
    }else {
        answer = 0;
    }
    
    
    
    
    return 0;
}
 
//int main(void){
//    int answer = 0;
//    bool tf = false;
//    string s= "cdcd";
//    bool erase_tf = false;
//     while(true){
//       // string size is Zero
//       if(s.size() == 0){
//           tf = true;
//           break;
//       }
//
//       for(int i=0; i<s.size()-1; i++){
//           // 알파벳 붙어있는 짝 찾기
//           if(s[i] == s[i+1]){
//               // 짝을 찾으면 제거하기
//               s.erase(i,2);
//               cout << s << "\n";
//               erase_tf = true;
//               break;
//           }
//       }
//         if(erase_tf == false){
//             break;
//         }
//
//   }
//    answer = tf;
//    cout << answer;
//
//
//
//
//    return 0;
//}
