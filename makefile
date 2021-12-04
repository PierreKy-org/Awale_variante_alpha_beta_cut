run :	build
	@./builds/main

build : 
	@g++ src/Game.cpp -o builds/main

#TODO : Definir un build optimisé