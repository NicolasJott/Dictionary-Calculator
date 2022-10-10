#ifndef PROJECT2_STACK_H
#define PROJECT2_STACK_H
#include <stdexcept>

const int STACK_SIZE = 100;

struct Input{
    std::string string;
    Fraction fraction;
};

template<class StackType>
class Stack {
private:
    StackType
            data[STACK_SIZE];
    int
            top;
public:
    Stack(void) { top = 0; }
    ~Stack(void) = default;

    void clear(void) { top = 0; }
    int size(void) const { return top; }
    bool isEmpty(void) const { return top == 0; }

    void push(const StackType &d) {

        if (top == STACK_SIZE)
            throw std::overflow_error("Stack is full");

        data[top] = d;

        top++;
    }

    StackType pop(void) {

        if (!top)
            throw std::underflow_error("Stack is empty");

        top--;

        return data[top];

    }

    StackType peek(void) {

        if (!top)
            throw std::underflow_error("Stack is empty");

        return data[top-1];
    }
};
#endif //PROJECT2_STACK_H
