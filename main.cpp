#include <iostream>
#include <vector>
#include <map>

using Cache = std::map<std::pair<int,int>,bool>;

Cache cache;

bool partitioner(int target, std::vector<int>& v, int i, int accum)
{
    // Base case: i moved through all values or my accumulator passed the target?
    if (i == nums.size() || accum >= target)
        return accum == target; // Check if I made to the target

    // If I have already met this problem with {i,accum} then return it, don't go on recursion
    if (cache.find({i,accum}) != cache.end())
        return cache[{i,accum}];

    bool hasSolution = false;

    // Check if there is solution by adding v[i]
    if(partitioner(target, v, i + 1, accum + v[i]))
        hasSolution = true;
        // Check if there is solution by not adding v[i]
    else if(partitioner(target, v, i + 1, accum))
        hasSolution = true;


    cache[{i,accum}] = hasSolution; // save the solution I have just calculated.

    return hasSolution;
}

bool canPartition(std::vector<int>& v)
{
    int sum = calcSum(v);

    if (sum % 2 != 0)
        return false

    int target = sum / 2; // I need to pick elements from v that sum up to the targe

    return partitioner(target, v, 0, 0);
}
