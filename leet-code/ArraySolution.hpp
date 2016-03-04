//
//  ArraySolution.hpp
//  leet-code
//
//  Created by zhangguang on 16/3/4.
//  Copyright © 2016年 com.github. All rights reserved.
//

#ifndef ArraySolution_hpp
#define ArraySolution_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/*关于线性表的操作,数组，单链表，双向链表*/

class ArraySolution {
    
    
public:
    /*给定一个有序的数组，删除重复的元素，使其每个元素只能在数组中出现一次，并返回数组长度，
     不许创建其他数组，消耗额外的内存，必须在源数组中完成工作
     
     Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
     Do not allocate extra space for another array, you must do this in place with constant memory.
     For example, Given input array A = [1,1,2],
     Your function should return length = 2, and A is now [1,2].
     */
    ArraySolution();
    ~ArraySolution();
    
    long removeDuplicates1(vector<int>& nums);
    int removeDuplicates2(vector<int>& nums);
    /*
     根据上面”删除重复的元素功能“，实现最多允许重复两次的功能；
     */
    size_t removeDuplicates3(vector<int>& nums);
    int removeDuplicates4(vector<int>& nums);
};




#endif /* ArraySolution_hpp */
