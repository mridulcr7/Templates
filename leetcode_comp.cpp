//os
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//1.for repeated values use pair
//2.lower_bound will return smallest index(if multiple answer if possible)
//3.store negative values if we want to reverse the function of both lower and upper bound
//4.end(a) in case no possible anser
//sortbycol
bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[1] < v2[1];
}

bool comp2(const pair<int,int> &v1, const pair<int,int> &v2)
{
    // if (v1.second != v2.second)
    //     return v1.second > v2.second;
    if (v1.first != v2.first)
        return v1.first < v2.first;
    return v1.second < v2.second;
}