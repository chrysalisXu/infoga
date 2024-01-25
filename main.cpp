// Author: Jing Xu 7396120 shiyuchongf@gmail.com

#include <iostream>
#include "utils.cpp"
#include "genData.cpp"
#include "validate.cpp"
#include "graham.cpp"
#include "jarvis.cpp"
using namespace std;
using namespace infoga_bonus;

void validate()
{
    bool res = ValidateAlgorithmCorrectness(jarvisSolve);
    if (!res) cout << "jarvis fail\n";
    else cout << "jarvis correct\n";
    res = ValidateAlgorithmCorrectness(grahamSolve);
    if (!res) cout << "graham fail\n";
    else cout << "graham correct\n";
}
void test()
{
    PointSet data[30];
    for (int i = 0; i < 10; i++) data[i] = genTestSet(1000);
    for (int i = 10; i < 20; i++) data[i] = genTestSet(2000);
    for (int i = 20; i < 30; i++) data[i] = genTestSet(4000);
    Timer t;
    t.reset();
    for (int i = 0; i < 10; i++) jarvisSolve(data[i]);
    cout << "jarvis normal 1000: "<< t.elapsed() * 100 << "ms"<< endl;
    t.reset();
    for (int i = 10; i < 20; i++) jarvisSolve(data[i]);
    cout << "jarvis normal 2000: "<< t.elapsed() * 100 << "ms"<< endl;
    t.reset();
    for (int i = 20; i < 30; i++) jarvisSolve(data[i]);
    cout << "jarvis normal 4000: "<< t.elapsed() * 100 << "ms"<< endl;
    t.reset();
    for (int i = 0; i < 10; i++) grahamSolve(data[i]);
    cout << "graham normal 1000: "<< t.elapsed() * 100 << "ms"<< endl;
    t.reset();
    for (int i = 10; i < 20; i++) grahamSolve(data[i]);
    cout << "graham normal 2000: "<< t.elapsed() * 100 << "ms"<< endl;
    t.reset();
    for (int i = 20; i < 30; i++) grahamSolve(data[i]);
    cout << "graham normal 4000: "<< t.elapsed() * 100 << "ms"<< endl;

    for (int i = 0; i < 10; i++) data[i] = genTestSetLowK(1000, 3);
    for (int i = 10; i < 20; i++) data[i] = genTestSetLowK(2000, 3);
    for (int i = 20; i < 30; i++) data[i] = genTestSetLowK(4000, 3);
    t.reset();
    for (int i = 0; i < 10; i++) jarvisSolve(data[i]);
    cout << "jarvis triangle 1000: " << t.elapsed() * 100 << "ms" << endl;
    t.reset();
    for (int i = 10; i < 20; i++) jarvisSolve(data[i]);
    cout << "jarvis triangle 2000: " << t.elapsed() * 100 << "ms" << endl;
    t.reset();
    for (int i = 20; i < 30; i++) jarvisSolve(data[i]);
    cout << "jarvis triangle 4000: " << t.elapsed() * 100 << "ms" << endl;
    t.reset();
    for (int i = 0; i < 10; i++) grahamSolve(data[i]);
    cout << "graham triangle 1000: " << t.elapsed() * 100 << "ms" << endl;
    t.reset();
    for (int i = 10; i < 20; i++) grahamSolve(data[i]);
    cout << "graham triangle 2000: " << t.elapsed() * 100 << "ms" << endl;
    t.reset();
    for (int i = 20; i < 30; i++) grahamSolve(data[i]);
    cout << "graham triangle 4000: " << t.elapsed() * 100 << "ms" << endl;

    for (int i = 0; i < 10; i++) data[i] = genTestSetHull(1000);
    for (int i = 10; i < 20; i++) data[i] = genTestSetHull(2000);
    for (int i = 20; i < 30; i++) data[i] = genTestSetHull(4000);
    t.reset();
    for (int i = 0; i < 10; i++) jarvisSolve(data[i]);
    cout << "jarvis hull 1000: " << t.elapsed() * 100 << "ms" << endl;
    t.reset();
    for (int i = 10; i < 20; i++) jarvisSolve(data[i]);
    cout << "jarvis hull 2000: " << t.elapsed() * 100 << "ms" << endl;
    t.reset();
    for (int i = 20; i < 30; i++) jarvisSolve(data[i]);
    cout << "jarvis hull 4000: " << t.elapsed() * 100 << "ms" << endl;
    t.reset();
    for (int i = 0; i < 10; i++) grahamSolve(data[i]);
    cout << "graham hull 1000: " << t.elapsed() * 100 << "ms" << endl;
    t.reset();
    for (int i = 10; i < 20; i++) grahamSolve(data[i]);
    cout << "graham hull 2000: " << t.elapsed() * 100 << "ms" << endl;
    t.reset();
    for (int i = 20; i < 30; i++) grahamSolve(data[i]);
    cout << "graham hull 4000: " << t.elapsed() * 100 << "ms" << endl;
}

int main()
{
    validate();
    test();
    return 0;
    // for (int i=0; i<data.size; i++) cout << data.data[i].x << " " << data.data[i].y << endl;
}
