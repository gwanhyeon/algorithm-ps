//
//  크레인인형뽑기.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/24.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for(int i=0; i<moves.size(); i++){
        int moves_size = moves[i]-1;
        for(int j=0; j<board.size(); j++){
            // 인형이 있는 경우
            if(board[j][moves_size] != 0){
                if(!s.empty() && s.top() == board[j][moves_size]){
                       s.pop();
                       answer +=2;
                }else {
                    s.push(board[j][moves_size]);
                }
                   board[j][moves_size] = 0;
                    break;
            }
        }
    }
    return answer;
}
