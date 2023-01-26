import os
import pytest

def test_hooks_exec():
    fh = os.popen("find Hooks -type f -exec ls -l {} \\; | grep -E ^-rw-")
    output = fh.read()
    retcode = fh.close()
    assert retcode == 256 and output == ''
