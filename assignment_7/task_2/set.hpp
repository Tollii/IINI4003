#pragma once
#include <vector>
#include <ostream>

class Set {
public:
    std::vector<int> set = {};

    Set();
    explicit Set(const std::vector<int> &list);

    Set &operator+=(const Set &other);
    Set &operator+=(int num);
    Set operator+(const Set &other) const;
    Set &operator=(const Set &other);
    bool operator==(const Set &other) const;
    bool operator!=(const Set &other) const;
    friend std::ostream &operator<<(std::ostream &out, const Set &s);


private:


};

