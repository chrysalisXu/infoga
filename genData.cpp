// Author: Jing Xu 7396120 shiyuchongf@gmail.com
#include <cstdlib>
#include <ctime> 
#include "utils.cpp"

namespace infoga_bonus {

    // gen test set, x - [0, 1], y - [0, 1]
    PointSet genTestSet(int size){
        PointSet result;
        result.size = size;
        result.data = (Point *) malloc(size * sizeof(Point));
        srand(time(0));
        for(int i=0; i<size; i++){
            result.data[i].x = rand_float();
            result.data[i].y = rand_float();
        }
        return result;
    }

    // gen testset with ground truth with vertices number <= maxGroundTruth
    PointSet genTestSetLowK(int size, int maxGroundTruth){
        PointSet result;
        result.size = size;
        result.data = (Point *) calloc(size, sizeof(Point));
        srand(time(0));
        for(int i=0; i<maxGroundTruth; i++){
            result.data[i].x = rand_float();
            result.data[i].y = rand_float();
        }

        int weight;
        for(int i=maxGroundTruth; i<size; i++){
            for(int j=0; j<maxGroundTruth; j++){
                weight = rand_float();
                result.data[i].x += weight * result.data[j].x;
                result.data[i].y += weight * result.data[j].y;
            }
        }
        return result;
    }

}


