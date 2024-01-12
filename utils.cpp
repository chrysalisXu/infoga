// Author: Jing Xu 7396120 shiyuchongf@gmail.com
#pragma once
#include <cstdlib>
#include <ctime> 

#define FLOAT_RAND_MAX static_cast <float> (RAND_MAX)

namespace infoga_bonus {
    struct Point{
        float x;
        float y;
        Point(const float a, const float b) : x( a ), y( b ) {}
        float lengthSquare(){return x*x + y*y;}
    };

    struct PointSet{
        Point* data;
        int size; 
        ~PointSet(){
            free(data);
            size = 0;
        }
    };

    // random float - [0, 1]
    inline float rand_float(){
        return static_cast <float> (rand()) / FLOAT_RAND_MAX;
    }

    inline bool operator!= (const Point& a, const Point& b){
        return (a.x!=b.x) || (a.y!=b.y);
    }

    inline Point operator - (const Point& a, const Point& b){
        return Point(a.x-b.x, a.y-b.y);
    }

    inline float cross (const Point& a, const Point& b){
        return a.x * b.y - a.y * b.x;
    }

}


