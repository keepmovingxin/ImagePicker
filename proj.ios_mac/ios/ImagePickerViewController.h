//
//  ImagePickerViewController.h
//  imagePicker
//
//  Created by babel_lgx on 2016/11/15.
//
//

#import <UIKit/UIKit.h>

@interface ImagePickerViewController : UIViewController<UINavigationControllerDelegate, UIImagePickerControllerDelegate>
{
    NSString* filePath;
}

// 打开本地相册
- (void)localPhoto;

// 打开相机
- (void)takePhoto;


@end
