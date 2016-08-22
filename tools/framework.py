#! /usr/bin/python
import subprocess

CC = 'g++'
SOURCE = 'target.cpp'
TARGET = 'target'


def gen_code(**params):
    with open('tools/main.cpp.tmplate') as f:
        template = f.read()
    with open(SOURCE, 'w') as f:
        f.write(template.format(**params))


def run_program():
    subprocess.call([CC, SOURCE, '-o', TARGET, '-std=c++11'])
    subprocess.call(['./%s' % TARGET])
    subprocess.call(['rm', TARGET, SOURCE])
