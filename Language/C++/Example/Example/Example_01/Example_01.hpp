//
//  Example_01.hpp
//  Example
//
//  Created by 이상동 on 2021/03/20.
//

#ifndef Example_01_hpp
#define Example_01_hpp

#include "../Global/Define/KGDefine.hpp"

/*
 네임 스페이스란?
 :
 - C++ 언어는 식별자를 지니는 공간을 선언하는 것이 가능하며, 이 기능을 네임 스페이스라고 한다.
 (즉, 네임 스페이스를 사용하면 이름을 지닌 영역 (공간) 을 선언하는 것이 가능하며, 해당 영역 하위에는 변수 및 함수 등을
 선언 및 구현하는 것이 가능하다.)
 
 또한, 네임 스페이스로 선언 된 공간은 해당 공간을 식별 할 수 있는 이름을 지니고 있기 때문에 필요에 따라 :: (멤버 지정 연산자)
 를 사용해서 언제든지 해당 공간에 접근하는 것이 가능하다.
 */
namespace E01 {
	//! Example 1
	void Example_01(const int argc, const char **args);
}

#endif /* Example_01_hpp */
