
namespace d1 {

#include <vector>
#include <tuple>

	inline int g_iResult;

	enum class Rotation
	{
		LEFT,
		RIGHT,
		UNK // failure - terminate if we encounter this value
	};

	int 
	main(
		std::vector<
			std::tuple<int, d1::Rotation>> vInput
	)

}