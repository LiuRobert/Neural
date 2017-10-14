#pragma once
#include <vector>

class Utils
{
public:
	
	template<typename T>
	static bool contains(const std::vector<T>& v, const T& value)
	{
		return std::find(v.begin(), v.end(), value) != v.end();
	}

private:
	Utils();
	~Utils();
};
