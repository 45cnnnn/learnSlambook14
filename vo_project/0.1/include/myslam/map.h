// map类中储存了各个关键帧和路标点，既需要随机访问，又需要随时插入和删除
#ifndef MAP_H
#define MAP_H

#include "myslam/common_include.h"
#include "myslam/frame.h"
#include "myslam/mappoint.h"

namespace myslam
{
    class Map
    {
    public:
        typedef shared_ptr<Map> Ptr;
        unordered_map<unsigned long, MapPoint::Ptr> map_points_; //all landmarks
        unordered_map<unsigned long, Frame::Ptr> keyframes_;    // all key-frames

        Map() {}

        void insertKeyFrame(Frame::Ptr frame);
        void insertMapPoint(MapPoint::Ptr map_point);
        
    };
}

#endif