#ifndef PROJECT2_NUMSTACK_H
#define PROJECT2_NUMSTACK_H
#include <stdexcept>

const int STACK_SIZE = 100;
typedef int NumStackType;

class NumStack {
private:
    NumStackType
            data[STACK_SIZE];
    int
            count;
public:
    NumStack(void) { count = 0; }
    ~NumStack(void) { }

    void clear(void) { count = 0; }
    int size(void) { return count; }
    bool isEmpty(void) { return count == 0; }

    void push(const NumStackType &d) {

        if (count == STACK_SIZE)
            throw std::overflow_error("Stack is full");

        data[count] = d;

        count++;
    }

    NumStackType pop(void) {

        if (!count)
            throw std::underflow_error("Stack is empty");

        count--;

        return data[count];

    }

    NumStackType peek(void) {

        if (!count)
            throw std::underflow_error("Stack is empty");

        return data[count-1];
    }
};
#endif //PROJECT2_NUMSTACK_H
