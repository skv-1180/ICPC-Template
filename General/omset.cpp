#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using omultiset = tree<T, null_type, less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

/*
oset<int> s;//same element not considered
omultiset<int> ms;//we can use int || pair<int,int>
s.insert(x);
*s.find_by_order(x)//x th element of in a set counting from zero
s.order_of_key(x)//no of items smaller than x
*/