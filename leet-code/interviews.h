//
//  interviews.h
//  leet-code
//
//  Created by zhangguang on 16/3/18.
//  Copyright © 2016年 com.github. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface interviews : NSObject

@end


/*
 
1.什么情况使用 weak 关键字，相比 assign 有什么不同？
    1.1 在arc下，可能会出现循环引用的时候，使用该关键字，比如 delegate  block
    不同点：weak 表示弱引用，一种非拥有关系，为这种属性设置新值时，既不保留新值，也不释放旧值，这点与 assgin类似，
           weak所指向的对象被销毁时，weak属性会被置为nil
           weak必须用于oc对象，assign 则不然。
 2. 怎么使用copy关键字
    2.1 copy表示的所属关系与strong类似，不同点在于copy并不保留新值，而是将其拷贝。
    2.2 NSString NSArry NSDictionry等经常使用copy关键字，是因为父类指针可以指向子类对象，并且他们都有对应的可变类型 NSMutableString NSMutableArry NSMutableDictionry
    2.2 block 也经常使用copy关键字  在mrc下，block是存放在栈区的，使用copy可以把他存放在堆区，arc下，编译器会自动对block进行copy操作，arc下对于block使用copy还是strong效果都是一样的。
 3. @property (copy) NSMutableArray *array; 这种写法会出什么问题。
    3.1 添加，删除，或者修改数组内的元素时候，程序会因为找不到对应的方法而奔溃，copy就是复制一个不可变的NSArray对象
    3.2 使用了atomic 会影响性能 ,默认是atomic
    @property (nonatomic, copy) NSMutableArray *mutableArray;
    NSMutableArray *array = [NSMutableArray arrayWithObjects:@1,@2,nil];
    self.mutableArray = array;
    [self.mutableArray removeObjectAtIndex:0];
 4. 如何让自定义类使用copy修饰符？ 如何冲洗带copy关键字的setter？
    
 */