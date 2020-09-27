//
//  구명보트.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/26.
//  Copyright © 2020 kgh. All rights reserved.
//https://m.blog.naver.com/tkddn0928/221790401154

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void){
    vector<int> people{70, 50, 80, 50};
    int limit = 100;
    
    int answer =0;
    int head = 0;
    int tail = people.size()-1;
    sort(people.begin(),people.end());
    while(head <= tail){
        if(people[head] + people[tail] <= limit){
            head++;
            tail--;
        }else {
            tail--;
        }
        answer++;
    }
    cout << answer;
     
    
    /*
    int people_size = people.size();
    sort(people.begin() ,people.end());
    
    int sum = 0;
    int answer = 0;
    for(int i=0; i<people_size; i++){
        if(sum + people[i] <= limit){
            sum += people[i];
        }else {
            answer++;
        }
        
    }
    cout << answer;
     */
     
}
