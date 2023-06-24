#include "findUrls.hpp"
#include <algorithm>
#include <cctype>

namespace
{
bool isUrlChar(char c)
{
    static const std::string allowedChars = "!;/?:@=&$-_+!'(),.";
    return std::isalnum(c) || std::find(allowedChars.cbegin(), allowedChars.cend(), c) != allowedChars.cend();

}

std::string::const_iterator urlBeg(std::string::const_iterator b, std::string::const_iterator e)
{
    static const std::string separator = "://";

    std::string::const_iterator foundSeparator = b;
    while ((foundSeparator = std::search(foundSeparator, e, separator.cbegin(), separator.cend())) != e)
    {
        if (foundSeparator != b && (foundSeparator + separator.size()) != e)
        {
            auto beg = foundSeparator;
            while (beg != b && std::isalpha(beg[-1]))
            {
                --beg;
            }
            if (beg != foundSeparator && isUrlChar(foundSeparator[separator.size()]))
            {
                return beg;
            }

        }
        foundSeparator += separator.size();
    }
    return e;
}

std::string::const_iterator urlEnd(std::string::const_iterator b, std::string::const_iterator e)
{
    return std::find_if(b, e, [](const auto c) { return !isUrlChar(c); });
}
}

std::vector<std::string> findUrls(const std::string& str)
{
    std::vector<std::string> ret;

    auto b = str.cbegin();
    while (b != str.cend())
    {
        b = urlBeg(b, str.cend());

        if (b != str.cend())
        {
            const auto after = urlEnd(b, str.cend());
            ret.push_back(std::string(b, after));
            b = after;
        }
    }
    return ret;
}
