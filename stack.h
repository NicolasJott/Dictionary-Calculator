#ifndef PROJECT2_STACK_H
#define PROJECT2_STACK_H
#include <stdexcept>

const int STACK_SIZE = 17;

struct Value{
    std::string name;
    Fraction value;
};

template<class StackType>
class Stack {
private:
    StackType
            data[STACK_SIZE];
    int
            top;
public:
    Stack() { top = 0; }
    ~Stack() = default;

    void clear() { top = 0; }
    int size() const { return top; }
    bool isEmpty() const { return top == 0; }

    void push(const StackType &d) {

        if (top == STACK_SIZE)
            throw std::overflow_error("Stack is full");

        data[top] = d;

        top++;
    }

    StackType pop() {

        if (!top)
            throw std::underflow_error("Stack is empty");

        top--;

        return data[top];

    }

    StackType peek() {

        if (!top)
            throw std::underflow_error("Stack is empty");

        return data[top-1];
    }
};
#endif //PROJECT2_STACK_H
