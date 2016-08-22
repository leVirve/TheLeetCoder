#! /usr/bin/python3
import re
import os.path
import subprocess

CC = 'g++'
CFLAGS = '-std=c++11'
UNITTEST = 'TEST.cpp'
TARGET = 'target'


def build_map():
    qmap = {}
    qid_regex = re.compile('(\d+).*')
    dirs = [d for d in os.listdir('.') if os.path.isdir(d)]
    for folder in dirs:
        qid = qid_regex.search(folder)
        if qid:
            qmap[qid.group(1)] = folder
    return qmap


def test_program(question_id=0, use_catch_framework=False):
    cwd = qmap[question_id]
    compile_cmds = [CC, UNITTEST, '-o', TARGET, CFLAGS]
    if use_catch_framework:
        compile_cmds += ['-DCATCH_TEST']

    subprocess.call(compile_cmds, cwd=cwd)
    subprocess.call(['./%s' % TARGET], cwd=cwd)
    subprocess.call(['rm', TARGET], cwd=cwd)

qmap = build_map()
