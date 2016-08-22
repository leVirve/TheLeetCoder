#! /usr/bin/python3
import re
import os.path
import subprocess

CC = 'g++'
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


def test_program(question_id=0):
    cwd = qmap[question_id]
    subprocess.call([CC, UNITTEST, '-o', TARGET, '-std=c++11'], cwd=cwd)
    subprocess.call(['./%s' % TARGET], cwd=cwd)
    subprocess.call(['rm', TARGET], cwd=cwd)

qmap = build_map()
