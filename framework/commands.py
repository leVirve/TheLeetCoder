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

    def run_command(args):
        subprocess.call(args, cwd=cwd)

    compile_cmd = [CC, UNITTEST, '-o', TARGET, CFLAGS]
    if use_catch_framework:
        compile_cmd += ['-DCATCH_TEST']

    run_command(compile_cmd)
    run_command(['./%s' % TARGET])
    run_command(['rm', TARGET])

qmap = build_map()
