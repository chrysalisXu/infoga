// Author: Jing Xu 7396120 shiyuchongf@gmail.com

#include <iostream>
#include "utils.cpp"
#include "genData.cpp"
#include "validate.cpp"
#include "graham.cpp"
#include "jarvis.cpp"
using namespace std;
using namespace infoga_bonus;

int main()
{
    bool res = ValidateAlgorithmCorrectness(jarvisSolve);
    if (!res) cout << "jarvis fail\n";
    else cout << "jarvis correct\n";
    res = ValidateAlgorithmCorrectness(grahamSolve);
    if (!res) cout << "graham fail\n";
    else cout << "graham correct\n";
    return 0;
    // for (int i=0; i<data.size; i++) cout << data.data[i].x << " " << data.data[i].y << endl;
}