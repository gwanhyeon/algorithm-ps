//
//  크레인인형뽑기게임.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/04.
//  Copyright © 2020 kgh. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
int check[101][101];


int main(void){
    
    vector<vector<int>> board(5);
    vector<int> moves;
    
    board[0].push_back(0);
    board[0].push_back(0);
    board[0].push_back(0);
    board[0].push_back(0);
    board[0].push_back(0);
    board[1].push_back(0);
    board[1].push_back(0);
    board[1].push_back(1);
    board[1].push_back(0);
    board[1].push_back(3);
    board[2].push_back(0);
    board[2].push_back(2);
    board[2].push_back(5);
    board[2].push_back(0);
    board[2].push_back(1);
    board[3].push_back(4);
    board[3].push_back(2);
    board[3].push_back(4);
    board[3].push_back(4);
    board[3].push_back(2);
    board[4].push_back(3);
    board[4].push_back(5);
    board[4].push_back(1);
    board[4].push_back(3);
    board[4].push_back(1);
    moves.push_back(1);
    moves.push_back(5);
    moves.push_back(3);
    moves.push_back(5);
    moves.push_back(1);
    moves.push_back(2);
    moves.push_back(1);
    moves.push_back(4);
    
    stack<int> res;
    memset(check,0,sizeof(check));
    int ans = 0;
    for(int k=0; k<moves.size(); k++){
        int target = moves[k]-1;
        for(int i=0; i<board.size(); i++){
            if(board[i][target] != 0){
            
                int crain = board[i][target];
                // 스택이 비지 않았을때
                if(!res.empty()){
                    // 터트리는경우
                    if(crain == res.top()){
                        res.pop();
                        ans +=2;
                    }else {
                        res.push(crain);
                    }
                }else {
                    res.push(crain);
                    
                }
                board[i][target] =0;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}

