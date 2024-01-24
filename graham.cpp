// Author: Jing Xu 7396120 shiyuchongf@gmail.com
#include "utils.cpp"
#include <vector>
#include <algorithm>
using namespace std;


namespace infoga_bonus {

    PointSet grahamSolve(PointSet &dataset)
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

        vector<Point> sortedData(dataset.data, dataset.data + dataset.size);
        sort (sortedData.begin(), sortedData.end(), compareP);
        // get half
        for(int i=0; i<sortedData.size(); i++)
        {
            if (sortedData[i] == result[result.size()-1]) continue;
            result.push_back(sortedData[i]);
            int start_id = result.size()-3;
            while (start_id >= 0){
                Point cur_vector = result[start_id+2] - result[start_id+1];
                Point pre_vector = result[start_id+1] - result[start_id];
                float sign = cross(cur_vector, pre_vector);
                if (sign <= 0)
                {
                    result.erase(result.begin() + start_id + 1);
                    start_id --;
                }
                else break;
            }
        }
        // another half
        int stable_result_num = result.size();
        for (int i = sortedData.size()-1; i >=0 ; i--) 
        {
            if (sortedData[i] == result[result.size() - 1]) continue;
            result.push_back(sortedData[i]);
            int start_id = result.size() - 3;
            while (start_id >= stable_result_num-1) {
                Point cur_vector = result[start_id + 2] - result[start_id + 1];
                Point pre_vector = result[start_id + 1] - result[start_id];
                float sign = cross(cur_vector, pre_vector);
                if (sign <= 0)
                {
                    result.erase(result.begin() + start_id + 1);
                    start_id--;
                }
                else break;
            }
        }

        result.pop_back();

        // output
        return wrapToPointSet(result);
    }
}