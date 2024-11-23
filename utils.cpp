#include "utils.hpp"

std::vector<std::string> args_to_vec(int argc, char** argv)
{
	std::vector<std::string> result;
	result.reserve(argc);
	for (int i = 0; i < argc; i++) {
		result.emplace_back(argv[i]);
	}
	return result;
}

void print_usage()
{
	std::cout << "Usage: regex-check <mode>" << std::endl;
	std::cout << "Modes: match, gen" << std::endl;
}

size_t count(std::string str, char target)
{
	size_t result = 0;
	for (char c : str) {
		if (c == target) result++;
	}
	return result;
}

std::vector<std::string> split(std::string full, std::string delim)
{
	std::vector<std::string> result;
	result.reserve(count(full, ' ') + 1);
	std::string token;
	while (full.find(delim) != std::string::npos) {
		token = full.substr(0, full.find(delim));
		result.emplace_back(token);
		full.erase(0, full.find(delim) + 1);
	}
	result.emplace_back(full);
	return result;
}

std::string get_pattern()
{
	std::cout << \
	"Welcome to match mode!\n" << \
	"Please enter the regex pattern you would like to check against:" << std::endl;
	std::string pattern;
	std::getline(std::cin, pattern);
	return pattern;
}

std::string get_list_of_tokens()
{
	std::cout << std::endl << \
	"Now please enter a list of strings to check, separated by spaces:" << std::endl;
	std::string tokens;
	std::getline(std::cin, tokens);
	return tokens;
}