#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack <int> st;
    int i = 0;

    cout << "Input first nums:\n";

    while(i != 10){
        int a;
        cin >> a;
        st.push(a);
        i++;
    }

    if (st.empty())
        cout << "Stack is not empty\n";

    cout << "Last elem stack: " << st.top() << "\n";
    cout << "Del last elem\n";
    st.pop();
    cout << "New last elem: " << st.top() << "\n";

    return 0;
}