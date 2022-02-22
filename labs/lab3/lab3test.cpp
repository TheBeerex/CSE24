#include <igloo/igloo.h>
#include "lab3.h"

using namespace igloo;

Context(RegroupTest){

	Spec(LettersOnly){
		Assert::That(regroup("HELLO"), Equals("HELLO"));
	}

	Spec(NumbersOnly){
		Assert::That(regroup("4123"), Equals("4123"));
	}

	Spec(LettersAndNumbers1){
		Assert::That(regroup("H2SO4"), Equals("HSO24"));
	}
	
	Spec(LettersAndNumbers2){
		Assert::That(regroup("A1B2C3D4"), Equals("ABCD1234"));
	}

};

Context(CountUpperTest){

	Spec(NoUpper){
		Assert::That(count_upper("small letters"), Equals(0));
	}

	Spec(AllUpper){
		Assert::That(count_upper("BIG LETTERS"), Equals(10));
	}

	Spec(SomeUpper){
		Assert::That(count_upper("SuperHot"), Equals(2));
	}
	
	Spec(SomeNumbers){
		Assert::That(count_upper("A1B2C3D4"), Equals(4));
	}

	Spec(SomeSpecial){
		Assert::That(count_upper("A*23g gaWwE- ,13$="), Equals(3));
	}

};

Context(TransformCaseTest){

	Spec(AllLower){
		Assert::That(transform_case("small letters"), Equals("SMALL LETTERS"));
	}

	Spec(AllUpper){
		Assert::That(transform_case("BIG LETTERS"), Equals("big letters"));
	}

	Spec(Mixed){
		Assert::That(transform_case("MiXeD StRiNg"), Equals("mIxEd sTrInG"));
	}
	
	Spec(Specials){
		Assert::That(transform_case("A$ i7 $H0u1d"), Equals("a$ I7 $h0U1D"));
	}

};

Context(StringRotationTest){

	Spec(Exists){
		Assert::That(rotation_distance("ABCD", "BCDA"), Equals(1));
	}
	Spec(Fails){
		Assert::That(rotation_distance("ABCD", "BCAD"), Equals(-1));
	}
	Spec(SentenceExists){
		Assert::That(rotation_distance("It's a cool dog.", "g.It's a cool do"), Equals(2));
	}
	Spec(SentenceFails){
		Assert::That(rotation_distance("It's a cool dog", "It's a ocol dog."), Equals(-1));
	}
	Spec(SpecialsNumbersEtAl){
		Assert::That(rotation_distance("5@S$-M4N", "-M4N5@S$"), Equals(4));
	}

};

Context(StringCompressTest){

	Spec(Letters){
		Assert::That(compress("AAACTGG"), Equals("A3CTG2"));
	}
	Spec(Numbers){
		Assert::That(compress("1337"), Equals("1327"));
	}
	Spec(Specials){
		Assert::That(compress("$$@@@#!(&&$"), Equals("$2@3#!(&2$"));
	}
	Spec(MultipleSpaces){
		Assert::That(compress("     "), Equals(" 5"));
	}
	Spec(Mixed){
		Assert::That(compress("Aaa%%%%oo0006"), Equals("Aa2%4o2036"));
	}

};



Context(StringSymmetryTest){

	// All the letters
	Spec(AlphabetA){
		Assert::That(symmetric("A"), IsTrue());
	}
	Spec(AlphabetB){
		Assert::That(symmetric("B"), IsFalse());
	}
	Spec(AlphabetC){	
		Assert::That(symmetric("C"), IsFalse());
	}
	Spec(AlphabetD){	
		Assert::That(symmetric("D"), IsFalse());
	}
	Spec(AlphabetE){	
		Assert::That(symmetric("E"), IsFalse());
	}
	Spec(AlphabetF){		
		Assert::That(symmetric("F"), IsFalse());
	}
	Spec(AlphabetG){		
		Assert::That(symmetric("G"), IsFalse());
	}
	Spec(AlphabetH){		
		Assert::That(symmetric("H"), IsTrue());
	}
	Spec(AlphabetI){		
		Assert::That(symmetric("I"), IsTrue());
	}
	Spec(AlphabetJ){		
		Assert::That(symmetric("J"), IsFalse());
	}
	Spec(AlphabetK){		
		Assert::That(symmetric("K"), IsFalse());
	}
	Spec(AlphabetL){		
		Assert::That(symmetric("L"), IsFalse());
	}
	Spec(AlphabetM){		
		Assert::That(symmetric("M"), IsTrue());
	}
	Spec(AlphabetN){		
		Assert::That(symmetric("N"), IsFalse());
	}
	Spec(AlphabetO){		
		Assert::That(symmetric("O"), IsTrue());
	}
	Spec(AlphabetP){		
		Assert::That(symmetric("P"), IsFalse());
	}
	Spec(AlphabetQ){		
		Assert::That(symmetric("Q"), IsFalse());
	}
	Spec(AlphabetR){		
		Assert::That(symmetric("R"), IsFalse());
	}
	Spec(AlphabetS){		
		Assert::That(symmetric("S"), IsFalse());
	}
	Spec(AlphabetT){		
		Assert::That(symmetric("T"), IsTrue());
	}
	Spec(AlphabetU){		
		Assert::That(symmetric("U"), IsTrue());
	}
	Spec(AlphabetV){		
		Assert::That(symmetric("V"), IsTrue());
	}
	Spec(AlphabetW){		
		Assert::That(symmetric("W"), IsTrue());
	}
	Spec(AlphabetX){		
		Assert::That(symmetric("X"), IsTrue());
	}
	Spec(AlphabetY){		
		Assert::That(symmetric("Y"), IsTrue());
	}
	Spec(AlphabetZ){	
		Assert::That(symmetric("Z"), IsFalse());
	}

	// All the numbers

	Spec(Numbers0){
		Assert::That(symmetric("0"), IsTrue());
	}
	Spec(Numbers1){	
		Assert::That(symmetric("1"), IsFalse());
	}
	Spec(Numbers2){	
		Assert::That(symmetric("2"), IsFalse());
	}
	Spec(Numbers3){	
		Assert::That(symmetric("3"), IsFalse());
	}
	Spec(Numbers4){	
		Assert::That(symmetric("4"), IsFalse());
	}
	Spec(Numbers5){	
		Assert::That(symmetric("5"), IsFalse());
	}
	Spec(Numbers6){	
		Assert::That(symmetric("6"), IsFalse());
	}
	Spec(Numbers7){	
		Assert::That(symmetric("7"), IsFalse());
	}
	Spec(Numbers8){	
		Assert::That(symmetric("8"), IsTrue());
	}
	Spec(Numbers9){	
		Assert::That(symmetric("9"), IsFalse());
	}

	// Strings
	Spec(Hello){
		Assert::That(symmetric("Hello"), IsFalse());
	}
	Spec(JOL){
		Assert::That(symmetric("JOL"), IsTrue());
	}
	Spec(E83){
		Assert::That(symmetric("E83"), IsTrue());
	}
	Spec(L0J){
		Assert::That(symmetric("L0J"), IsTrue());
	}
	Spec(ABBA){
		Assert::That(symmetric("ABBA"), IsFalse());
	}
	Spec(SE32){
		Assert::That(symmetric("SE32"), IsTrue());
	}

};

int main(){
	return TestRunner::RunAllTests();
}




