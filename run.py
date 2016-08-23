#! /usr/bin/python
import sys
from framework import commands

qid = sys.argv[1]
catch = sys.argv[2] == 'catch' if len(sys.argv) > 2 else False

commands.test_program(
    question_id=qid,
    use_catch_framework=catch)
