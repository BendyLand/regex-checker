#pragma once

#include <regex>

class Matcher {
public: 
    Matcher(const std::string text) 
        : pattern(std::regex(text))
    {}
    void find_token_matches(const std::vector<std::string>& tokens);
    void print_token_matches();
private:
    // Fields
    std::regex pattern;
    std::vector<std::string> matches;
    std::vector<std::string> non_matches;
    // Methods
    bool is_match(const std::string& str);
};

