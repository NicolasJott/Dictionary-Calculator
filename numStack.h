#ifndef PROJECT2_NUMSTACK_H
#define PROJECT2_NUMSTACK_H
#include <stdexcept>

const int STACK_SIZE = 100;
typedef int StackType;

class numStack {
private:
    StackType
            data[STACK_SIZE];
    int
            count;
public:
    numStack(void) { count = 0; }
    ~numStack(void) { }

    void clear(void) { count = 0; }
    int size(void) { return count; }
    bool isEmpty(void) { return count == 0; }

    void push(const StackType &d) {

        if (count == STACK_SIZE)
            throw std::overflow_error("Stack is full");

        data[count] = d;

        count++;
    }

    StackType pop(void) {

        if (!count)
            throw std::underflow_error("Stack is empty");

        count--;

        return data[count];

    }

    StackType peek(void) {

        if (!count)
            throw std::underflow_error("Stack is empty");

        return data[count-1];
    }
};
#endif //PROJECT2_NUMSTACK_H
