#include <iostream>
#include "arrays.h"

bool checkArrayPrecondition(int size, const char* name) {
    if(size < 0) {
        cout << name;
        cout << " must be > 0" << endl;
        return false;
    }

    if(size > SIZE) {
        cout << name;
        cout << " must be <= SIZE" << endl;
        return false;
    }

    return true;
}

void printRight(int n) {
    if(n < 0) {
        cout << "n must be > 0" << endl;
        return;
    }

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < row + 1; col++) {
            cout << "*";
        }

        cout << endl;
    }
}

void printRight_upsideDown_rightJustified(int n) {
    if(n < 0) {
        cout << "n must be > 0" << endl;
        return;
    }

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            if(col >= row) {
                cout << "*";
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }
}

void printArray(const char arr[], int size) {
    if(!checkArrayPrecondition(size, "size")) {
        return;
    }

    for(int idx = 0; idx < size; idx++) {
        cout << arr[idx];
    }
    cout << endl;
}

void printArray(const char arr[][SIZE], int rows, int cols) {
    if(!checkArrayPrecondition(rows, "rows") || !checkArrayPrecondition(cols, "cols")) {
        return;
    }

    for(int row = 0; row < rows; row++) {
        printArray(arr[row], cols);
    }
}

void add(char arr[], int size, int val) {
    if(!checkArrayPrecondition(size, "size")) {
        return;
    }

    for(int idx = 0; idx < size; idx++) {
        int charVal = (((int) arr[idx]) + val);

        while (charVal < MIN_PRINTABLE_ASCII) {
            charVal += ASCII_PRINTABLE_RANGE;
        }

        while (charVal > MAX_PRINTABLE_ASCII) {
            charVal -= ASCII_PRINTABLE_RANGE;
        }

        arr[idx] = (char) charVal;
    }
}

void add(char arr[][SIZE], int rows, int cols, int val) {
    if(!checkArrayPrecondition(rows, "rows") || !checkArrayPrecondition(cols, "cols")) {
        return;
    }

    for(int row = 0; row < rows; row++) {
        add(arr[row], cols, val);
    }
}

void rotateLeft(char arr[], int size) {
    if(!checkArrayPrecondition(size, "size")) {
        return;
    }

    char firstChar = arr[0];

    for(int idx = 1; idx < size; idx++) {
        arr[idx - 1] = arr[idx];
    }

    arr[size - 1] = firstChar;
}

void rotateLeft(char arr[][SIZE], int rows, int cols) {
    if(!checkArrayPrecondition(rows, "rows") || !checkArrayPrecondition(cols, "cols")) {
        return;
    }

    for(int row = 0; row < rows; row++) {
        rotateLeft(arr[row], cols);
    }
}

void rotateRight(char arr[], int size) {
    if(!checkArrayPrecondition(size, "size")) {
        return;
    }

    char lastChar = arr[size - 1];

    //Does size need to me minus 1
    for(int idx = size - 1; idx > 0; idx--) {
        arr[idx] = arr[idx - 1];
    }

    arr[0] = lastChar;
}

void rotateRight(char arr[][SIZE], int rows, int cols) {
    if(!checkArrayPrecondition(rows, "rows") || !checkArrayPrecondition(cols, "cols")) {
        return;
    }

    for(int row = 0; row < rows; row++) {
        rotateRight(arr[row], cols);
    }
}

void reverse(char arr[], int size) {
    if(!checkArrayPrecondition(size, "size")) {
        return;
    }
    char newArr[SIZE];

    for(int idx = 0; idx < size; idx++) {
        newArr[size - idx - 1] = arr[idx];
    }

    for(int idx = 0; idx < size; idx++) {
        arr[idx] = newArr[idx];
    }

}

void swapRange(char arr1[], int size1, int index1,
               char arr2[], int size2, int index2, int len) {
    if(size1 < index1 + len) {
        cout << "size1 must be >= index1 + len" << endl;
    }
    if(!checkArrayPrecondition(size1, "size1")) {
        return;
    }

    if(size2 < index2 + len) {
        cout << "size2 must be >= index2 + len" << endl;
    }
    if(!checkArrayPrecondition(size2, "size2")) {
        return;
    }

    char slice1[SIZE];
    char slice2[SIZE];

    for(int idx = 0; idx < len; idx++) {
        slice1[idx] = arr1[index1 + idx];
    }
    for(int idx = 0; idx < len; idx++) {
        slice2[idx] = arr2[index2 + idx];
    }

    for(int idx = 0; idx < len; idx++) {
        arr1[index1 + idx] = slice2[idx];
    }
    for(int idx = 0; idx < len; idx++) {
        arr2[index2 + idx] = slice1[idx];
    }
}


void swapWithinOneRow(char arr[], int size, int len) {
    int idx = 0;

    while(idx + (len * 2) <= size) {
        swapRange(arr, size, idx, arr, size, idx + len, len);
        idx += len * 2;
    }
}

void swapRows(char arr[][SIZE], int rows, int cols) {
    int idx = 0;

    while(idx + 2 <= rows) {
        swapRange(arr[idx], cols, 0, arr[idx + 1], cols, 0, cols);
        idx += 2;
    }
}
