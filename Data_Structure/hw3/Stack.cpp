// 4109061012  Homework 3 programming exercise
#include <cstdlib>
#include <iostream>

using namespace std;

class NStack {
    public:
        NStack(int capacity=10);
        ~NStack();

        int Pop();
        void Push(int d);

        bool IsEmpty();
        bool Remove(NStack &s, int num);
        void Output(NStack &s);
        void Sort(NStack &s);

    private:
        void Resize();
        int top, size;
        int *narray;
};

NStack::NStack(int capacity) {
    if(capacity < 1) throw "Stack capacity must be > 0.";
    narray = new int[capacity];
    size = capacity;
    top = -1;
}

NStack::~NStack() {
    delete [] narray;
}

int NStack::Pop() {
    if(IsEmpty()) throw "Stack is empty. cannot delete.";
    return narray[top--];
}

void NStack::Push(int d) {
    if(top+1 == size)
        Resize();
    narray[++top] = d;
}

bool NStack::IsEmpty() {
    if(top < 0)
        return true;
    else
        return false;
}

bool NStack::Remove(NStack &s, int num) {
    NStack tmp;
    int pop_num;
    bool flag = false;
    while(!s.IsEmpty()) {
        pop_num = s.Pop();
        if(pop_num != num)
            tmp.Push(pop_num);
        else
            flag = true;
    }
    while(!tmp.IsEmpty())
        s.Push(tmp.Pop());

    return flag;
}

void NStack::Output(NStack &s) {
    int num;
    NStack tmp;
    while(!s.IsEmpty())
        tmp.Push(s.Pop());
    while(!tmp.IsEmpty()) {
        num = tmp.Pop();
        s.Push(num);
        printf("%d ", num);
    }
    printf("\n");
}

void NStack::Sort(NStack &s) {
    int s_top, tmp_top, num;
    NStack tmp;
    while(!s.IsEmpty()) {
        s_top = s.Pop();
        num = s_top;
        while(!tmp.IsEmpty() && tmp_top < num) {
            tmp_top = tmp.Pop();
            s.Push(tmp_top);
            s_top = tmp_top;
        }
        tmp.Push(num);
        tmp_top = num;
    }
    while(!tmp.IsEmpty())
        s.Push(tmp.Pop());
}

void NStack::Resize() {
    int *tmp = new int[size * 2];
    for(int i=0; i<=top; i++)
        tmp[i] = narray[i];
    delete [] narray;
    narray = tmp;
}



int main() {
    NStack s;
	int num = 0, option = 0;

	while(num != -1) {
		printf("Input a positive interger (-1 to end): ");
        scanf(" %d", &num);
        if(num != -1)
            s.Push(num);
	}

	while(option != 4) {
		printf("\nOptions >>  1) Output.  2) Remove.  3) Sort.  4) Quit. : ");
		scanf(" %d", &option);
		switch(option) {
			case 1:
				s.Output(s);
				break;
			case 2:
                bool success;
				printf("Number to remove: ");
				scanf(" %d", &num);
				success = s.Remove(s, num);
                if(success) {
                    printf("%d is deleted!\n", num);
                    s.Output(s);
                }
                else
                    printf("Not found!\n");
				break;
			case 3:
				s.Sort(s);
				s.Output(s);
				break;
			default:
				break;
		}
	}

    return 0;
}
