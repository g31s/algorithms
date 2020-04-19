// Following code convert the Infix to Postfix notation. Following steps discribe the Algorithom
// Copied From: http://csis.pace.edu/~wolf/CS122/infix-postfix.htm
// 1. Print operands as they arrive.
// 2. If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
// 3. If the incoming symbol is a left parenthesis, push it on the stack.
// 4. If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.
// 5. If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
// 6. If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator.
// 7. If the incoming symbol has lower precedence than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.
// 8. At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Creating a calss.
class Infix2Postfix { 

  // Following methods are private for this class. All the steps are done privatly.
  private:
  	// Private variables
  	// Stack to store operators
  	stack<char> opstack;

  	//Private Functions
  	int GetOperatorWeight(char op);

  	void IterateString();
  	void PopStackUntilLeftParenthesis();
  	void PopStackUntilEmpty();
  	
  	bool IsOperator(char C);
  	bool IsPresHigh(char stacktop,char nextchar);
  
  // Following methods and parameters are public.
  public:
  	// Public variables
  	// input_infix is the user input set at constructor.
  	string input_infix;
  	// postfix is the output this function returns.
  	string postfix;

  	// Contructor: have to submit user input when creating class object.
  	Infix2Postfix(string user_input);
  	// Function start the all steps defined above and are in private class.
    string Convert();

    //Helper Function design to understand what is going on at each step.
    bool debug  = false;
    void Debug(bool value);
    void PrintHelper(int step_value);
    string PrintStack();
};

// ------------ HELPER FUNCTIONS ------------------
// Helper Functions to see what is going on in stack and postfix string
string Infix2Postfix::PrintStack(){
	stack<char> opstack_copy;
	opstack_copy = opstack;
	string result;
	while(!opstack_copy.empty()) //body
    { 
    	result += opstack_copy.top();
   		opstack_copy.pop();
    }
    return result;
}

// Print the Stack and Postfix values
void Infix2Postfix::PrintHelper(int step_value){
	cout << "\n===Step: " << to_string(step_value) << "=====\n";
	cout << "=       top\n";
	cout << "=        |\n";
	cout << "= Stack: ";
	cout << PrintStack();
	cout << "\n= Postfix: " << postfix;
	cout << "\n===============\n";
}

// Set the value for debug option.
void Infix2Postfix::Debug(bool value){
	debug = value;
}

// ------------- END ---------------

// H Empty the stack till it's empty
void Infix2Postfix::PopStackUntilEmpty(){
	// Add what is remaining on stack to postfix
	while(!opstack.empty()){ 
    	postfix += opstack.top();
   		opstack.pop();
    }
}

// G Set the Weight for each operator
int Infix2Postfix::GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op) {
		case '+':
		case '-':
			weight = 1;
			break;
		case '*':
		case '/':
			weight = 2;
			break;
		case '^':
			weight = 3;
			break;
	}
	return weight;
}

// F Check the precedence between top of stack and incoming character
bool Infix2Postfix::IsPresHigh(char stacktop,char nextchar){
	// Get the operator weight and assing the value to new variables
	int nextchar_weight = GetOperatorWeight(nextchar);
	int stacktop_weight = GetOperatorWeight(stacktop);
	if (nextchar_weight == stacktop_weight) {
		// Assuming it all will be left association. if right association false return can be sent.
		return true;
	}
	return ((stacktop_weight > nextchar_weight ) ? true : false);

}

// E Pop the stack till Left Parenthesis is reachd. 
void Infix2Postfix::PopStackUntilLeftParenthesis(){
	while(opstack.top() != '('){
		postfix += opstack.top();
		opstack.pop();
	}
	opstack.pop(); // pop the left parenthesis in the end
}

// D Check if the character is operator or not.
bool Infix2Postfix::IsOperator(char C) {
	return (C == '+' || C == '-' || C == '*' || C == '/' ) ? true :false;
}

//C Iterate through each character in the string
void Infix2Postfix::IterateString() {
	// for loop to go through the each character in the string 
	for (int i = 0; i < input_infix.length(); ++i){ 
		if (IsOperator(input_infix[i])){ // Check if the character is operator 
			while(!opstack.empty() && (opstack.top() != '(')  && IsPresHigh(opstack.top(),input_infix[i]) ) { // Step 2 and 5
				postfix += opstack.top();
				opstack.pop();
			}
			opstack.push(input_infix[i]);
		} else if (input_infix[i] == '(') { // Step 3
			opstack.push(input_infix[i]);
		} else if (input_infix[i] == ')'){ // Step 4
			PopStackUntilLeftParenthesis();
		} else { // If nothing matches add to postfix
			postfix += input_infix[i];
		}
		// If the Debug option is set to true print stack values:
		if (debug) PrintHelper(i+1);
	}

	// Empty the stack it's unitl it's empty
	PopStackUntilEmpty();
}

// B The public "convert" start all the steps.
string Infix2Postfix::Convert() {
	IterateString();
	return postfix;
}

// A Constructor to get user_input and set it as instance variable.
Infix2Postfix::Infix2Postfix(string user_input) { 
	input_infix = user_input;
}