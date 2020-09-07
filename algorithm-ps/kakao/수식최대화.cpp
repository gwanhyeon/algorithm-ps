//
//  수식최대화.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/04.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    string expression = "100-200*300-500+20";
    
    vector<int> v;
    vector<int> cal(3);
    string tmp = "";
    for(int i=0; i<expression.size(); i++){
        if(expression[i]-'0' >= 0 && expression[i]-'0' <= 9){
            tmp += expression[i];
        }else {
            v.push_back(stoi(tmp));
            tmp = "";
            if(expression[i] == '+'){
                cal[0] += 1;
            }else if(expression[i] == '-'){
                cal[1] += 1;
            }else if(expression[i] == '*'){
                cal[2] += 1;
            }
        }
        if(i == expression.size()-1){
            v.push_back(stoi(tmp));
        }
    }
    vector<int> check;
    for(int i=0; i<cal[0]; i++){
        check.push_back(0);
    }
    for(int i=0; i<cal[1]; i++){
        check.push_back(1);
    }
    for(int i=0; i<cal[2]; i++){
        check.push_back(2);
    }
    sort(check.begin(), check.end());
    
    vector<int> res;
    do {
        int sum = v[0];
        for(int i=1; i<v.size(); i++){
            if(check[i-1] == 0){
                sum += v[i];
            }else if(check[i-1] == 1){
                sum -= v[i];
            }else if(check[i-1] == 2){
                sum *= v[i];
            }
        }
        res.push_back(abs(sum));
    } while (next_permutation(check.begin(), check.end()));
    
    long long max = *max_element(res.begin(), res.end());
    cout << max / 3 << '\n';
    
    return 0;
}
