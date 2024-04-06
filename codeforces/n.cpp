#include <bits/stdc++.h>
using namespace std;

// Find the next greater element for every element in an array
vector<int> findNextGreaterElements(vector<int>  &input)
{
    int n = input.size();
    vector<int> result(n, -1);

    // create an empty stack
    stack<int> s;
    reverse(input.begin(), input.end());

    // do for each element
    for (int i = 0; i < n; i++)
    {
        // loop till we have a greater element on top or stack becomes empty.

        // Keep popping elements from the stack smaller than the current
        // element, and set their next greater element to the current element

        while (!s.empty() && input[s.top()] < input[i])
        {
            result[s.top()] = n-i-1;
            s.pop();
        }

        // push current "index" into the stack
        s.push(i);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int a[] = {2, 7, 3, 5, 4, 6, 8,9};
    int *p = a;
    cout << sizeof(p);

    return 0;
}