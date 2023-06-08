#include <iostream>
#include "arrays.h"

int main() {
    printRight(-1);
    printRight(1);
    printRight(3);
    printRight(5);

    std::cout << std::endl;

    printRight_upsideDown_rightJustified(-1);
    printRight_upsideDown_rightJustified(3);
    printRight_upsideDown_rightJustified(5);

    std::cout << std::endl;

    const char arr[] = {'A','%','8'};
    printArray(arr, 3);

    std::cout << std::endl;

    const char arr2d[][SIZE] = {{'A','3','@'}, {'#','\\','9'}};
    printArray(arr2d, 2, 3);

    std::cout << std::endl;

    char str[] = "a#~ *";
    add(str, 5, 5);
    printArray(str, 5);

    std::cout << std::endl;

    char str1[][SIZE] = {"how  ", "now  ", "brown", "cow  "};
    add(str1, 4, 5, 5);
    printArray(str1, 4, 5);

    std::cout << std::endl;

    char strNew[] = "abcde";
    rotateLeft(strNew, 5);
    printArray(strNew, 5);

    std::cout << std::endl;

    char strNew2[][SIZE] = {"abc", "def", "ghi"};
    rotateLeft(strNew2, 3, 3);
    printArray(strNew2, 3, 3);

    std::cout << std::endl;

    char strNewNew[] = "abcdef";
    rotateRight(strNewNew, 6);
    printArray(strNewNew, 6);

    std::cout << std::endl;

    char strNewNew2[][SIZE] = {"abc", "def", "ghi"};
    rotateRight(strNewNew2, 3, 3);
    printArray(strNewNew2, 3, 3);

    std::cout << std::endl;

    char strNewNewNew[] = "abcdef";
    reverse(strNewNewNew, 6);
    printArray(strNewNewNew, 6);

    std::cout << std::endl;

    char strA[] = "123456";
    char strB[] = "789012";
    swapRange(strA, 6, 0, strB, 6, 3, 3);
    printArray(strA, 6);
    printArray(strB, 6);

    std::cout << std::endl;

    char strSwap[] = "batman$robin";
    swapWithinOneRow(strSwap, 12, 6);
    printArray(strSwap, 12);

    std::cout << std::endl;

    char strRows[][SIZE] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};//, {'j', 'k', 'l'}};
    swapRows(strRows, 3, 3);
    printArray(strRows, 3, 3);
    return 0;
}
