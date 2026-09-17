#ifndef INT_ARRAY_HPP
#define INT_ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

class Array {
public:
    Array() : len{0}, buf{nullptr} {
    }

    explicit Array(int len) : len{len}, buf{new int[len]} {
    }

    // TODO Step 4: copy constructor
    // TODO Step 4: move constructor
    // TODO Step 5: friend void swap(Array& lhs, Array& rhs) noexcept
    // TODO Step 5: copy assignment
    // TODO Step 5: move assignment
    // TODO Step 4: destructor

    int length() const {
        return len;
    }

    int& operator[](int index) {
        // TODO Step 3: throw std::string when the index is out of bounds:
        //     "Exception operator[](" + std::to_string(index) + ") Out Of Range"
        return buf[index];
    }

    const int& operator[](int index) const {
        // TODO Step 3: the same check as above
        return buf[index];
    }

    // TODO Step 2: void fill(int val) - set every element to val

private:
    int len;
    int* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};

inline std::ostream& operator<<(std::ostream& out, const Array& array) {
    std::stringstream temp;
    // We don't want to set formatting flags globally.
    temp << std::setprecision(2) << std::fixed << std::right;

    for (int i = 0; i < array.length(); ++i) {
        temp << std::setw(8) << array[i];
    }

    out << temp.str();
    return out;
}

inline std::istream& operator>>(std::istream& in, Array& array) {
    for (int i = 0; i < array.length(); ++i) {
        in >> array[i];
    }

    return in;
}

#endif
