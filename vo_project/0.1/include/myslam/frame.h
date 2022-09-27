// frame.h 中定义了ID，时间戳，位姿，相机，图像

#ifndef FRAME_H
#define FRAME_H

#include "myslam/common_include.h"
#include "myslam/camera.h" 

namespace myslam
{
    class Frame
    {
    public:
        typedef std::shared_ptr<Frame> Ptr;  
        unsigned long id_;                                      // id of this frame
        double time_step_;                                    // when it is recorded
        SE3<double> T_c_w_;                                                    // transform from world to camera
        Camera::Ptr camera_;                                // pinhole RGBD Camera model
        Mat color_, depth_;                                    // color and depth image
    
    public: // data members
        Frame();
        Frame(long id, double time_step = 0, SE3<double> T_c_w=SE3<double>(), Camera::Ptr camera = nullptr, Mat color = Mat(), Mat depth = Mat());
        ~Frame();

        // factory function
        static Frame::Ptr creatFrame();

        // find the depth in depth map
        double findDepth(const cv::KeyPoint& kp);

        // get camera center
        Vector3d getCamCenter() const;

        //  check if a point is in this frame
        bool isInFrame(const Vector3d& pt_world);

    };
}

#endif