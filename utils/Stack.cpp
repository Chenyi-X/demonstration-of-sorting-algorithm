#include <all.h>
#include <Stack.h>

Status InitStack_Sq(SqStack& S, int size, int inc) {
    S.elem = new ElemType[size];
    if (!S.elem) {
        // Memory allocation failed
        return OVERFLOW;
    }
    S.top = 0;
    S.size = size;
    S.increment = inc;
    return OK;
}

Status StackEmpty_Sq(SqStack S) {
    if (S.top == 0) {
        return TRUE;  // Stack is empty
    }
    else {
        return FALSE; // Stack is not empty
    }
}

Status Push_Sq(SqStack& S, ElemType e) {
    if (S.top == S.size) {
        // Stack is full, need to expand
        ElemType* newElem = new ElemType[S.size + S.increment];
        if (!newElem) {
            // Memory allocation failed
            return OVERFLOW;
        }
        // Copy existing elements to the new array
        for (int i = 0; i < S.size; ++i) {
            newElem[i] = S.elem[i];
        }
        delete[] S.elem;  // Free the old array
        S.elem = newElem; // Update the base address
        S.size += S.increment; // Update the new size
    }
    S.elem[S.top++] = e;
    return OK;
}

Status Pop_Sq(SqStack& S, ElemType& e) {
    if (S.top == 0) {
        // Stack is empty
        return ERROR;
    }
    e = S.elem[--S.top];
    return OK;
}
