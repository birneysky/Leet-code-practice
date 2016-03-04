//
//  ArraySolution1.hpp
//  leet-code
//
//  Created by zhangguang on 16/3/4.
//  Copyright © 2016年 com.github. All rights reserved.
//

#ifndef ArraySolution1_hpp
#define ArraySolution1_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class ArraySolution1 {
    
public:
    ArraySolution1();
    ~ArraySolution1();
    
    /*假设一个有序的数组，在你之前未知的转轴上是可以轮换的
      比如 0 1 2 3 4 5 6 7  可以变成 4 5 6 7 0 1 2
      你可以给定一个目标值去搜索，如果你在数组中发现它，就返回它在数组中的索引，否则返回 -1；
      假定数组中没有重复的数据
     
     Suppose a sorted array is rotated at some pivot unknown to you beforehand.
     (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
     You are given a target value to search. 
     If found in the array return its index, 
     otherwise return -1. 
     You may assume no duplicate exists in the array.
     二分查找的难度在于左右边界的确定
     */
    int search(const vector<int>& nums, int target);
};

#endif /* ArraySolution1_hpp */
