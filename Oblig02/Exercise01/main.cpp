#include "VectorImpl.h"
#include "ListImpl.h"
#include "IteratorImpl.h"

void printHelloWorld1() {
    std::cout << "Hello World!" << std::endl;
}

auto printHelloWorld2 = []() {
    std::cout << "Hello World2!" << std::endl;
};

int calculateSum1(int a, int b) {
    return a + b;
}

auto calculateSum2 = [](int a, int b) {
    return a + b;
};

int main() {

    auto vectorImpl = new VectorImpl<std::vector<int>, int>();
    auto listImpl = new ListImpl<std::list<int>, int>();
//    auto iteratorImplVector = new IteratorImpl<std::vector<int>, int>();
//    auto iteratorImplList = new IteratorImpl<std::list<int>, int>();

    std::vector<int> v{1, 9, 7, 3, 5, 6, 2, 8, 4};
    std::list<int> list{1, 9, 7, 3, 5, 6, 2, 8, 4};

    printHelloWorld1();
    printHelloWorld2();

    std::cout << "Sum = " << calculateSum1(5, 8) << std::endl;
    std::cout << "Sum = " << calculateSum2(5, 8) << std::endl;

    vectorImpl->run(v);
    listImpl->run(list);

//    iteratorImplVector->run(v);
//    iteratorImplList->run(list);

    return 0;
}