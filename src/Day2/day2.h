#pragma once

#include "common.h"

namespace d2 {

	uint64_t g_iResult = 0;

	inline
	void
	CheckRangeForInvalidIDs(
		uint64_t iMin,
		uint64_t iMax
	)
	{
		// 1. Iterate over the range, from min to max
		for (uint64_t i = iMin; i <= iMax; i++)
		{
			// 2. break apart the current number into an array, perform two pointer comparison
			
			std::string sArr = std::to_string(i);

			if (sArr.size() % 2 != 0)
				continue;

			int iMid = sArr.size() / 2;
			bool bIsInvalid = true;
			for (uint64_t j = 0; j < iMid; j++)
			{
				if (sArr[j] != sArr[j + iMid])
				{
					bIsInvalid = false;
					break;
				}
			}

			// 3. if the current number IS palindromic -> add it to g_iResult;
			if (bIsInvalid)
				g_iResult += i;
		}
	}

	inline
	uint64_t
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

			uint64_t iMin, iMax;
			char cDash;

			ssRange >> iMin >> cDash >> iMax;

			std::cout << "Range: " << iMin << " " << cDash << " " << iMax << "\n";

			CheckRangeForInvalidIDs(iMin, iMax);

		}

		return g_iResult;
	}

}