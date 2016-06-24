//
//  YXNDHTTP.h
//  YXNetworkDiagnose
//
//  Created by YourtionGuo on 6/24/16.
//  Copyright © 2016 Yourtion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YXNDProtocols.h"

@interface YXNDHttpResult : NSObject

@property (readonly) NSInteger code;
@property (readonly) NSTimeInterval duration;
@property (readonly) NSDictionary* headers;
@property (readonly) NSData* body;

- (NSString*)description;

@end

typedef void (^YXNDHttpCompleteHandler)(YXNDHttpResult*);

@interface YXNDHttp : NSObject <YXNDStopDelegate>

/**
 *    default port is 80
 *
 *    @param host     domain or ip
 *    @param output   output logger
 *    @param complete complete callback, maybe null
 *
 *    @return YXNDTcpping instance, could be stop
 */
+ (instancetype)start:(NSString*)url
               output:(id<YXNDOutputDelegate>)output
             complete:(YXNDHttpCompleteHandler)complete;

@end
