run :	build
	@./builds/main

build : 
	@g++ src/Awale.cpp -o builds/main

#TODO : Definir un build optimisé