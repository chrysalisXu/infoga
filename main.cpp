// Author: Jing Xu 7396120 shiyuchongf@gmail.com

#include <iostream>
#include "utils.cpp"
#include "genData.cpp"
using namespace std;
using namespace infoga_bonus;

int main()
{
    PointSet data = genTestSet(5);
    for (int i=0; i<data.size; i++){
        cout << data.data[i].x << " " << data.data[i].y << endl;
    }
}