//
//  test02.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/29.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> res;
int check[10001];

void dfs(int num, int sum, int cnt, vector<int> cards){
    if(num == sum){
        res.push_back(cnt);
        return;
    }
    if(num < sum){
        return;
    }
    for(int i=0; i<cards.size(); i++){
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        dfs(num,sum+cards[i], cnt+1, cards);
        check[i] = false;
    }
    
    
}
int main(void){
    
    int num = 8;
    vector<int> cards{1,4,6};
    
    dfs(num,0,0,cards);
    int min = *min_element(res.begin(), res.end());
    cout << min;
    
}
