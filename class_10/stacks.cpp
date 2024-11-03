#include "include/stack.hpp"

int main(){
    stack st;
    st.push(80);
    st.push(90);
    st.push(100);
    st.push(600);
    st.pop();
    std::cout << st.top() << "\n";
    return 0;
}