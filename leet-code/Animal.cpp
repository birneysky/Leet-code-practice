//
//  Animal.cpp
//  LeetCode
//
//  Created by birneysky on 16/4/30.
//  Copyright © 2016年 birneysky. All rights reserved.
//

#include "Animal.hpp"

Animal::Animal()
{
	cout << "Animal Create" << endl;
}

Animal::~Animal()
{
	cout << "~ Animal" << endl;
}

void Animal::show( bool bNewLine)
{
	cout << "Animal :: show " << bNewLine << endl;
}
