
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
        
        stack<char> s1;
        char v=0;
        
        for(auto c:s){
            
            switch(c){
                    
                    case '[':
                    case '{':
                    case '(':
                        s1.push(c);
                        break;
                    case '}':
                        if(!s1.empty()){
                            v=s1.top();
                            s1.pop();
                        }
                        if(v!='{') return false;
                        v=0;
                        break;
                    case ']':
                        if(!s1.empty()){
                            v=s1.top();
                            s1.pop();
                        }
                        if(v!='[') return false;
                        v=0;
                        break;
                    case ')':
                        if(!s1.empty()){
                            v=s1.top();
                            s1.pop();
                        }
                        if(v!='(') return false;
                        v=0;
                        break;
                   default: return false;
            }            
        }
        
        return s1.empty();
        
    }

int main()
{
	bool matching = isValid("{([])}");
	cout << matching << " \n";
	return 0;
}
