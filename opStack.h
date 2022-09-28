#ifndef PROJECT2_OPSTACK_H
#define PROJECT2_OPSTACK_H
#include <stdexcept>
#include <cstring>

typedef char opStackType;

class opStack {
private:
    opStackType
            data[STACK_SIZE];
    int
            count;
public:
    opStack(void) { count = 0; }
    ~opStack(void) = default;

    void clear(void) { count = 0; }
    int size(void) { return count; }
    bool isEmpty(void) { return count == 0; }

    void push(const opStackType &d) {

        if (count == STACK_SIZE)
            throw std::overflow_error("Stack is full");

        data[count] = d;

        count++;
    }

    opStackType pop(void) {

        if (!count)
            throw std::underflow_error("Stack is empty");

        count--;

        return data[count];

    }

    opStackType peek(void) {

        if (!count)
            throw std::underflow_error("Stack is empty");

        return data[count-1];
    }
};
#endif //PROJECT2_OPSTACK_H
