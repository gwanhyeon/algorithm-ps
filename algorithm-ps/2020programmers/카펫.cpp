//
//  카펫.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/09/26.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int check[100000001];
int answer[2];

void dfs(int sum, int x, int y){
    
    if(x*y == sum){
        answer[0] = x;
        answer[1] = y;
        return;
    }
    
    for(int i=0; i<100000001; i++){
        
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        dfs(sum, x+i, y);
        check[i] = false;
        dfs(sum, x, y+i);
        
    }
    
    
}
int main(void){
    
    int brown = 10;
    int yellow = 2;
    int sum = brown + yellow;
    
    dfs(sum,1, 1);
    cout << answer[0] << answer[1];
    
    return 0;
}
