//
//  NSViewMy.h
//  OSXWindowEvents
//
//  Created by Zaqro Butskhrikidze on 9/12/14.
//  Copyright (c) 2014 Zaqro Butskhrikidze. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSViewMy : NSView

-(void)initializeMercuryView:(NSRect)rcView wnd:(NSWindow*)wnd;
-(void)resizeEvent:(NSSize)frameSize;

@end
