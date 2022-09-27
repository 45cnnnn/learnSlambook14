// mappoint表示路标点，将估计它的世界坐标
// 并且会拿当前帧提取到的特征点与地图中的路标点匹配，来估计相机的运动
// 因此还需要储存它对应的descriptor
// 此外还要记录一个点被观测到的次数和被匹配的次数，作为评价好坏程度的指标
#ifndef MAPPOINT_H
#define MAPPOINT_H

#include "myslam/common_include.h"
#include "myslam/frame.h"

namespace myslam
{
    class Frame;
    class MapPoint
    {
    public:
        typedef std::shared_ptr<MapPoint> Ptr;
        unsigned long id_;      // ID
        Vector3d pos_;            // Posion in the world
        Vector3d norm_;         // Normal of viewing direction
        Mat descriptor_;         // Descriptor for matching
        int obeserved_times_; // being observed by feature matching logo
        int correct_times_;        // being an inliner in pose estimation

        MapPoint();
        MapPoint(long id, Vector3d position, Vector3d norm);

        // factory function
        static MapPoint::Ptr creatMapPoint();
    };

}

#endif