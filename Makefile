installdir = ${pkgdir}/opt/aninix/Uniglot/
targets = Bash C CSharp Python Hooks

compile:
	@echo Nothing to compile.

install: compile
	mkdir -p ${installdir}
	for target in ${targets}; do rsync -avzzl "$$target" ${installdir}; done
	mkdir "${installdir}/pacman/"
	cp PKGBUILD "${installdir}/pacman/"
	mkdir "${installdir}/make/"
	cp Makefile "${installdir}/make/"
	mkdir -p ${pkgdir}/usr/local/bin
	find bin/ -type f -exec install -m 0755 -o root -g root {} "${pkgdir}/usr/local/bin" \;
	make checkperm

clean:
	git clean -fdX

uninstall:
	rm -Rf ${installdir}

test:
	python3 -m pytest

checkperm:
	chmod -R 0755 ${installdir} ${pkgdir}/usr/local/bin/uniglot-clone
	chown root:root ${installdir} ${pkgdir}/usr/local/bin/uniglot-clone

diff: ${INSTALLFIR}
	diff -rc . ${installdir}

reverse:
	rsync -avzlp ${installdir} .
