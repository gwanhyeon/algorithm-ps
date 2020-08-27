//
//  실패율.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/25.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int arr[100001];
    int stages_size = stages.size();
    
    for(int i=0; i<stages_size; i++){
        arr[stages[i]]++;
    }
    int ans = -1;
    for(int i=0; i<N+1; i++){
        int good_people = 0;
        int fail_people = 0;
        for(int j=0; j<N+1; j++){
            if(arr[i] < arr[j]){
                good_people += 1;
            }else {
                fail_people += 1;
            }
        }
        //실패율 구하기
        if(good_people != 0){
            if(ans < fail_people/good_people){
                //answer.push_back(i+1);
                answer.push_back(fail_people/good_people);
            }
        }
        //sort(answer.begin(), answer.end(), cmp);
        //cout << people;
    }
    return answer;
}
