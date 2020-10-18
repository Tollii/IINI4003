#pragma once

template <typename T1, typename T2>
class Pair {
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    T1 first;
    T2 second;

    bool operator>(const Pair &other);
    Pair operator+(const Pair &other);
};

template<typename T1, typename T2>
bool Pair<T1, T2>::operator>(const Pair &other) {
    return (first + second) > (other.first + other.second);
}

template<typename T1, typename T2>
Pair<T1, T2> Pair<T1, T2>::operator+(const Pair &other) {
    Pair p = *this;
    p.first += other.first;
    p.second += other.second;
    return p;
}

