#include "common.h"

namespace d1 {

	constexpr int MIN = 0;
	constexpr int MAX = 99;

	inline int g_iResult = 0;

	inline 
	int
	IndexLoop(int iPos, int iMove)
	{
			// (cur_pos + (wrapped_move) + to_makePositive) % to_reWrap
		return (iPos	+ ( iMove % 100 ) +       100	  )	% 100;
	}

	inline
	int 
	Run()
	{
		const char* pFilename = "input.txt";
		std::ifstream fFile(pFilename);
		if (!fFile)
		{
			std::cerr << "Failed to open " << pFilename << "\n";
			return -1;
		}

		int iPos = 50;
		int iCount = 0; // Part 2: How many times we wrap around

		char cDir;			// direction is 'L' or 'R'
		int iDist;			// distance is already parsed as int
		while (fFile >> cDir >> iDist)
		{
			if (cDir == 'L')
			{
				// LEFT: how many times we pass through 0
				if (iPos == 0)
					g_iResult += iDist / 100;
				else
					g_iResult += (iDist - iPos + 100) / 100;

				iPos = IndexLoop(iPos, -iDist);
			}
			else if (cDir == 'R')
			{
				// RIGHT: how many times we wrap past 99 -> 0
				g_iResult += (iPos + iDist) / 100;
				iPos = IndexLoop(iPos, iDist);
			}
			else
				return -1;
		}

		return g_iResult;
	}

}