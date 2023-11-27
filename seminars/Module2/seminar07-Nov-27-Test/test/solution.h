#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <string>
#include <iostream>
#include <set>

class StringFinder
{
private:

    int curOccurrence; // HINT: Keep track of the index of the occurrence your finder is pointing at a given moment
    std::vector<std::pair<int, int>> occurrences;
    std::vector<std::string> lines;
    // What other fields you think you may need?

public:

    std::vector<int> calcLPS(const std::string& pattern)
    {
        std::vector<int> lps(pattern.size(), 0);
        for (int len = 0, i = 1; i < pattern.size();)
        {
            if (pattern[len] == pattern[i])
            {
                lps[i++] = ++len;
            }
            else
            {
                if (len == 0)
                {
                    lps[i++] = 0;
                }
                else
                {
                    len = lps[len - 1];
                }
            }
        }
        return lps;
    }

    void KMPSearch(const std::string& text, const std::string& pattern, int lineNumber)
    {
        std::vector<int> lps = calcLPS(pattern);
        for (int i = 0, j = 0; i < text.size();)
        {
            if (pattern[j] == text[i])
            {
                j++, i++;
            }
            if (j == pattern.size())
            {
                occurrences.push_back(std::make_pair(lineNumber, i - j));
                j = lps[j - 1];
            }
            else if (i < text.size() && pattern[j] != text[i])
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
    }


    /*****************************************************************************************************/
    /*** PROBLEM #1: Complete StringFinder constructor, next(), hasNext() and count() functions [5pts] ***/
    StringFinder(const std::string& text, const std::string& pattern)
    {
        // Split the text into lines
        size_t start = 0;
        size_t end;
        while ((end = text.find('\n', start)) != std::string::npos)
        {
            lines.push_back(text.substr(start, end - start));
            start = end + 1;
        }
        lines.push_back(text.substr(start)); // Add the last line

        // Find all occurrences of the pattern
        for (int line_idx = 0; line_idx < lines.size(); ++line_idx)
        {
            KMPSearch(lines[line_idx], pattern, line_idx);
        }
        curOccurrence = 0;
    }

    bool hasNext()
    {
        return curOccurrence < occurrences.size();
    }

    std::pair<int, int> next()
    {
        if (hasNext())
        {
            return occurrences[curOccurrence++];
        }
        return std::make_pair(-1, -1); // If there is no next occurrence
    }

    int count()
    {
        return occurrences.size();
    }


    /*****************************************************************************************************/
    /*********************** PROBLEM #2: Complete printLines() function [2pts] ***************************/

    void printLines()
    {
        std::set<int> alreadyPrinted; // To store lines i already printed
        for (const auto& occurrence: occurrences)
        {
            if (alreadyPrinted.find(occurrence.first) == alreadyPrinted.end()) // If line wasnt printed
            {
                std::cout << lines[occurrence.first] << std::endl;
                alreadyPrinted.insert(occurrence.first); // Add line to the alreadyPrinted to not print it again
            }
        }
    }


    /*****************************************************************************************************/
    /************* PROBLEM #3: Complete last(), hasPrevious() and previous() function [1pt] *************/

    void last()
    {
        curOccurrence = occurrences.size() - 1;
    }

    bool hasPrevious()
    {

        return curOccurrence > 0;
        // Complete code and change this return value
    }

    std::pair<int, int> previous()
    {
        std::pair<int, int> previousOccurrence; // line and position in the line of the previous occurrence


        return previousOccurrence;
    }

    /*****************************************************************************************************/
    /****** PROBLEM #4: Complete StringFinder constructor with caseSensitive boolean flag [2pts] **********/

    StringFinder(const std::string& text, const std::string& pattern, bool caseSensitive)
    {

    }
};

#endif