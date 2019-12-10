#include <bits/stdc++.h>
#include <iterator>

using namespace std;

template <typename I>
void merge(I begin, I midPoint, I end)
{
    typedef vector<typename iterator_traits<I>::value_type> TmpVec;

    TmpVec tmp(make_move_iterator(begin), make_move_iterator(end));

    typename TmpVec::iterator beginAlt = std::begin(tmp);
    typename TmpVec::iterator endAlt = std::end(tmp);
    typename TmpVec::iterator midAlt = next(beginAlt, distance(begin, midPoint));

    typename TmpVec::iterator l = beginAlt;
    typename TmpVec::iterator r = midAlt;
    I i = begin;

    while (l < midAlt && r < endAlt)
    {
        *i = move((*l < *r) ? *l++ : *r++);
        ++i;
    }

    while (l < midAlt)
    {
        *i = move(*l++);
        ++i;
    }

    while (r < endAlt)
    {
        *i = move(*r++);
        ++i;
    }
}

template <typename I>
void merge_sort(I begin, I end)
{
    size_t length = distance(begin, end);
    if (length <= 1)
        return;

    size_t mid = length / 2;
    I midPoint = next(begin, mid);

    merge_sort(begin, midPoint);
    merge_sort(midPoint, end);
    merge(begin, midPoint, end);
}

int main()
{
    vector<int> data{{5, 12, 45, 2, 67, 8}};
    merge_sort(begin(data), end(data));

    copy(begin(data), end(data), ostream_iterator<int>(cout, " "));
    cout << "\n";
}