// Author: Jing Xu 7396120 shiyuchongf@gmail.com
#include "genData.cpp"
#include "utils.cpp"

namespace infoga_bonus{
    bool validateCorrectness(PointSet &dataset, PointSet &result){
        if (result.size == 1){
            for (int i=0; i<dataset.size; i++){
                if (dataset.data[i]!= result.data[1])
                    return false;
            }
            return true;
        }

        for (int start=0; start<result.size; start++){
            int end = (start + 1) % result.size;
            Point cur_vector = result.data[end] - result.data[start];
            if ((cur_vector.x == cur_vector.y) && (cur_vector.x == 0))
                return false; // duplicate point
            float sign = 0;
            for (int i=0; i<dataset.size; i++){
                float cur_cross = cross(dataset.data[i] - result.data[start], cur_vector);
                if (sign == 0)
                    sign = cur_cross;
                if (sign * cur_cross < 0)
                    return false;
                if (sign * cur_cross == 0){
                    float ratio = (dataset.data[i] - result.data[start]).lengthSquare() / cur_vector.lengthSquare();
                    if ((ratio > 1) || (ratio < 0)) return false; // 3 point same line
                }
            }
        }
        return true;
    }

    bool ValidateAlgorithmCorrectness(PointSet (*algo)(PointSet&)){
        // general case
        for (int i=0; i<20; i++){
            PointSet testset = genTestSet(100);
            if (i%3==0) pushbackSetCopy(testset, 5); // add some duplicate points
            if (!validateCorrectness(testset, algo(testset)));
                return false;
        }

        // one point 
        PointSet testset = genTestSet(1);
        if (!validateCorrectness(testset, algo(testset)));
                return false;
        pushbackSetCopy(testset, 1);
        if (!validateCorrectness(testset, algo(testset)));
                return false;
        pushbackSetCopy(testset, 20);
        if (!validateCorrectness(testset, algo(testset)));
                return false;

        // 2 point
        testset = genTestSet(2);
        if (!validateCorrectness(testset, algo(testset)));
                return false;
        pushbackSetCopy(testset, 1);
        if (!validateCorrectness(testset, algo(testset)));
                return false;
        pushbackSetCopy(testset, 20);
        if (!validateCorrectness(testset, algo(testset)));
                return false;

        // line
        for (int i=0; i<4; i++){
            testset = genTestSetLowK(100,2);
            if (!validateCorrectness(testset, algo(testset)));
                return false;
        }
        for (int i=0; i<4; i++){
            testset = genTestSetLowK(80,2);
            pushbackrand(testset, 20);
            if (!validateCorrectness(testset, algo(testset)));
                return false;
        }

        // a big test case
        testset = genTestSet(2000);
        if (!validateCorrectness(testset, algo(testset)));
                return false;

        return true;
        
    }

}
