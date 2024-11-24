#include "generator.hpp"

std::string Generator::generate()
{
    std::string result = "";
    Style check = this->check_for_consistent_chars();
    switch (check) {
    case Style::ALPHABETIC:
        result = "[a-zA-Z]+";
        break;
    case Style::NUMERIC:
        result = "\\d+";
        break;
    case Style::ALPHANUMERIC:
        result = "[a-zA-Z0-9]+";
        break;
    case Style::NONE:
        result = ""; //todo: create functions to figure it out from here
        break;
    }
    return result;
}

Style Generator::check_for_consistent_chars()
{
    size_t alphas = 0;
    size_t nums = 0;
    size_t alnums = 0;
    for (std::string token : this->m_tokens) {
        bool alpha = this->is_all_alphabetic(token);
        bool num = this->is_all_numeric(token);
        bool alnum = this->is_all_alphanumeric(token);
        if (alpha) alphas++;
        else if (num) nums++;
        else if (alnum) alnums++;
    }
    if (alphas == 0 && alnums == 0 && nums > 0) return Style::NUMERIC;
    else if (nums == 0 && alnums == 0 && alphas > 0) return Style::ALPHABETIC;
    else if (alnums > 0) return Style::ALPHANUMERIC;
    else return Style::NONE;
}

bool Generator::is_all_alphabetic(const std::string& token)
{
    for (char c : token) {
        if (!isalpha(c)) return false;
    }
    return true;
}

bool Generator::is_all_numeric(const std::string& token)
{
    for (char c : token) {
        if (!isnumber(c)) return false;
    }
    return true;
}

bool Generator::is_all_alphanumeric(const std::string& token)
{
    for (char c : token) {
        if (!isalnum(c)) return false;
    }
    return true;
}