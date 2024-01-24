// Author: Jing Xu 7396120 shiyuchongf@gmail.com

#include "utils.cpp"
#include <vector>
using namespace std;

namespace infoga_bonus {

    PointSet jarvisSolve(PointSet &dataset)
    {
        vector<Point> result;
        if (dataset.size == 0) return wrapToPointSet(result);

        // find most left point
        result.push_back(dataset.data[0]);
        bool single_point = true;
        for(int i=1; i<dataset.size; i++){
            if (dataset.data[i] != result[0]) single_point = false;
            if((dataset.data[i].x < result[0].x) || ((dataset.data[i].x == result[0].x) && (dataset.data[i].y < result[0].y))){
                result.pop_back();
                result.push_back(dataset.data[i]);
            }
        }
        if (single_point) return wrapToPointSet(result);

        // warping until finish
        while((result.size() < 2) || (result[result.size()-1] != result[0])){
            // TODO
            int start_id = result.size()-1;
            for(int i=0; i<dataset.size; i++)
            {
                if (dataset.data[i] == result[start_id]) continue;
                if (start_id == result.size()-1) result.push_back(dataset.data[i]);
                Point cur_vector = dataset.data[i] - result[start_id];
                Point pre_vector = result[start_id+1] - result[start_id];
                float sign = cross(pre_vector, cur_vector);
                if ((sign < 0) || ((sign == 0) && (cur_vector.lengthSquare() > pre_vector.lengthSquare())))
                {
                    result.pop_back();
                    result.push_back(dataset.data[i]);
                }
            }
        }
        result.pop_back();

        // output
        return wrapToPointSet(result);
    }

}