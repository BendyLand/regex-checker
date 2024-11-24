#pragma once

#include "utils.hpp"

enum class Style 
{
    ALPHABETIC,
    NUMERIC,
    ALPHANUMERIC,
    NONE,
};

inline std::ostream& operator<<(std::ostream& os, Style style)
{
	switch (style) {
    case Style::ALPHABETIC:
        std::cout << "alphabetic";
        break;
    case Style::NUMERIC:
        std::cout << "numeric";
        break;
    case Style::ALPHANUMERIC:
        std::cout << "alphanumeric";
        break;
    default:
        std::cout << "none";
        break;
    }
	return os;
}

class Generator 
{
public:
    Generator(std::string tokens)
        : m_tokens(split(tokens, " "))
    {}
    std::string generate();
    Style check_for_consistent_chars();

private:
    std::vector<std::string> m_tokens;
    bool is_all_alphabetic(const std::string& token);
    bool is_all_alphanumeric(const std::string& token);
    bool is_all_numeric(const std::string& token);
};