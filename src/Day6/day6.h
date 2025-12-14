#pragma once

#include "common.h"

namespace d6 {

	inline
	int
	Run()
	{
		std::ifstream fFile = ReadFile( "input_d6.txt" );

		/*
		
			123 328   51  64 \n
			 45  64  387  23 \n
			 6   98  215 314 \n
			 *   +   *   +   EOF

		*/

		// 1) Gather number of colums (iterate till first \n)
		//		This will let us set iCols and thus we can % the distance from the start of the line to \n
		// 

		int iCols;
		int temp;
		while ( fFile >> temp && fFile.peek() != '\n' )
		{
			iCols++;
		}

	}
}