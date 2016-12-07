//
//  DeviceInfo.h
//  TestDeviceInfo
//
//  Created by niuzhongliang on 2016/12/7.
//  Copyright © 2016年 niuzhongliang. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface DeviceInfo : NSObject

/** 系统版本号，eg：10.0.2 */
+ (NSString *)getOSVersion;

/** 系统名称，eg：iOS */
+ (NSString *)getSystemName;

/** 设备型号，eg：iPhone6 | iPhone6 plus */
+ (NSString *)getDeviceModel;

/** 内存信息，eg:总内存，可用内存 */
+ (NSString *)getMemoryInfo;

/** 存储信息，eg：总容量，可用容量 */
+ (uint64_t)getFreeDiskspace;

@end
