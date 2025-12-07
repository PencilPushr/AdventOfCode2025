#pragma once

#include "common.h"

//#define SOL1

namespace d4 {

	// Will no longer be using a global result -> it has been moved into Run()
	inline
	std::vector<std::pair<int , int>>
	RollsAffected(std::vector<std::string>& vGrid)
	{

		std::vector<std::pair<int , int>> vCoords;

	    /*
		* 
		* Check the neighbours
		* (-1,-1)    (-1,0)    (-1,1)
		* (0,-1)   ( i , j )   (0,1)
		* (1,-1)     (1,0)     (1,1)
		*
		*/

		int iRows = vGrid.size();
		int iCols = vGrid[ 0 ].size();

		// 8 directions: up, down, left, right, and 4 diagonals
		int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
		int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

		for ( size_t i = 0; i < iRows; i++ )
		{
			for ( size_t j = 0; j < iCols; j++ )
			{
				if ( vGrid[ i ][ j ] != '@' )
					continue;

				int iNeighbours = 0;
				int ni;
				int nj;
				for ( size_t k = 0; k < 8; k++ )
				{
					ni = i + dx[ k ];
					nj = j + dy[ k ];

					if ( ni < 0 || ni >= iRows || nj < 0 || nj >= iCols )
						continue;

					if ( vGrid[ ni ][ nj ] == '@' )
						iNeighbours++;
				}

				if ( iNeighbours < 4 )
					vCoords.push_back( std::make_pair( ni , nj ) );
			}
		}
	}

	inline
	int
	Run()
	{
		int iResult = 0;

		const char * pFilename = "input_d4.txt";
		std::ifstream fFile{ pFilename };
		if ( !fFile )
		{
			std::cerr << "Failed to open file " << pFilename << "\n";
			return -1;
		}

		// Store the contents we can iterate
		std::vector<std::string> vGrid;
		std::string sLine;
		while ( std::getline( fFile , sLine ) )
		{
			vGrid.push_back( sLine );
		}

#ifdef SOL1

		/*
		*
		* Check the neighbours
		* (-1,-1)    (-1,0)    (-1,1)
		* (0,-1)   ( i , j )   (0,1)
		* (1,-1)     (1,0)     (1,1)
		*
		*/

		int iRows = vGrid.size();
		int iCols = vGrid[ 0 ].size();

		// 8 directions: up, down, left, right, and 4 diagonals
		int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
		int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

		for ( size_t i = 0; i < iRows; i++ )
		{
			for ( size_t j = 0; j < iCols; j++ )
			{
				if ( vGrid[ i ][ j ] != '@' )
					continue;

				int iNeighbours = 0;
				int ni;
				int nj;
				for ( size_t k = 0; k < 8; k++ )
				{
					ni = i + dx[ k ];
					nj = j + dy[ k ];

					if ( ni < 0 || ni >= iRows || nj < 0 || nj >= iCols )
						continue;

					if ( vGrid[ ni ][ nj ] == '@' )
						iNeighbours++;
				}

				if ( iNeighbours < 4 )
					iResult++;
			}
		}
#else

		std::vector<std::pair<int , int>> vCoords;

		bool bCanRemove = true;
		while ( bCanRemove )
		{


		}

#endif

		return iResult;

	}
}