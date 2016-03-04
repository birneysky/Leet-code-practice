//
//  ArraySolution1.cpp
//  leet-code
//
//  Created by zhangguang on 16/3/4.
//  Copyright © 2016年 com.github. All rights reserved.
//

#include "ArraySolution1.hpp"


ArraySolution1::ArraySolution1()
{
    
}

ArraySolution1::~ArraySolution1()
{
    
}


/*
 tartet = 2;
 
 |(first = 0)            |(last = size)
 |                       |
 ▽                       ▽
 0  1  2  3  4  5  6  7 (如果 array[mid] == target, 返回,  如果 array[first] <= array[mid]，如果array[first]<=array[target]并且array[target]<array[mid],last = mid)
             △
             |
             |(mid = first + (last - first) / 2)
 
 |(first=0)  |(last = 4)
 |           |
 ▽           ▽
 0  1  2  3  4  5  6  7 (如果 array[mid] == target, 返回,  如果 array[first] <= array[mid]，如果array[first]<=array[target]并且array[target]<array[mid],last = mid)
       △
       |
       |(mid = 2)
 
 */
int ArraySolution1::search(const vector<int>& nums, int target)
{
    return 0;
}