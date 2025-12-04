#pragma once

#include "common.h"

namespace d2 {

	inline uint64_t g_iResult = 0;

	inline
	void
	CheckRangeForInvalidIDs(
		uint64_t iMin,
		uint64_t iMax
	)
	{
		for ( uint64_t i = iMin; i <= iMax; i++ )
		{
			std::string sArr = std::to_string( i );
			int length = sArr.size();
			bool bIsInvalid = false;

			// Try all possible pattern lengths
			for ( int patternLength = 1; patternLength <= length / 2; patternLength++ )
			{
				// Pattern must divide evenly into the total length
				if ( length % patternLength != 0 )
					continue;

				// Check if this pattern repeats throughout
				bool bIsRepeating = true;
				for ( int j = 0; j < length; j++ )
				{
					if (sArr[ j ] != sArr[ j % patternLength ])
					{
						bIsRepeating = false;
						break;
					}
				}

				if ( bIsRepeating )
				{
					bIsInvalid = true;
					break;  // Found a repeating pattern, no need to check more
				}
			}

			if ( bIsInvalid )
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