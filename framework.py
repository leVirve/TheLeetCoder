#! /usr/bin/python
import subprocess

CC = 'g++'
SOURCE = 'target.cpp'
TARGET = 'target'


def gen_code(params):
    with open('main.cpp.tmplate') as f:
        template = f.read()
    with open(SOURCE, 'w') as f:
        f.write(template.format(**params))


def run_program():
    subprocess.call([CC, SOURCE, '-o', TARGET])
    subprocess.call(['./%s' % TARGET])
    subprocess.call(['rm', TARGET, SOURCE])


params = {
    'question_solution_cpp': '334.Reverse-String.cpp',
    'solution_name': 'reverseString',
    'input': 'ABCD',
    'output': 'DCBA'
}

gen_code(params)
run_program()
