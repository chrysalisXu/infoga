// Author: Jing Xu 7396120 shiyuchongf@gmail.com
#pragma once
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <algorithm>
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

    PointSet genTestSetHull(int size){
        PointSet result;
        result.size = size;
        result.data = (Point *) malloc(size * sizeof(Point));
        srand(time(0));
        float start_angle = 0, start_distance = 100;
        for(int i=0; i<size; i++){
            start_angle = 2 * PI * (((float)i + rand_float())/size);
            result.data[i].x = cosf(start_angle) * start_distance;
            result.data[i].y = sinf(start_angle) * start_distance;
        }
        std::random_shuffle(&result.data[0], & result.data[size-1]);
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

        float weight;
        float sum_weight;
        for(int i=maxGroundTruth; i<size; i++){
            sum_weight = 0;
            for(int j=0; j<maxGroundTruth; j++){
                weight = rand_float();
                sum_weight += weight;
                result.data[i].x += weight * result.data[j].x;
                result.data[i].y += weight * result.data[j].y;
            }
            result.data[i].x /= sum_weight;
            result.data[i].y /= sum_weight;
        }
        return result;
    }

    // avoid float accuracy lost
    void pushbackSetCopy(PointSet& target, int addSize){
        Point * new_data = (Point *) calloc(target.size + addSize, sizeof(Point));
        memcpy(new_data, target.data, target.size * sizeof(Point));
        for (int i=0; i<addSize; i++){
            new_data[i+target.size].x = target.data[i % target.size].x;
            new_data[i+target.size].y = target.data[i % target.size].y;
        }
        free(target.data);
        target.data = new_data;
        target.size = target.size + addSize;
    }

    void pushbackrand(PointSet& target, int addSize){
        Point * new_data = (Point *) calloc(target.size + addSize, sizeof(Point));
        memcpy(new_data, target.data, target.size * sizeof(Point));
        srand(time(0));
        for (int i=0; i<addSize; i++){
            new_data[i+target.size].x = rand_float();
            new_data[i+target.size].y = rand_float();
        }
        free(target.data);
        target.data = new_data;
        target.size = target.size + addSize;
    }

    PointSet readTestCase(const char* dataFile){
        PointSet result;
        FILE* file = fopen( dataFile, "r" );
        if (!file) { 
            result.size = 0;
            return result;
        }
        char line[512] = { 0 };
        fgets( line, 511, file );
        sscanf(line, "%d", &(result.size));
        result.data = (Point *) malloc(result.size * sizeof(Point));

        int i = 0;
        while (!feof( file ))
        {
            fgets( line, 511, file );
            sscanf(line, "%f %f", &(result.data[i].x), &(result.data[i].y));
            i++;
        }
        return result;
    }
}


