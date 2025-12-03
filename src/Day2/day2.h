#pragma once

#include "common.h"

namespace d2 {

	int g_iResult = 0;

	inline
	bool
	CheckRangeForInvalidIDs(
		int iMin,
		int iMax
	)
	{
		// 1. Iterate over the range, from min to max
		for (int i = iMin; i < iMax; i++)
		{
			// 2. break apart the current number into an array, perform two pointer comparison
			
			std::string sArr = std::to_string(i);

			if (sArr.size() % 2 != 0)
			{
				std::cerr << "Array size was not even digit, it cannot be split into 2";
				return false;
			}

			int iMid = sArr.size() / 2;
			for (int a = 0; a < iMid; a++)
			{
				if (sArr[a] != sArr[a + iMid]) break;
			}

			// 3. if the current number IS palindromic -> add it to g_iResult;
		}
	}

	inline
	int
	Run()
	{
		const char * pFilename = "input_d2.txt";
		std::ifstream fFile{ pFilename };
		if ( !fFile )
		{
			std::cerr << "Failed to open " << pFilename << "\n";
			return -1;
		}

		std::string sLine;
		if ( !std::getline(fFile, sLine) )
		{
			std::cerr << "File is empty or could not read line\n";
			return -1;
		}

		std::stringstream ssLine(sLine);
		std::string sRange;

		while (std::getline(ssLine, sRange, ','))  // Extract each range, split by comma
		{
			// sRange should contain "12077-25471"
			std::stringstream ssRange(sRange);

			int iMin, iMax;
			char cDash;

			ssRange >> iMin >> cDash >> iMax;

			if (!CheckRangeForInvalidIDs(iMin, iMax)) break;

		}
	}

}