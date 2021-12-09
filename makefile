run :	build
	@./builds/main

minmax: buildMinmax
	@./builds/minmax

testAll : buildSowingTest buildWinningTest buildCapturingTest
	@echo "----------------------------------Launching the sowing tests...----------------------------------"
	@./builds/tests/sowing

	@echo "----------------------------------Launching the winning tests...----------------------------------"
	@./builds/tests/winning

	@echo "----------------------------------Launching the capturing tests...----------------------------------"
	@./builds/tests/capturing

testSowing : buildSowingTest
	@echo "----------------------------------Launching the sowing tests...----------------------------------"
	@./builds/tests/sowing

testWinning : buildWinningTest
	@echo "----------------------------------Launching the winning tests...----------------------------------"
	@./builds/tests/winning

testCapturing : buildCapturingTest
	@echo "----------------------------------Launching the capturing tests...----------------------------------"
	@./builds/tests/capturing 


build : 
	@g++ src/Game.cpp -o builds/main

buildMinmax:
	@g++ src/Minmax.cpp -o builds/minmax

buildSowingTest : 
	@g++ tests/SowingTesting.cpp -o builds/tests/sowing

buildWinningTest : 
	@g++ tests/WinningTesting.cpp -o builds/tests/winning

buildCapturingTest : 
	@g++ tests/CapturingTesting.cpp -o builds/tests/capturing

#TODO : Definir un build optimisé