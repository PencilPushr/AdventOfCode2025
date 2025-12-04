#pragma once

#include "common.h"

namespace d3 {

	inline uint64_t g_uResult = 0;

	inline
	uint64_t
	GetJoltageForCurrentLine( const std::string& sLine )
	{
		int iTens = 0;
		int iDigits = 0;
		int iTensPos = 0;

		// Find out the tens -> go to (end - 1) => (Edge case: 81119) We should not select 9 as our tens, we won't be able to choose a digit.
		for ( int i = 0; i < sLine.size() - 1; i++ )
		{
			int iCur = sLine[ i ] - '0';
			if ( iCur > iTens ) 
			{
				iTens = iCur;
				iTensPos = i;      
			}
		}

		// Find digit AFTER (+ 1) from the tens pos
		for ( int i = iTensPos + 1; i < sLine.size(); i++ )
		{
			iDigits = std::max( iDigits , sLine[ i ] - '0' );
		}

		// [ 9 , 8 ] :: 9 * 10 = 90 :: 90 + 8 = 98
		int iJolt = ( iTens * 10 ) + iDigits;
		
		return iJolt;
	}

	inline 
	int
	Run()
	{
		const char * pFilename = "input_d3.txt";
		std::ifstream fFile { pFilename };
		if ( !fFile )
		{
			std::cerr << "Failed to open " << pFilename << "\n";
			return -1;
		}

		std::string sLine;
		while ( std::getline( fFile , sLine ) )
		{
			// sLine should now contain something like: "22322122122122222112212311..."

			g_uResult += GetJoltageForCurrentLine( sLine );
		}

		return g_uResult;
	}
}