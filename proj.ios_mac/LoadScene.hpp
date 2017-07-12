//
//  LoadScene.hpp
//  HunterAndSnake
//
//  Created by zeyong shan on 7/11/17.
//
//

#ifndef LoadScene_hpp
#define LoadScene_hpp


class LoadScene: public cocos2d::Scene
{
public:
    static LoadScene* create(int gameSceneType);
    LoadScene(int gameSceneType);
    virtual bool init();
private:
    cocos2d::Sprite* background;
    cocos2d::Sprite* shipAndBall;
    cocos2d::Sprite* loadingBlue;
    cocos2d::Label*  loadingLabel;
    std::function<void (cocos2d::Texture2D*)> loadCallBack;
    int pictureNumTotal;
    int pictureNumCurrent;
    int gameSceneType;
    std::mutex mutex;
    
    
    void initItems();
    void initCallBackFunc();
};

#endif /* LoadScene_hpp */
