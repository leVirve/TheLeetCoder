#! /usr/bin/python3
import re
import click
import os
import shutil
import subprocess

CC = 'clang++'
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
@click.option('--catch', '-c', is_flag=True)
@click.option('--lang_c', is_flag=True)
@click.argument('question_id')
def test(question_id, catch, lang_c):
    print('==> Testing on #' + question_id)

    qmap = build_map()
    cwd = qmap[re.search('(\d+)', question_id).group(1)]

    def run_command(args):
        return subprocess.call(args, cwd=cwd)

    compile_cmd = [CC, UNITTEST, '-o', TARGET, CFLAGS]
    if catch:
        compile_cmd += ['-DCATCH_TEST']
    if lang_c:
        compile_cmd += ['-DC_SOLUTION']

    print('==> Compiling ...')
    ret = run_command(compile_cmd)
    if not ret:
        print('==> Running ...')
        run_command(['./%s' % (TARGET)])

    print('==> Delete output.')
    run_command(['rm', TARGET])


@click.group()
def cli():
    pass


if __name__ == '__main__':
    cli.add_command(gen)
    cli.add_command(test)
    cli()
