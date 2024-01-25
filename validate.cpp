// Author: Jing Xu 7396120 shiyuchongf@gmail.com
#include "genData.cpp"
#include "utils.cpp"

namespace infoga_bonus{
    bool validateCorrectness(PointSet &dataset, PointSet &result){
        // for (int i = 0; i < result.size; i++) cout << result.data[i].x << " " << result.data[i].y << endl;
        if (result.size == 1){
            for (int i=0; i<dataset.size; i++){
                if (dataset.data[i]!= result.data[0])
                    return false;
            }
            return true;
        }

        for (int start=0; start<result.size; start++){
            int end = (start + 1) % result.size;
            Point cur_vector = result.data[end] - result.data[start];
            if ((cur_vector.x == cur_vector.y) && (cur_vector.x == 0)) {
                return false; // duplicate point
            }
            float sign = 0;
            for (int i=0; i<dataset.size; i++){
                float cur_cross = cross(dataset.data[i] - result.data[start], cur_vector);
                if (sign == 0)
                    sign = cur_cross;
                if (sign * cur_cross < -epsilon) {
                    return false;
                }
                if (close_zero(sign * cur_cross)){
                    float ratio = (dataset.data[i] - result.data[start]).lengthSquare() / cur_vector.lengthSquare();
                    if (ratio > 1) {
                        return false; // 3 point same line
                    }
                }
            }
        }
        return true;
    }

    bool ValidateAlgorithmCorrectness(PointSet (*algo)(PointSet&)){
        PointSet testset, solution;
        // manual test cases.
        testset = readTestCase("../testcases/test.txt");
        solution = algo(testset);
        for (int i = 0; i < solution.size; i++) cout << solution.data[i].x << " " << solution.data[i].y << endl;
        if (!validateCorrectness(testset, algo(testset)))
            return false;
        testset.reset();

        // general case
        for (int i=0; i<20; i++){
            testset = genTestSet(100);
            if (i%3==0) pushbackSetCopy(testset, 5); // add some duplicate points
            if (!validateCorrectness(testset, algo(testset)))
                return false;
            testset.reset();
        }

        // one point 
        testset = genTestSet(1);
        if (!validateCorrectness(testset, algo(testset)))
                return false;
        pushbackSetCopy(testset, 1);
        if (!validateCorrectness(testset, algo(testset)))
                return false;
        pushbackSetCopy(testset, 20);
        if (!validateCorrectness(testset, algo(testset)))
                return false;
        testset.reset();

        // 2 point
        testset = genTestSet(2);
        if (!validateCorrectness(testset, algo(testset)))
                return false;
        pushbackSetCopy(testset, 1);
        if (!validateCorrectness(testset, algo(testset)))
                return false;
        pushbackSetCopy(testset, 20);
        if (!validateCorrectness(testset, algo(testset)))
                return false;
        testset.reset();

        // line
        for (int i=0; i<4; i++){
            testset = genTestSetLowK(100,2);
            if (i%2 == 0) pushbackSetCopy(testset, 10);
            if (!validateCorrectness(testset, algo(testset)))
                return false;
        }

        // general 
        for (int i=0; i<4; i++){
            testset = genTestSetLowK(80,2);
            pushbackrand(testset, 20);
            if (!validateCorrectness(testset, algo(testset)))
                return false;
            testset.reset();
        }

        // a big test case
        testset = genTestSet(2000);
        if (!validateCorrectness(testset, algo(testset)))
                return false;
        testset.reset();

        return true;
        
    }

}
