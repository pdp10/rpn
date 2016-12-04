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


// Evaluation of arithmatic expression in 
// Reverse Polish notation 


#include "fun_stack.h"
#include<iostream>
using namespace std;

void insert(char *exp, int dim, int& i) {
  bool sent = false;
  char x;
  for(int j=0; j<dim && !sent; j++) {
    cin >> x;
    if(x != '=')  { 
        *(exp+j) = x;
	i++;
    }
    else sent = true;
  }
}

main() {

  char exp[25];
  int dim = 0;
  cout << "Insert an arithmetic expression in Reverse Polish Notation (RPN).\n"
          "Syntax: numbers (0-9); operators (+,-,*,/,%); end expression (=).\n"
          "(e.g. 3 4 + = will return 7)\n"; 
  insert(exp, 25, dim);
  int exp_val = evalBool(exp, dim);
  cout << "Result: " << exp_val << endl;
}
