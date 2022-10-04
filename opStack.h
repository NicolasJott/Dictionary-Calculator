#ifndef PROJECT2_OPSTACK_H
#define PROJECT2_OPSTACK_H
#include <stdexcept>

typedef char OpStackType;

class OpStack {
private:
    OpStackType
            data[STACK_SIZE]{};
    int
            top;
public:
    OpStack() { top = 0; }
    ~OpStack() = default;

    void clear() { top = 0; }
    [[nodiscard]] int size() const { return top; }
    [[nodiscard]] bool isEmpty() const { return top == 0; }

    void push(const OpStackType &d) {

        if (top == STACK_SIZE)
            throw std::overflow_error("Stack is full");

        data[top++] = d;

    }

    OpStackType pop() {

        if (!top)
            throw std::underflow_error("Stack is empty");



        return data[top--];

    }

    OpStackType peek() {

        if (!top)
            throw std::underflow_error("Stack is empty");

        return data[top-1];
    }
};
#endif //PROJECT2_OPSTACK_H
