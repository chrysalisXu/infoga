// Author: Jing Xu 7396120 shiyuchongf@gmail.com
#pragma once
#include <cstdlib>
#include <chrono>
#include <ctime> 
#include <vector>

using namespace std;

#define FLOAT_RAND_MAX static_cast <float> (RAND_MAX)

#define epsilon 0.0000001 

#define PI 3.1415926536f

namespace infoga_bonus {
    inline bool close_zero(const float a) { return (a <= epsilon) && (a >= 0 - epsilon); }

    struct Timer
    {
        Timer() { reset(); }
        float elapsed() const
        {
            chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - start);
            return (float)time_span.count();
        }
        void reset() { start = chrono::high_resolution_clock::now(); }
        chrono::high_resolution_clock::time_point start;
    };

    struct Point{
        float x;
        float y;
        Point(const float a, const float b) : x( a ), y( b ) {}
        float lengthSquare(){return x*x + y*y;}
    };

    struct PointSet{
        Point* data;
        int size; 
        void reset(){
            // free(data);
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

    inline bool operator== (const Point& a, const Point& b){
        return (a.x==b.x) && (a.y==b.y);
    }

    inline Point operator - (const Point& a, const Point& b){
        return Point(a.x-b.x, a.y-b.y);
    }

    inline float cross (const Point& a, const Point& b){
        return a.x * b.y - a.y * b.x;
    }

    inline float dot (const Point& a, const Point& b){
        return a.x * b.x + a.y * b.y;
    }

    float compareP (const Point& a, const Point& b){
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    }

    inline PointSet wrapToPointSet(const vector<Point> &vec)
    {
        PointSet res;
        res.size = vec.size();
        res.data = (Point *) calloc(res.size, sizeof(Point));
        memcpy(res.data, vec.data(), res.size * sizeof(Point));
        return res;
    }

}


