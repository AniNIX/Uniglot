import os
import pytest

def test_bash_import():
    fh = os.popen("/bin/bash -c 'source Bash/header; [ `declare -F | wc -l` -eq `grep -E -c ^function\\  Bash/header` ]'", mode='r', buffering=-1)
    output = fh.read()
    retcode = fh.close()
    assert retcode == None

def test_c_import():
    fh = os.popen("gcc -o tests/c.out C/ll.h", mode='r', buffering=-1)
    output = fh.read()
    retcode = fh.close()
    assert retcode == None and os.path.isfile('tests/c.out')

def test_csharp_import():
    fh = os.popen("/bin/bash -c 'mcs -out:tests/csharp.out CSharp/*.csharp tests/test.csharp'", mode='r', buffering=-1)
    output = fh.read()
    retcode = fh.close()
    assert retcode == None and os.path.isfile('tests/csharp.out')

def test_remove_outs():
    fh = os.popen("/bin/bash -c 'rm -Rf tests/*.out'", mode='r', buffering=-1)
    output = fh.read()
    retcode = fh.close()
    assert retcode == None
