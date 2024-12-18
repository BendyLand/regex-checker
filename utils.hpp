#pragma once

#include <iostream>
#include <vector>

template <typename T>
inline std::ostream& operator<<(std::ostream& os, std::vector<T> vec)
{
	size_t length = vec.size();
	for (size_t i = 0; i < length; i++) {
		if (i < length - 1) std::cout << vec[i] << ", ";
		else std::cout << vec[i]; 
	}
	return os;
}

std::vector<std::string> args_to_vec(int argc, char** argv);
void print_usage();
size_t count(std::string str, char target);
std::vector<std::string> split(std::string full, std::string delim);
std::string get_tokens_string();
