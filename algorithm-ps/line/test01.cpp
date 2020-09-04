//
//  test01.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/29.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int select, int N, )
int main(void){
    
    int N = 2;
    int check[N];
    vector<vector<int>> simulation_data{{0, 3}, {2, 5}, {4, 2}, {5, 3}};
    
    
    int allocation[N];
    
    int time = 0;                               // 현재 시각
    int cnt = simulation_data.size();           //고객수
    
    
        
        for(int i=0; i<simulation_data.size(); i++){
            
            
            // 할당할 수 있으면
            while(cnt == 0 || cnt == 1){
                
                for(int j=0; j<simulation_data[i].size()-1; j++){
                    
                    allocation[cnt] = simulation_data[i][j];
                    
                }
                cnt++;
            }
            
            if(cnt == 2){
                
                time+=1;
            }
            
        }
        
    }
    
    
    
    
    return 0;
}
