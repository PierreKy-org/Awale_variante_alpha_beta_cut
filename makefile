run :	build
	@./builds/main

testAll : buildSowingTest buildWinningTest
	@echo "----------------------------------Launching the sowing tests...----------------------------------"
	@./builds/tests/sowing

	@echo "----------------------------------Launching the winning tests...----------------------------------"
	@./builds/tests/winning

testSowing : buildSowingTest
	@echo "----------------------------------Launching the sowing tests...----------------------------------"
	@./builds/tests/sowing

testWinning : buildWinningTest
	@echo "----------------------------------Launching the winning tests...----------------------------------"
	@./builds/tests/winning

#@echo "----------------------------------Launching the capture tests...----------------------------------"
#@./builds/tests/sowing

build : 
	@g++ src/Game.cpp -o builds/main

buildSowingTest : 
	@g++ tests/SowingTesting.cpp -o builds/tests/sowing

buildWinningTest : 
	@g++ tests/WinningTesting.cpp -o builds/tests/winning

#TODO : Definir un build optimisé