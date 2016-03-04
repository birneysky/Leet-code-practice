//
//  ArraySolution.cpp
//  leet-code
//
//  Created by zhangguang on 16/3/4.
//  Copyright © 2016年 com.github. All rights reserved.
//

#include "ArraySolution.hpp"

//使用STL
long ArraySolution::removeDuplicates1(vector<int>& nums)
{
    /*unique函数是一个去重函数， unique的功能是去除相邻的重复元素(只保留一个),
     其实它并不真正把重复的元素删除，是把重复的元素移到后面去了，
     然后依然保存到了原数组中，然后 返回去重后最后一个元素的地址，
     因为unique去除的是相邻的重复元素，所以一般用之前都会要排一下序*/
    vector<int>::iterator end_unique = unique(nums.begin(), nums.end());
    /*
     书上说 difference_type，带符号类型，足以保存两个迭代器之间的距离。
     假设迭代器 m 指向第 3 个元素，迭代器 n 指向第 4 个元素，那么 n - m 自然等于 1 ，
     而 m - n 是等于 -1 （类型都是difference_type）。difference_type对应的无符号版本是size_type。
     STL的设计者取名的时候大概参考了C库的 ptrdiff_t（很容易认为是pointer difference type的简写）和 size_t （size type的简写）
     */
    vector<int>::difference_type count =  distance(nums.begin(), end_unique);
    return count;
}

/*
 距离说明算法
 A = [1,1,2];
 循环开始
 1 index = 0,i = 0; num[index] = 1; num[i] = 1; num[index] == num[i]；进入下次循环
 2 index = 0,i = 1; num[index] = 1; num[i] = 1; num[index] == num[i]; 进入下次循环
 3 index = 0,i = 2; num[index] = 1; num[i] = 2; num[index] != num[i]; ++index-->index = 1;nums[1] = num[2];计入下次循环
 4 循环结束
 
 算法思想：
    首先由一个指针指向数组起始位置(index = 0)，然后循环遍历数组，用该指针指向的元素跟数组中的每一个元素比较，
    如果如果不相等（如果这个元素是a[3]）,指针指向下一个元素(++index)，并且将a[3]的值赋值给当前指针指向的元素。
 
|(index = 0)
|
▽
1  1  2 3 3 4 5  (比较index 和 i 所表示的值，相等，i++)
△
|
|(i = 0)
 
|(index = 0)
|
▽
1  1  2 3 3 4 5  (比较index 和 i 所表示的值，相等，i++)
   △
   |
   |(i = 1)
 
 |(index = 0)
 |
 ▽
 1  1  2 3 3 4 5  (比较index 和 i 所表示的值，不等，array[++index] = array[i];i++)
       △
       |
       |(i = 2)
 
    |(index = 1)
    |
    ▽
 1  2  2  3  3  4  5  (比较index 和 i 所表示的值，不等，array[++index] = array[i];i++)
          △
          |
          |(i = 3)
 
       |(index = 2)
       |
       ▽
 1  2  3  3  3  4  5  (比较index 和 i 所表示的值，相等，i++)
             △
             |
             |(i = 4)
 
       |(index = 2)
       |
       ▽
 1  2  3  3  3  4  5  (比较index 和 i 所表示的值，不等，array[++index] = array[i];i++)
                △
                |
                |(i = 5)
 
          |(index = 3)
          |
          ▽
 1  2  3  4  3  4  5  (比较index 和 i 所表示的值，不等，array[++index] = array[i];i++)
                   △
                   |
                   |(i = 6)
 
             |(index = 3)
             |
             ▽
 1  2  3  4  5  4  5  (比较index 和 i 所表示的值，不等，array[++index] = array[i];i++)
                     △
                     |
                     |(i = 7)
 
 */

int ArraySolution::removeDuplicates2(vector<int>& nums)
{
    if (nums.empty()) {
        return 0;
    }
    
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[index] != nums[i]) {
            nums[++index] = nums[i];
        }
    }
    
    return index + 1;
}