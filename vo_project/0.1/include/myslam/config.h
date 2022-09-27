// config类负责参数文件的读取，并在程序任意地方都可以随时提供参数的值
// Singleton 模式，只有一个全局对象，当我们设置参数文件时，创建该对象并读取参数文件，
// 随后可以再任意地方访问参数值，最后在程序结束时自动销毁
#ifndef CONFIG_H
#define CONFIG_H

#include "myslam/common_include.h"

namespace myslam
{
    class Config
    {
        private:
            static std::shared_ptr<Config> config_;
            cv::FileStorage file_;

            Config() {} //private constructor makes a singleton
        public:
            ~Config();  // close the file when deconstructing

            // set a new config file
            static void setParameterFile(const std::string& filename);

            // access the parameter values
            template<typename T>
            static T get(const std::string& key)
            {
                return T(Config::config_->file_[key]);
            }
    };       
}

#endif