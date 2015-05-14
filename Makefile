all:
	@make all -C sources/; \
	mv  sources/*.o object
tests:
	@make test -C sources/; \
	mv sources/*.o object
docu:
	@echo "Génération des fichiers de documentation...\n";\
	doxygen doxyfile > doc/logs.txt 2>&1 ;\
	echo "Fin de la génération de la documentation.\nLes logs sont accessibles depuis le fichier doc/logs.txt";\
	ln -fs doc/html/index.html documentation.html
clean:
	@make clean -C sources/ >> /dev/null 2>&1
mrproper:
	@rm binary/* >> /dev/null 2>&1;\
	rm test/* >> /dev/null 2>&1;\
	make clean >> /dev/null 2>&1;\
	rm documentation.html >> /dev/null 2>&1;\
	rm -rf doc/* >> /dev/null 2>&1
