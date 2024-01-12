// Author: Jing Xu 7396120 shiyuchongf@gmail.com

#include "utils.cpp"
#include <vector>
using namespace std;

namespace infoga_bonus {

    PointSet jarvisSolve(PointSet &dataset)
    {
        vector<Point> result;

        // find most left point
        result.push_back(dataset.data[0]);
        for(int i=1; i<dataset.size; i++){
            if(dataset.data[i].x < result[0].x){
                result.pop_back();
                result.push_back(dataset.data[i]);
            }
        }

        // warping until finish
        while((result.size() < 2) || (result[result.size()-1] != result[0])){
            // TODO
        }

        // filter out 3 point in single line

        // output
        PointSet res;
        res.size = result.size();
        res.data = (Point *) calloc(res.size, sizeof(Point));
        memcpy(res.data, result.data(), res.size * sizeof(Point));
        return res;
    }

}