//
//  퀵정렬.cpp
//  algorithm-ps
//
//  Created by kgh on 2020/08/11.
//  Copyright © 2020 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int arr[], int start, int end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

int partion(int arr[], int start, int end){
    int pivot = arr[(start+end) / 2];
    
    while(start <= end){
        while(arr[start] < pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start <= end){
            swap(arr, start,end);
            start++;
            end--;
        }
    }
    return start;
}
void quickSort(int arr[],int start, int end){
    int part2 = partion(arr,start,end);
    
    if(start < part2-1){
        quickSort(arr,start,part2-1);
    }
    if(part2 < end){
        quickSort(arr, part2, end);
    }
}

int main(void){
    int arr[10] = {3,9,4,7,5,0,1,6,8,2};
    
    for(int i=0; i<(sizeof(arr) / sizeof(int)); i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
    
    quickSort(arr,0,(sizeof(arr) / sizeof(int)) -1);
    for(int i=0; i<(sizeof(arr) / sizeof(int)); i++){
        cout << arr[i] << ' ';
    }
    return 0;
}
