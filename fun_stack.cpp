/*
 * Copyright (c) 2004 Piero Dalle Pezze
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */


#include <stdlib.h>
#include<iostream>
#include "fun_stack.h"
using namespace std;

void push(int *P, int dim, int &top, int x) {
  if(top < dim) {
    *(P + top) = x;
    top++;
  }
  else {
    cout << "\aERROR PUSH. Full stack!\n";
    exit(-1);
  }
}

int pop(int *P, int &top) {
  if(top > 0) { 
    top--;
    return *(P+top);
  }
  else {
    cout << "\aERROR POP. Empty stack!\n";
    exit(-1);
  }
}

bool isEmpty(int *P, int top) {
  return (top == 0);
}

void printBool(int *P, int top) {
  if(!isEmpty(P,top)) {
    for(int i=0; i<top; i++)
      cout << *(P+i) << ' ';
    cout << endl;
  }
}

int evalBool(char *exp, int dim) {
  int i = 0;
  int P[50];
  int top = 0;
  int a1, a2;
  while(i < dim) {
    if(*(exp+i) >= '0' && *(exp+i) <= '9')
      push(P, 100, top, *(exp+i)-'0');
    else 
      switch(*(exp+i)) {
          case '+': push(P, 100, top, pop(P, top)+pop(P, top) );
		    break;
          case '*': push(P, 100, top, pop(P, top)*pop(P, top));
		    break;
          case '-': a2 = pop(P, top);
                    a1 = pop(P, top);
                    push(P, 100, top, a1-a2);
		    break;
          case '/': a2 = pop(P, top);
                    a1 = pop(P, top);
                    push(P, 100, top, a1/a2);
		    break;
          case '%': a2 = pop(P, top);
                    a1 = pop(P, top);
                    push(P, 100, top, a1%a2);
		    break;
          default:  cout<<"Item "<<*(exp+i)<<" not accepted!\n";
	            break;
      }
    printBool(P, top);
    i++;
  }
  int exp_value = pop(P, top);
  if(!isEmpty(P, top)) { 
      cout << "\aERROR. Stack is not empty!\n";
      exit(-1);
  }
  return exp_value;
}
 
