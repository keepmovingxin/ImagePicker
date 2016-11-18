# ImagePicker

imagePicker utility for cocos2d-x 3.12 (iOS/Android)

cocos2d-x 调用系统相册或相机的测试，支持iOS和Android

Usage:

ImagePicker::getInstance()->callImagePickerWithPhotoAndCamera([=](std::string path) {
                                                                      // do Something
                                                                      CCLOG("image path:%s",path.c_str());
                                                                  });
