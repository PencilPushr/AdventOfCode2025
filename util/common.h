#pragma once

#include <vector>
#include <tuple>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_set>

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
