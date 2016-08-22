#! /usr/bin/python
from tools import framework

framework.gen_code(
    question_solution_cpp='334.Reverse-String.cpp',
    solution_name='reverseString',
    input='ABCD',
    output='DCBA'
)
framework.run_program()
