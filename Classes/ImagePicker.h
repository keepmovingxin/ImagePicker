//
//  ImagePicker.h
//  imagePicker
//
//  Created by babel_lgx on 2016/11/15.
//
//

#ifndef ImagePicker_h
#define ImagePicker_h

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#endif	// CC_PLATFORM_ANDROID

/**
 * 图像选择器
 */
class ImagePicker
{
public:
    // 获取选择器单例
    static ImagePicker* getInstance();
    
    // 销毁
    static void destoryInstance();
public:
    // 显示本地相册与相机选择器
    void callImagePickerWithPhotoAndCamera(const std::function<void(std::string)>& callback);
    
    // 设置监听
    void setListener(const std::function<void(std::string)>& callback);
    
    // 移除监听
    void removeListener();
    
    // 打开相册
    void openPhoto();
    
    // 打开相机
    void openCamera();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // 设置AppController
    void setViewController(void* viewController);
#endif // CC_PLATFORM_IOS
    
protected:
    // 初始化
    bool init();
    
    ImagePicker();
    
protected:
    std::function<void(std::string)> m_callback;
    static ImagePicker* s_instance;
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    void* m_viewController;
#endif // CC_PLATFORM_IOS
    
};

#endif /* ImagePicker_h */
