# CSDS 337 - Project


## Overview

Our group will be modifying the compiler we have been working with to support a subset of the python language. To accomplish this we will be modifying the existing language, as well as implementing changes to the AST to support some more niche features of Python that are not supported in C.

The subset of the Python language that we will be implementing will be the starting rules, general statements, assignment, if/else statements, conditional/compound statements, arithmetic operators, and while loops.

The change we will be making to the AST will be to support Python’s dynamic typing. For example variables can be dynamically typed and converted based on usage rather than explicitly typed on instantiation. We will also be incorporating indentation (block style) as opposed to the C-type  }/{. We can achieve this by checking for  “:” to indicate the start of a code block and then reading until we don’t get a tab space (U+0009). 

## Evaluation/Testing

We will run unit tests on each individual component of the modified grammar. Each unit test will test for the correctness of the grammar by utilizing the appropriate calls.

Similar to assignment 1, we will be generating dummy python code for certain functions (quicksort, bubble sort, etc) and testing for the correctness of the compiled machine code. 

## Current Progress

So far, we have arrived at the Python general grammar. After reading through it, we have created a subsection of the grammar that only relates to the functionalities that we plan on implementing in our compiler. Our next step is to start implementing our grammar. We referenced the (Official Python)[https://docs.python.org/3/reference/grammar.html] site to design our new grammar. We have written the lexer and currently working on the parser.




