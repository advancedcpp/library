#include <iostream>
#include <map>

int main()
{
    std::map<std::string, std::string> cache;
    cache["http://example.com"] = "<html>hello</html>";

    std::string url = "http://example.com";
    std::cout << "Cache for " << url << cache[url] << std::endl;
    return 0;
}