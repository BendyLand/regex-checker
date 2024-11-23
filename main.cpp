#include "matcher.hpp"
#include "utils.hpp" // iostream, vector

void match();

int main(int argc, char** argv)
{
	if (argc > 1) {
		bool invalid_arg = argv[1] != std::string("match") && argv[1] != std::string("gen");
		if (invalid_arg) goto Usage;
		if (argv[1] == std::string("match")) match();
	}
	else {
		Usage:
		print_usage();
	}
}

void match()
{
	std::string pattern = get_pattern();
	std::string token_str = get_list_of_tokens();
	Matcher matcher(pattern);
	std::vector<std::string> tokens = split(token_str, " ");
	matcher.find_token_matches(tokens);
	matcher.print_token_matches();
}