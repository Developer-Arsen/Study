#include <iostream>
#include <cassert>
#include "stack.hpp"

void testDefaultConstructor() {
    Stack<int> stack;
    assert(stack.isEmpty() && "Default constructor failed; stack should be empty.");
    std::cout << "testDefaultConstructor passed.\n";
}

void testPush() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    assert(stack.top() == 20 && "Push failed; top element should be 20.");
    assert(!stack.isEmpty() && "Push failed; stack should not be empty after pushing elements.");
    std::cout << "testPush passed.\n";
}

void testPop() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.pop();
    assert(stack.top() == 10 && "Pop failed; top element should be 10 after pop.");

    stack.pop(); // Should leave the stack empty
    assert(stack.isEmpty() && "Pop failed; stack should be empty after popping all elements.");

    try {
        stack.pop(); // Should throw an exception
        assert(false && "Pop on empty stack did not throw exception.");
    } catch (const std::out_of_range&) {
        std::cout << "Pop on empty stack threw as expected.\n";
    }
    std::cout << "testPop passed.\n";
}

void testTop() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    assert(stack.top() == 20 && "Top failed; top should return 20.");

    try {
        Stack<int> emptyStack;
        emptyStack.top(); // Should throw an exception
        assert(false && "Top on empty stack did not throw exception.");
    } catch (const std::out_of_range&) {
        std::cout << "Top on empty stack threw as expected.\n";
    }
    std::cout << "testTop passed.\n";
}

void testInitializerListConstructor() {
    Stack<int> stack = {1, 2, 3, 4, 5};
    assert(stack.top() == 5 && "Initializer list constructor failed; top element should be 5.");
    std::cout << "testInitializerListConstructor passed.\n";
}

void testIsEmpty() {
    Stack<int> stack;
    assert(stack.isEmpty() && "IsEmpty failed; new stack should be empty.");

    stack.push(10);
    assert(!stack.isEmpty() && "IsEmpty failed; stack with elements should not be empty.");

    stack.pop();
    assert(stack.isEmpty() && "IsEmpty failed; stack should be empty after popping all elements.");
    std::cout << "testIsEmpty passed.\n";
}

void testCopyConstructor() {
    Stack<int> originalStack;
    originalStack.push(1);
    originalStack.push(2);

    Stack<int> copiedStack = originalStack;
    assert(copiedStack.top() == 2 && "Copy constructor failed; top element should be 2.");
    std::cout << "testCopyConstructor passed.\n";
}

void testMoveConstructor() {
    Stack<int> originalStack;
    originalStack.push(1);
    originalStack.push(2);

    Stack<int> movedStack = std::move(originalStack);
    assert(movedStack.top() == 2 && "Move constructor failed; top element should be 2.");
    std::cout << "testMoveConstructor passed.\n";
}

int main() {
    testDefaultConstructor();
    testPush();
    testPop();
    testTop();
    testInitializerListConstructor();
    testIsEmpty();
    testCopyConstructor();
    testMoveConstructor();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
