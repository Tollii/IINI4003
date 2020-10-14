#include "set.hpp"
#include <vector>
#include <algorithm>
#include <ostream>

Set::Set(const std::vector<int> &list) {
    set = {};

    for (int j : list) {
        bool unique = true;
        for (int i : set) {
            if (i == j) {
                unique = false;
                break;
            }
        }

        if (unique)
            set.emplace_back(j);
    }
}

Set::Set() = default;

Set &Set::operator+=(int num) {

    bool unique = true;
    for (int i : set) {
        if (i == num) {
            unique = false;
            break;
        }
    }

    if (unique)
        set.emplace_back(num);

    return *this;
}

Set &Set::operator+=(const Set &other) {
    set.reserve(set.size() + other.set.size());

    for (int i : other.set)
        *this += i;

    return *this;
}

Set Set::operator+(const Set &other) const {
    Set s = *this;
    s += other;
    return s;
}

bool Set::operator==(const Set &other) const {

    // If they have different sizes, they can't be equal
    if (set.size() != other.set.size())
        return false;

    for (int i : set) {
        bool found = false;
        for (int j : other.set) {
            if (i == j)
                found = true;
        }
        if (!found) {
            return false;
        }
    }

    return true;
}

bool Set::operator!=(const Set &other) const {
    return !(*this == other);
}

Set &Set::operator=(const Set &other) {

    // Handle self assignment
    if (this == &other)
        return *this;

    set.clear();
    set.reserve(other.set.size());

    for (int i : other.set)
        set.push_back(i);

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Set &s) {
    out << "{ ";
    for (int i : s.set) {
        out << i << ", ";
    }
    out << "}";
    return out;
}