run :	build
	@./builds/main

test : buildTest
	@./builds/testing

build : 
	@g++ src/Game.cpp -o builds/main

buildTest : 
	@g++ src/Testing.cpp -o builds/testing

#TODO : Definir un build optimisé