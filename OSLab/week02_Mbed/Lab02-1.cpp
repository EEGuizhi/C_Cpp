#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> s;
	stack<int> tmp;
	
	int t;
	string cmd;
	
	while(cin >> cmd) {
		if(cmd == "push") {
			int x;
			cin >> x;
			s.push(x);
		}
		else if(cmd == "pop") {
			if(s.empty()) {
				cout << "error: stack is empty" << endl;
			}
			else {
				s.pop();
			}
		}
		else if(cmd == "top") {
			if(s.empty()) {
				cout << "error: stack is empty" << endl;
			}
			else {
				cout << s.top() << endl;
			}
		}
		else if(cmd == "empty") {
			cout << (s.empty() ? "true" : "false") << endl;
		}
		else if(cmd == "getMin") {
			if(s.empty()) {
				cout << "error: stack is empty" << endl;
			}
			else {
				t = s.top();
				tmp.push(s.top());
				s.pop();
				while(s.empty() == 0) {
					if(s.top() < t)
						t = s.top();
					tmp.push(s.top());
					s.pop();
				}
				while(tmp.empty() == 0) {
					s.push(tmp.top());
					tmp.pop();
				}
				cout << t << endl;
			}
		}
		else {
			cout << "error: invalid command" << endl;
		}
	}
	
	return 0;
}
