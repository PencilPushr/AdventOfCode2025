#pragma once

#include <vector>
#include <tuple>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>

#ifdef WTYPES

#define INLINE inline

using INT = int;
using UINT = unsigned int;

using BYTE = unsigned char;
using WORD = unsigned short;
using DWORD = unsigned long;
using QWORD = unsigned long long;

using BOOL = int;
using CHAR = char;
using WCHAR = wchar_t;

using HANDLE = void*;
using VOID = void;

#endif


inline
std::ifstream
ReadFile(
    const char* pFilename
)
{
    std::ifstream fFile{ pFilename };
    if ( !fFile )
    {
        std::cerr << "Failed to read " << pFilename << "\n";
    }

    return fFile;  // returned by value (moved)
}

inline
std::vector<std::string>
ReadLines(
    std::ifstream& fFile
)
{
    std::vector<std::string> vLines;

    std::string sLine;
    while ( std::getline( fFile , sLine ) )
    {
        vLines.push_back( sLine );
    }

    return vLines; 
}
