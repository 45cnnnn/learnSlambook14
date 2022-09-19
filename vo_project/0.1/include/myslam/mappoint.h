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