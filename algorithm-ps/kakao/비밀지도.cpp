//
//  비밀지도.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/25.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <string>
#include <vector>
#include <string>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++){
        string res = "";
        for(int j=n-1; j>=0; j--){
            if(arr1[i] & (1<<j) || arr2[i] & (1<<j)){
                res += "#";
            }else {
                res += " ";
            }
        }
        answer.push_back(res);
    }
    
    return answer;
}
