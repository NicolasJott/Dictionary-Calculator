#ifndef PROJECT2_OPSTACK_H
#define PROJECT2_OPSTACK_H
#include <stdexcept>
#include <cstring>

typedef char OpStackType;

class OpStack {
private:
    OpStackType
            data[STACK_SIZE];
    int
            count;
public:
    OpStack(void) { count = 0; }
    ~OpStack(void) = default;

    void clear(void) { count = 0; }
    int size(void) { return count; }
    bool isEmpty(void) { return count == 0; }

    void push(const OpStackType &d) {

        if (count == STACK_SIZE)
            throw std::overflow_error("Stack is full");

        data[count] = d;

        count++;
    }

    OpStackType pop(void) {

        if (!count)
            throw std::underflow_error("Stack is empty");

        count--;

        return data[count];

    }

    OpStackType peek(void) {

        if (!count)
            throw std::underflow_error("Stack is empty");

        return data[count-1];
    }
};
#endif //PROJECT2_OPSTACK_H
