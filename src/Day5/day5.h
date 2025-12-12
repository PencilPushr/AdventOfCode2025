#pragma once

#include "common.h"

namespace d5
{

	inline 
	uint64_t
	Run()
	{
		std::ifstream fFile = ReadFile( "input_d5.txt" );

		std::vector<std::pair<uint64_t, uint64_t>> vIntervals;
		std::vector<uint64_t> vValidIDs;

		std::string sLine;

		uint64_t iMin, iMax;
		char cDash;
		while ( std::getline( fFile, sLine ) )
		{
			// Terminating condition
			if ( sLine.empty() )
				break;

			std::stringstream ssCurLine( sLine );
			if ( ssCurLine >> iMin >> cDash >> iMax )
			{
				std::cout << "iMin " << iMin
					<< "iMax " << iMax
					<< "\n";

				vIntervals.emplace_back( iMin, iMax );
			}
		}

#ifdef SOL1

		uint64_t iID;
		//size_t szValidIDs;
		while ( fFile >> iID )
		{
			for ( int i = 0; i < vIntervals.size(); i++ )
			{
				if ( vIntervals[ i ].first <= iID && iID <= vIntervals[ i ].second )
				{
					std::cout << "Valid id: " << iID << std::endl;
					vValidIDs.push_back( iID );
					break;
				}
			}
		}


		return vValidIDs.size();
#else

		if ( vIntervals.empty() )
			return -1;

		// Sort intervals, using the left
		std::sort( 
			vIntervals.begin(), 
			vIntervals.end(),
			[]( const auto & a, const auto & b ) {
				return a.first < b.first;
			} );

		uint64_t iTotalFresh = 0;

		/*
		Sorted intervals:
		    [  3 ---  5 ]
		           [  4 --------  9 ]
		                         [  7 -------- 12 ]
		                                         [ 14 --- 17 ]
		*/

		uint64_t iCurL = vIntervals[ 0 ].first;
		uint64_t iCurR = vIntervals[ 0 ].second;

		for ( int i = 1; i < vIntervals.size() - 1; i++ )
		{
			uint64_t iNextL = vIntervals[ i ].first;
			uint64_t iNextR = vIntervals[ i ].second;

			if ( iNextL <= iCurR)
			{
				// if ( iCurR < iNextR ) avoid the condition like:
				// [ 3 --- 9 ] [ 4 --- 8 ] where iCur:9 >= iNextL:4 but do not set iCur to a smaller value.
				iCurR = std::max(iCurR, iNextR);
			}
			else
			{
				iTotalFresh += ( iCurR - iCurL ) + 1;
				iCurL = iNextL;
				iCurR = iNextR;
			}
		}

		return iTotalFresh;
#endif
	}
}