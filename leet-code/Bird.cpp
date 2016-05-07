//
//  Bird.cpp
//  LeetCode
//
//  Created by birneysky on 16/4/30.
//  Copyright © 2016年 birneysky. All rights reserved.
//

#include "Bird.hpp"

Bird::Bird()
{
	cout << "Bird Create" << endl;
}

Bird::~Bird()
{
	cout << "~ Bird" << endl;
}

void Bird::show()
{
	cout << "Bird::show" << endl;
}


void Bird::show(bool bNewLine)
{
    Animal::show(bNewLine);
}
