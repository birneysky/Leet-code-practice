//
//  Bird.hpp
//  LeetCode
//
//  Created by birneysky on 16/4/30.
//  Copyright © 2016年 birneysky. All rights reserved.
//

#ifndef Bird_hpp
#define Bird_hpp

#include "Animal.hpp"

class Bird : public Animal {

public:
	Bird();
	~Bird();
	void show();
	void show(bool bNewLine);
};


#endif /* Bird_hpp */
