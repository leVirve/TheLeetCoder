#! /usr/bin/python
from tools import framework

framework.gen_code(
    question_solution_cpp='231.Power-of-Two.cpp',
    solution_name='isPowerOfTwo',
    input=50,
    output='false'
)
framework.run_program()