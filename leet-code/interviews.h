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
 5. @property 的本质是什么？实例变量和读写方法是如何被添加到这个类中的？
    property 的本质就是实例变量和存取方法。
    property的主要作用是封装对象中的数据。oc通常会把其所需要的数据保存为各种实例变量。实例变量一般通过存取方法来访问。
    完成属性定义后，编译器会自动编写访问这些属性所需的方法。这个过程是由编译器在编译期执行。
    除了生成存取方法之外，编译器还要向类中添加适当类型的实例变量，并且在属性前面加下划线，以此作为实例变量的名字。
         1.OBJC_IVAR_$类名$属性名称 ：该属性的“偏移量” (offset)，这个偏移量是“硬编码” (hardcode)，表示该变量距离存放对象的内存区域的起始地址有多远。
         2.setter 与 getter 方法对应的实现函数
         3.ivar_list ：成员变量列表
         4.method_list ：方法列表
         5.prop_list ：属性列表
    每增加一个属性，系统都会在ivar_list添加一个成员变量的描述，在method_list增加setter/getter方法的描述，在属性列表中增加一个属性的描述，然后计算该属性的偏移量
    然后给出 setter 与 getter 方法对应的实现,在 setter 方法中从偏移量的位置开始赋值,在 getter 方法中从偏移量开始取值,为了能够读取正确字节数,系统对象偏移量的指针类型进行了类型强转.
 6. @protocol 和 category 中如何使用 @property
    6.1 如果在protocol使用属性只会生成setter和getter方法声明，是协议中使用属性的目的是希望遵守协议的对象能够实现该属性。
    6.2 category 也只会生成setter和getter方法声明，如果真的要给category增加属性的实现，需要借助于两个运行时函数
            objc_setAssociatedObject
            objc_getAssociatedObject
 7. runtime 如何实现weak属性？
 8. @property中有哪些属性关键字？/ @property 后面可以有哪些修饰符？
    8.1 原子性 nonatomic
    8.2 内存管理 strong weak copy assign
    8.3 读写权限 readwrite readonly
    8.4 方法名 getter=<name> setter=<name>  @property (nonatomic,assign,getter=isOn) BOOL On;
 9. @synthesize和@dynamic分别有什么作用？
    @synthesize 作用是如果没有写getter/setter，编译器会自动帮你加上这两个方法。如果 @synthesize和 @dynamic都没写，那么默认的就是@syntheszie var = _var;
    @dynamic 就是要告诉编译器，代码中用@dynamic修饰的属性，其getter和setter方法会在程序运行的时候或者用其他方式动态绑定，以便让编译器通过编译。其主要的作用就是用在NSManagerObject对象的属性声明上，由于此类对象的属性一般是从Core Data的属性中生成的，core data 框架会在程序运行的时候为此类属性生成getter和setter方法。 
 
 10. ARC下，不显式指定任何属性关键字时，默认的关键字都有哪些?
     基本类型默认关键字
        atomic assign readwrite
     oc对象默认关键字
        atomic strong  readwrite
 
 11. 用@property声明的NSString（或NSArray，NSDictionary）经常使用copy关键字，为什么？如果改用strong关键字，可能造成什么问题？
      11.1 由于父类指针可以指向子类对象，使用copy时为了让该属性不受外界影响，无论传入的是一个可变对象还是不可变对象，实例变量持有的都是一个不可变的副本。
      11.2 如果使用strong，那么该属性就有可能指向一个可变的对象，这样如果在外部修改了这个可变对象，就会影响属性的值
 12.@synthesize合成实例变量的规则是什么？假如property名为foo，存在一个名为_foo的实例变量，那么还会自动合成新变量么？
     12.1 @synthesize 规则
           12.1.1 如果是@synthesize foo = newName,会在生成一个newName的成员变量
           12.1.2 如果没有使用@synthesize，不会再生成新的成员变量
           12.1.3 如果是@synthesize foo = _foo; 不会再生成新的成员变量
           12.1.4 如果是@synthesize foo；会生成一个名称为foo的成员变量 （如果没有指定成员变量的名称会自动生成一个属性同名的成员变量,）
           12.1.5 如果没有使用@synthesize，并且类内部没有定义成员变量_foo，会自动东生成一个_foo成员变量
           12.1.6 当你同时重写了 setter 和 getter 时，系统就不会生成成员变量。这是你又两个选择： 1 手动创建成员变量 2 @synthesize foo = _foo；
 
 
 */