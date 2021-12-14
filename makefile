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

	@echo "----------------------------------Launching the copy tests...----------------------------------"
	@./builds/tests/copy

testSowing : buildSowingTest
	@echo "----------------------------------Launching the sowing tests...----------------------------------"
	@./builds/tests/sowing

testWinning : buildWinningTest
	@echo "----------------------------------Launching the winning tests...----------------------------------"
	@./builds/tests/winning

testCapturing : buildCapturingTest
	@echo "----------------------------------Launching the capturing tests...----------------------------------"
	@./builds/tests/capturing 

testMinmax : buildMinmaxTest
	@echo "----------------------------------Launching the minmax tests...----------------------------------"
	@./builds/tests/minmax 

testCopy : buildCopy
	@echo "----------------------------------Launching the minmax tests...----------------------------------"
	@./builds/tests/copy 


build : 
	@g++ -O3 src/Game.cpp -o builds/main

buildMinmax:
	@g++ -O3 src/Minmax.cpp -o builds/minmax

buildSowingTest : 
	@g++ tests/SowingTesting.cpp -o builds/tests/sowing

buildWinningTest : 
	@g++ tests/WinningTesting.cpp -o builds/tests/winning

buildCapturingTest : 
	@g++ tests/CapturingTesting.cpp -o builds/tests/capturing

buildMinmaxTest : 
	@g++ tests/MinmaxTest.cpp -o builds/tests/minmax


buildCopy : 
	@g++ tests/CopyBoardTest.cpp -o builds/tests/copy

#TODO : Definir un build optimisé
