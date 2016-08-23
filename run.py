#! /usr/bin/python3
import re
import click
import os
import shutil
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


@click.command()
@click.argument('question_name')
def gen(question_name):
    if not os.path.exists(question_name):
        os.mkdir(question_name)
    open('%s/solution.hpp' % question_name, 'a').close()
    shutil.copy('framework/template/TEST.cpp', '%s/TEST.cpp' % question_name)


@click.command()
@click.argument('question_id')
def test(question_id, use_catch_framework=False):
    click.echo('Test Start...')

    qmap = build_map()
    cwd = qmap[question_id]

    def run_command(args):
        print(args)
        return subprocess.call(args, cwd=cwd)

    compile_cmd = [CC, UNITTEST, '-o', TARGET, CFLAGS]
    if use_catch_framework:
        compile_cmd += ['-DCATCH_TEST']

    not run_command(compile_cmd) and run_command(['./%s/%s' % (cwd, TARGET)])
    run_command(['rm', TARGET])


@click.group()
def cli():
    pass


if __name__ == '__main__':
    cli.add_command(gen)
    cli.add_command(test)
    cli()
