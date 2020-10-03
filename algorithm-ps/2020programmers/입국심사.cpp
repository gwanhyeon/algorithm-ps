//
//  입국심사.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/27.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n = 6;
vector<int> times{7,10};
int main(void){
    sort(times.begin(), times.end());
    
    long long left = 1;
    long long right = (long long) times[times.size()-1] * n;
    long long answer = right;
    
    // 추정시간값 / 각시간별 심사시관 = 심사관당 맡을 수 있는 입국자수
    while(left<=right){
        long long mid = (left + right) / 2;
        long long sum = 0;
        
        for(vector<int>::iterator iter = times.begin(); iter != times.end(); iter++){
            sum += mid / (*iter);
        }
        if(sum < n){
            if(answer > mid){
              answer = mid;
            }
            left = mid+1;
        }
        else if(sum > n){
            right = mid-1;
        }
    }
    cout << answer;
    return 0;
}
