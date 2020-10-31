#include <iostream>
#include <string>

using namespace std;



int M(int x) {
    int y;
    if (x > 100) return (x - 10);
    else{
        y=M(x+11);
        return M(y);
    }
}

int main() {
    int x1=80;
    cout<<M(x1)<<endl;
    int x2=70;
    cout<<M(x2);
}
