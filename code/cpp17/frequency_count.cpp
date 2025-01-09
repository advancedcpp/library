#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main()
{
    std::string text = "hello world hello you are a man.";
    std::map<std::string, int> wordCount;
    std::stringstream ss(text);
    std::string word;

    while (ss >> word)
    {
        /* code */

        wordCount[word]++;
    }

    for (const auto &entry : wordCount)
        std::cout << entry.first << ":" << entry.second << std::endl;

    return 0;
}