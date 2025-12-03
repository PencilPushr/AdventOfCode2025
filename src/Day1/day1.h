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

		char cDir;			// direction is 'L' or 'R'
		int iDist;			// distance is already parsed as int
		while (fFile >> cDir >> iDist)
		{
			if ( cDir == 'L' )
			{
				iPos = IndexLoop(iPos, -iDist);
			}
			else if ( cDir == 'R' )
			{
				iPos = IndexLoop(iPos, iDist);
			}
			else 
				return -1;

			if (iPos == 0) g_iResult++;
		}

		return g_iResult;
	}

}