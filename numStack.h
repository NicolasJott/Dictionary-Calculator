#ifndef PROJECT2_NUMSTACK_H
#define PROJECT2_NUMSTACK_H
#include <stdexcept>

const int STACK_SIZE = 100;
typedef Fraction NumStackType;

class NumStack {
private:
    NumStackType
            data[STACK_SIZE];
    int
            top;
public:
    NumStack() { top = 0; }
    ~NumStack() = default;

    void clear() { top = 0; }
    [[nodiscard]] int size() const { return top; }
    [[nodiscard]] bool isEmpty() const { return top == 0; }

    void push(const NumStackType &d) {

        if (top == STACK_SIZE)
            throw std::overflow_error("Stack is full");

        data[top] = d;

        top++;
    }

    NumStackType pop() {

        if (!top)
            throw std::underflow_error("Stack is empty");

        top--;

        return data[top];

    }

    NumStackType peek() {

        if (!top)
            throw std::underflow_error("Stack is empty");

        return data[top-1];
    }
};
#endif //PROJECT2_NUMSTACK_H
