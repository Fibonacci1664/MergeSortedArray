#include<iostream>
#include <vector>
#include<algorithm>

void printVector(std::vector<int>& numVec)
{
    for (int i = 0; i < numVec.size(); ++i)
    {
        std::cout << "[ " << numVec[i] << " ], ";
    }
}

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    // Case:1 
    // Both vecs are empty
    if (nums1.empty() && nums2.empty())
    {
        // Do nothing
        return;
    }

    // Case:2
    // One vec is empty
    if (nums1.empty() || nums2.empty())
    {
        if (nums1.empty())
        {
            // Loop over nums2 and copy into nums1
            for (int i = 0; i < nums2.size(); ++i)
            {
                nums1.push_back(nums2[i]);
            }
        }
        else
        {
            // If nums2 is empty, do nothing
            printVector(nums1);
            return;
        }
    }

    int counter = nums2.size();

    // Case:3
    // Loop backwards over nums1 vec, removing the useless zeros
    for (int i = nums1.size() - 1; counter > 0; --i, --counter)
    {
        if (nums1[i] == 0)
        {
            nums1.pop_back();
        }
    }

    // Now copy everything from nums2 into nums1
    for (int i = 0; i < nums2.size(); ++i)
    {
        nums1.push_back(nums2[i]);
    }

    auto vecBegIt = nums1.begin();
    auto vecEndIt = nums1.end();

    // Sort nums1
    std::sort(vecBegIt, vecEndIt);

    printVector(nums1);
}

int main()
{
    // TEST CASES
    // TEST 1.
    std::vector<int> vec1 = { 1, 2, 3, 0, 0, 0 };
    std::vector<int> vec2 = { 2, 5, 6};

    // TEST 2.
    std::vector<int> vec3 = {1};
    std::vector<int> vec4 = {};

    // TEST 3.
    std::vector<int> vec5 = {0};
    std::vector<int> vec6 = {1};

    // TEST 4.
    std::vector<int> vec7 = { -1, 0, 0, 3, 3, 3, 0, 0, 0 };
    std::vector<int> vec8 = { 1, 2, 2 };

    merge(vec1, vec1.size(), vec2, vec2.size());

    return 0;
}