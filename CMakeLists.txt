cmake_minimum_required(VERSION 3.22)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructure main.c)

add_executable(testVector Vector/vector.c)
add_executable(testStack Stack/stack.c)

add_executable(infixToPrefix 3.Stack/ExpressionConvert/infixToPrefix.c)
add_executable(infixTPostfix 3.Stack/ExpressionConvert/infixToPostfix.c)
add_executable(prefixToInfix 3.Stack/ExpressionConvert/prefixToInfix.c)
