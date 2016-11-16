#include "HelloWorldScene.h"
#include "ImagePicker.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2*3.0f ,
                                origin.y + closeItem->getContentSize().height/2*3.0f));
    closeItem->setScale(3.0f);
    
    // add a "image" icon to exit the progress. it's an autorelease object
    auto imageItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuImageCallback, this));
    
    imageItem->setPosition(Vec2(origin.x + visibleSize.width - imageItem->getContentSize().width/2*3.0f ,
                                origin.y + visibleSize.height - imageItem->getContentSize().height/2*3.0f));
    imageItem->setScale(3.0f);

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem,imageItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("ImagePicker", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}

void HelloWorld::menuImageCallback(Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto label = Label::createWithTTF("Opened ImagePicker", "fonts/Marker Felt.ttf", 20);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height*2.2));
    label->setTag(1000);
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    //移除 Opened ImagePicker
    Sequence* seq = Sequence::createWithTwoActions(FadeOut::create(0.9), RemoveSelf::create());
    label->runAction(seq);
    
    ImagePicker::getInstance()->callImagePickerWithPhotoAndCamera([=](std::string path)
                                                                  {
                                                                      //做你想做的事情
                                                                      CCLOG("image path:%s",path.c_str());
                                                                  });
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
