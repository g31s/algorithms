// Following program run the Test on Infix2Postfix classed.

#include <iostream>
#include <string>
using namespace std;

// Include the Infix2Postfix header file.
#include"../Infix2Postfix.h"

/* Tests 2D array
 [[input,output,test_output],
 [input,output,test_output],
 ] */
string test_array[][3] = {{"a+b*c+d-e+f","abc*+d+e-f+","true"},
						 {"(a+b)*(c+d)","ab+cd+*","true"},
						 {"a*b+c*d","ab*cd*+","true"},
						 {"a+b+c+d","ab+c+d+","true"},
						 {"3+4*5/6","345*6/+","true"},
						 {"(300+23)*(43-21)/(84+7)","30023+4321-*847+/","true"},
						 {"a*b-c", "abc-*","false"},
						 {"3+4*5/6","3456*/+","false"}
						};

// Test Pass
bool test_pass = true;

int RunTest();
string compare(string test,string output) {
	return (test == output ) ? "true" : "false";
}

int RunTest(){
	// Iterate through array Test
	for (auto& test: test_array)
	{
		// Create Infix2Postfix object: ob
		Infix2Postfix ob(test[0]);
		string program_output = ob.Convert();
  		// Compare the output with correct result
  		if( compare(test[1], program_output) == test[2] ){
  			cout << ".";
  		} else {
  			test_pass = false;
  			cout << "\n[!] Following Test is failing:\n";
  			cout << "[!] Test output: " << program_output << " Macthed with: " << test[1] << ". Should be " << test[2] << "\n"; 
  		}
	}
	return 0;
};


// Create the Object for class and run Tests
int main() {
  cout << "[*] Runing Tests\n";
  // Run Test
  RunTest();
  cout << (test_pass == true ? "\nAll Test Passed.\n" : "\nTest Failed.\n");
  return 0;
}
