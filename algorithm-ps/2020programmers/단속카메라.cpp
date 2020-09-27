//
//  단속카메라.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/26.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    
    
    
    
    
    vector<vector<int>> routes{{-20,15}, {-14,-5},{-18,-13}, {-5,-3}};

    sort(routes.begin(), routes.end());

    int camera_location = routes[0][1];// 첫번째 진입차량 위치

    int answer = 1;         // 무조건한대는 넣어야함
    for(int i=1; i<routes.size(); i++){

        if(routes[i][1] < camera_location){
            camera_location = routes[i][1];
        }
        if(routes[i][0] > camera_location){
            answer++;
            camera_location = routes[i][1];
        }
    }

    
                                          
                                          
}
