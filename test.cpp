#include <igloo/igloo.h>
#include "lab3.h"

using namespace igloo;

Context(RegroupTest){

	Spec(LettersOnly){
		Assert::That(regroup("HELLO"), Equals("HELLO"));
	}
	
}

int main(){
	return TestRunner::RunAllTests();
}