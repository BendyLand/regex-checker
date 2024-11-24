#include "matcher.hpp"
#include "utils.hpp" // iostream, vector
#include "generator.hpp"

void match();
void gen();

int main(int argc, char** argv)
{
	if (argc <= 1) {
		Usage:
		print_usage();
		exit(EXIT_FAILURE);
	}
	std::string mode = argv[1];
	if (mode != "match" && mode != "gen") goto Usage; // above
	if (mode == "match") match();
	else gen();
}

void match()
{
	std::string pattern = get_pattern();
	std::string token_str = get_tokens_string();
	Matcher matcher(pattern);
	std::vector<std::string> tokens = split(token_str, " ");
	matcher.find_token_matches(tokens);
	matcher.print_token_matches();
}

void gen()
{
	std::cout << "Welcome to generator mode!"; 
	std::string token_str = get_tokens_string();
	Generator gen(token_str);
	std::string pattern = gen.generate();
	std::cout << "Pattern:\n" << pattern << std::endl;
}