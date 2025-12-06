// AdventOfCode2025.cpp : Defines the entry point for the application.
//

#include "Day1/day1.h"
#include "Day2/day2.h"
#include "Day3/day3.h"
#include "Day4/day4.h"

int main()
{
	//printf("%llu", d2::Run());

	// printf was replaced in favour of std::cout as it automatically handles what the return type and print value should be
	// Which is annoying as I much prefer the syntax and C-style of printf()
	std::cout << d4::Run();
	return 0;
}
