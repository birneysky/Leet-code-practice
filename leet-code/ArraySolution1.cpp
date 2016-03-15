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
 
 
 |(first)                |(last )
 |                       |
 ▽                       ▽
 7  6  5  4  3  2  1  0
             △
             |
             |(mid)
 
             |(first)    |(last )
             |           |
             ▽           ▽
 7  6  5  4  3  2  1  0
             △
             |
             |(mid)
 
 
 */
int ArraySolution1::search(const vector<int>& nums, int target)
{
    size_t first = 0;
    size_t last = nums.size();
    while (first <= last) {
        size_t mid = first + (last - first) / 2;
        if (nums[mid] == target) {
            return nums[mid];
        }
        else if (nums[first] <= nums[mid]){//升序
            if ( target >= nums[first] && target < nums[mid]) {
                last = mid;
            }
            else
            {
                first = mid + 1;
            }
        }
        else{//降序
            if (target >=nums[last - 1]  && target < nums[mid]) {
                first = mid + 1;
            }
            else
            {
                last = mid;
            }
        }
    }
    
    return -1;
}

/*
 递归法
 */


