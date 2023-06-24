#pragma once
#include <iosfwd>
#include <map>
#include <string>
#include <vector>
#include "../../common/split.hpp"

std::map<std::string, std::vector<unsigned>> xref(std::istream& in, std::vector<std::string> findWords(const std::string&) = split);
