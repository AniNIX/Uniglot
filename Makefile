installdir = ${pkgdir}/opt/aninix/SharedLibraries/
targets = Bash C CSharp

compile: 
	@echo Nothing to compile.

install: compile
	mkdir -p ${installdir}
	for target in ${targets}; do rsync -avzl "$$target" ${installdir}; done
	make checkperm

clean:
	for i in `cat .gitignore`; do rm -Rf $$i; done
	
uninstall: 
	rm -Rf ${installdir} 

test: 
	@echo Nothing to do.

checkperm: 
	chmod -R 0755 ${installdir}
	chown root:root ${installdir}

diff: ${INSTALLFIR}
	diff -rc . ${installdir}

reverse:
	rsync -avzlp ${installdir} .
