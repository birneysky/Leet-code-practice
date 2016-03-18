//
//  interviews.h
//  leet-code
//
//  Created by zhangguang on 16/3/18.
//  Copyright © 2016年 com.github. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface interviews : NSObject <NSCopying,NSMutableCopying>

@property (nonatomic,strong) NSSet* set;

@end


/*
 
 0.什么情况使用 weak 关键字，相比 assign 有什么不同？
    0.1 在arc下，可能会出现循环引用的时候，使用该关键字，比如 delegate  block
    不同点：weak 表示弱引用，一种非拥有关系，为这种属性设置新值时，既不保留新值，也不释放旧值，这点与 assgin类似，
           weak所指向的对象被销毁时，weak属性会被置为nil
           weak必须用于oc对象，assign 则不然。
 1. 对象的拷贝
    对象的拷贝有两种方式：浅拷贝和深拷贝。浅拷贝，并不是拷贝对象的内容，而是简单的复制对象的指针值，深拷贝是拷贝对象在内存中的内容，拷贝到另一块内存中
    1.1 集合的浅复制(shawllow copy)
        集合浅复制有很多方法
            NSArray* shawllowCopyArray = [someArray copyWithZone:nil];
            NSSet* shawllowCopySet = [someSet mutableCopyWithZone:nil];
            NSDictionary* shawllowCopyDict = [NSDictionary alloc] initWithDictionary:someDictionary copyItems:NO];
    1.2 集合的深复制
        集合深复制有两种方法
        1.2.1  NSDictionary* shawllowCopyDict = [NSDictionary alloc] initWithDictionary:someDictionary copyItems:YES];
               如果使用这种方式深复制，集合里的每一个对象都会受到copyWithZone 消息，如果集合中对象都遵循“NSCopying”协议，那么对象会被深复制到新的集合，如果没用，程序奔溃
        1.2.2 将集合进行归档(archive)，然后解档(unarchive)
                NSArray *trueDeepCopyArray = [NSKeyedUnarchiver unarchiveObjectWithData:[NSKeyedArchiver archivedDataWithRootObject:oldArray]];
    1.3 系统对象的copy和mutableCopy方法
        1.3.1 不管是集合类对象还是非集合类对象，接受到copy和mutableCopy消息时，都遵循以下准则：
              copy方法返回非mutable对象，所以如何copy返回值使用mutable对象接口，程序就会奔溃
              mutableCopy方法返回mutable对象
    1.4 非集合类对象的copy和mutableCopy
        1.4.1 系统非集合类对象指的是NSString，NSNumber..之类的对象。非集合类非mutable对象拷贝的例子：
                NSString *string = @"origin";
                NSString *stringCopy = [string copy];
                NSMutableString *stringMCopy = [string mutableCopy];
            string 和 stringCopy的地址相同，进行了指针拷贝，stringMCopy和string不一样，进行了内容拷贝
        1.4.2 mutable对象拷贝的例子
                     NSMutableString *string = [NSMutableString stringWithString: @"origin"];
                     //copy
                     NSString *stringCopy = [string copy];
                     NSMutableString *mStringCopy = [string copy];
                     NSMutableString *stringMCopy = [string mutableCopy];
                     //change value
                     [mStringCopy appendString:@"mm"]; //crash
                     [string appendString:@" origion!"];
                     [stringMCopy appendString:@"!!"];
    1.5 集合类对象的copy与mutableCopy
            1.5.1 集合类对象是指NSArray、NSDictionary、NSSet ... 之类的对象。下面先看集合类immutable对象使用copy和mutableCopy的一个例子：
             
                 NSArray *array = @[@[@"a", @"b"], @[@"c", @"d"];
                 NSArray *copyArray = [array copy];
                 NSMutableArray *mCopyArray = [array mutableCopy];
             查看内容，可以看到copyArray和array的地址是一样的，而mCopyArray和array的地址是不同的。说明copy操作进行了指针拷贝，mutableCopy进行了内容拷贝。但需要强调的是：此处的内容拷贝，仅仅是拷贝array这个对象，array集合内部的元素仍然是指针拷贝。这和上面的非集合immutable对象的拷贝还是挺相似的，那么mutable对象的拷贝会不会类似呢？我们继续往下，看mutable对象拷贝的例子：
             
                 NSMutableArray *array = [NSMutableArray arrayWithObjects:[NSMutableString stringWithString:@"a"],@"b",@"c",nil];
                 NSArray *copyArray = [array copy];
                 NSMutableArray *mCopyArray = [array mutableCopy];
             查看内存，如我们所料，copyArray、mCopyArray和array的内存地址都不一样，说明copyArray、mCopyArray都对array进行了内容拷贝。同样，我们可以得出结论：
             
             在集合类对象中，对immutable对象进行copy，是指针复制，mutableCopy是内容复制；对mutable对象进行copy和mutableCopy都是内容复制。但是：集合对象的内容复制仅限于对象本身，对象元素仍然是指针复制。用代码简单表示如下：
             
                 [immutableObject copy] // 浅复制
                 [immutableObject mutableCopy] //单层深复制
                 [mutableObject copy] //单层深复制
                 [mutableObject mutableCopy] //单层深复制
             这个代码结论和非集合类的非常相似。
 
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
    4.1 如果想让自己的类具有拷贝功能，则需要实现NSCopying协议，该协议只有一个方法- (id)copyWithZone:(NSZone *)zone;
 */