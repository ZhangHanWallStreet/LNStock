//
//  LNChartAnimator.h
//  Market
//
//  Created by vvusu on 5/12/16.
//  Copyright © 2016 vvusu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>

typedef NS_ENUM(NSUInteger, LNAnimatorActionType) {
    LNAnimatorActionType_Pan = 0,
    LNAnimatorActionType_Pinch,
    LNAnimatorActionType_LongPress,
    LNAnimatorActionType_LeftAction,
    LNAnimatorActionType_RightAction
};

typedef void (^LNChartAnimatorBlock)(LNAnimatorActionType type, id empty, BOOL isStop);

@class LNChartData;
@interface LNChartAnimator : NSObject
@property (nonatomic, strong) LNChartData *data;
@property (nonatomic, copy) LNChartAnimatorBlock animatorBlock;
@property (nonatomic, assign, getter = isDragging) BOOL dragging;         //是否在拖拽
@property (nonatomic, assign, getter = isScrolling) BOOL scrolling;       //是否在滑动
@property (nonatomic, assign, getter = isDecelerating) BOOL decelerating; //是否在减速

+ (instancetype)setupWithData:(LNChartData *)data;
- (void)stopAnimation;
- (void)setupDefaultValue;
- (void)animationWithPanGestureRecognizer:(UIPanGestureRecognizer *)pan view:(UIView *)view;
- (void)animationWithPinchGestureRecognizer:(UIPinchGestureRecognizer *)pinch view:(UIView *)view;
- (void)animationWithLongPressGestureRecognizer:(UILongPressGestureRecognizer *)longPress view:(UIView *)view chartTyoe:(NSInteger)type;

@end
