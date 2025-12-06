#pragma once

#include "common.h"

namespace d3 {

	inline uint64_t g_uResult = 0;

	inline
	uint64_t
	StringToUInt64( const std::string& s )
	{
		uint64_t iResult = 0;
		for ( char c : s )
		{
			iResult = iResult * 10 + ( c - '0' );
		}
		return iResult;
	}

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
	uint64_t
	GetJoltageForCurrentLine( const std::string & sLine , int iBatteries )
	{
		std::vector<int> vDigits( iBatteries, 0 );
		int iLargestPos = 0; // Start searching from the beginning

		// Which digit we are currently try to fill
		for ( size_t idx = 0; idx < iBatteries; idx++ )
		{
			// Find the largest digit in the valid range
			int iMaxDigit = -1;
			int iMaxPos = iLargestPos;

			// Go up to the remaining positions:
			size_t iSearchEnd = sLine.size() - ( iBatteries - idx );


			for ( size_t i = iLargestPos; i <= iSearchEnd; i++ )
			{
				int digit = sLine[ i ] - '0';
				if ( digit > iMaxDigit )
				{
					iMaxDigit = digit;
					iMaxPos = i;
				}
			}

			vDigits[ idx ] = iMaxDigit;
			iLargestPos = iMaxPos + 1; // Next search starts after this position
		}

		// Convert array into integer
		uint64_t iResult = 0;
		for ( int digit : vDigits )
		{
			iResult = iResult * 10 + digit;
		}

		return iResult;
	}

	inline
	uint64_t
	GetKLargest( const std::string & sLine , int iBatteries )
	{
		std::string sStack;
		int iToRemove = sLine.size() - iBatteries;

		for ( int i = 0; i < sLine.size(); i++ )
		{
			while ( !sStack.empty() && iToRemove > 0 && sStack.back() < sLine[ i ])
			{
				sStack.pop_back();
				iToRemove--;
			}

			sStack.push_back( sLine[ i ] );
		}

		// Remove any remaining from end
		while ( iToRemove > 0 )
		{
			sStack.pop_back();
			iToRemove--;
		}

		return StringToUInt64( sStack );
	}

	inline 
	uint64_t
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

			g_uResult += GetKLargest( sLine, 12 );
		}

		return g_uResult;
	}
}