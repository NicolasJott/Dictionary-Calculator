#ifndef PROJECT2_DICTIONARY_H
#define PROJECT2_DICTIONARY_H

#include <string>
#include "fraction.h"
#include <stdexcept>

enum DictionaryStatus {
    UNUSED,
    IN_USE,
    DELETED
};

const uint32_t
    TABLE_SIZE = 127,
    MAX_ITEMS = 101;

class Dictionary {
public:
    Dictionary() { clear(); }
    ~Dictionary() = default;

    bool isEmpty() { return !nItems; }
    uint32_t  size() { return nItems; }

    void clear();

    void add(const std::string &, const Fraction);

    Fraction search(const std::string &);

    void remove(const std::string &);
private:
    std::string
        keys[TABLE_SIZE];
    Fraction
        values[TABLE_SIZE];
    DictionaryStatus
        status[TABLE_SIZE];
    uint32_t
        nItems;

};


#endif //PROJECT2_DICTIONARY_H
