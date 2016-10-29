//
//  MyModalView.m
//  WindowCreationApp
//
//  Created by Zaqro Butskrikidze on 10/15/16.
//  Copyright © 2016 zaqro butskrikidze. All rights reserved.
//

#import "NSWindowFrameView.h"
#include "../MercuryBaseWnd.h"

@interface NSWindowFrameView()
{
@protected
    MercuryBaseView* _pMercuryView;
    MercuryBaseView* _pMercuryViewToDisplay;
}

@end

@implementation NSWindowFrameView

/*
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}*/

-(void)drawRect:(NSRect)rect
{
    NSLog(@"redraw %f %f %f %f", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
    CGContextRef context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
    if( _pMercuryView != NULL )
    {
        _Rect rcDraw(rect.origin.x, rect.origin.y, (rect.origin.x + rect.size.width), (rect.origin.y + rect.size.height));
        _pMercuryView->OnPaint(context, rcDraw);
    }
}

-(id)initWithFrame:(NSRect)frameRect
{
    self = [super initWithFrame:frameRect];
    return self;
}

-(void)viewDidMoveToWindow
{
    [super viewDidMoveToWindow];
    
    // Initialize mercury view.
    //[self initializeMercuryView:CGRectMake(0.0, 0.0, 0.0, 0.0) wnd:nil];
}

-(void)initializeMercuryView:(NSRect)rcView wnd:(NSWindow*)wnd mercuryView:(MercuryBaseView*) pMercuryView;
{
    if( _pMercuryView == NULL )
    {
        NSTrackingAreaOptions options = (NSTrackingActiveAlways | NSTrackingInVisibleRect | NSTrackingMouseEnteredAndExited | NSTrackingMouseMoved);
        NSTrackingArea *area = [[NSTrackingArea alloc] initWithRect:[self bounds] options:options owner:self userInfo:nil];
        [self addTrackingArea: area];
        
        _pMercuryView = pMercuryView == NULL ? new MercuryBaseView() : pMercuryView;
        _pMercuryView->SetHWND(self);
        _pMercuryView->SetDesignerMode(true);
        _pMercuryViewToDisplay = NULL;
        
        /*
         _string arrCOntrolNames[] = {
         _T("ESChildControlLabel"),
         _T("ESChildControlImage"),
         _T("ESChildControlImageButton"),
         _T("ESChildControlList"),
         _T("ESChildTextBox"),
         _T("ESChildControlTabCtrl"),
         _T("ESChildBanner"),
         _T("ESChildControlCheckBox"),
         _T("ESChildScrollBar"),
         _T("ESChildTabView"),
         _T("ESChildComboBox"),
         _T("ESSimpleRenderView"),
         _T("ESChildSlider"),
         _T("ESChildControlPropertyGrid"),
         _T("ESChildProgressCtrl"),
         _T("ESChildAvatar"),
         };
         
         for(int i=0; i<sizeof(arrCOntrolNames)/sizeof(_string); i++){
         ESChildControl* p = ESChildControl::GetChildClassInstance(arrCOntrolNames[i]);
         p->GetVariableInfo(_T("A"));
         }*/
        
        //_string designFile = _T("design/Lobby.des");
        //designFile = _T("TournamentLobby.des");
        //_string designFile = _T("/Volumes/OSX/Users/ZqrTalent/Desktop/Dev/design/Lobby.des");
        //_string designFile = _T("/Volumes/OSX-DATA/Dev/ESPoker_06.01.2014/_bin/ESPokerClient_Debug/design/LoginDialog.des");
        //_pMercuryView->LoadFromDesignFile(designFile);
        [self setNeedsDisplay:YES];
    }
}

-(void)resizeEvent:(NSSize)frameSize
{
    if( _pMercuryView != NULL )
    {
        //_pMercuryView->OnSize(0, (int)frameSize.width, (int)frameSize.height);
        _pMercuryView->OnSize(0, (int)[self frame].size.width, (int)[self frame].size.height);
        [self setNeedsDisplay:YES]; // Redraw view
    }
    else
    {
        //[self initializeMercuryView:self.frame wnd:[self window]];
    }
}

-(BOOL)isFlipped
{
    return YES;
}

-(void)mouseMoved:(NSEvent *)theEvent
{
    [super mouseMoved:theEvent];
    if(_pMercuryView != NULL)
    {
        int nFlags = 0;
        NSEventModifierFlags flags = [theEvent modifierFlags];
        if( (flags & NSControlKeyMask) == NSControlKeyMask)
            nFlags |= MK_CONTROL;
        else
            if( (flags & NSCommandKeyMask) == NSCommandKeyMask)
                nFlags |= MK_COMMAND;
            else
                if( (flags & NSShiftKeyMask) == NSShiftKeyMask)
                    nFlags |= MK_SHIFT;
        
        NSPoint pt = [theEvent locationInWindow];
        NSPoint ptView = [self convertPoint:pt toView:self];
        _pMercuryView->OnMouseMove(nFlags, _Point(ptView.x, [self bounds].size.height - ptView.y));
        NSLog(@"mouse moved1 - buttonNumber %ld", (long)[theEvent subtype]);
    }
    
}

-(void)mouseDragged:(NSEvent *)theEvent
{
    [super mouseDragged:theEvent];
    if(_pMercuryView != NULL)
    {
        int nFlags = MK_LBUTTON;
        NSPoint pt = [theEvent locationInWindow];
        NSPoint ptView = [self convertPoint:pt toView:self];
        _pMercuryView->OnMouseMove(nFlags, _Point(ptView.x, [self bounds].size.height - ptView.y));
    }
    NSLog(@"mouse dragged");
}

-(void)mouseDown:(NSEvent *)theEvent
{
    [super mouseDown:theEvent];
    if(_pMercuryView != NULL)
    {
        int nFlags = 0;
        NSEventModifierFlags flags = [theEvent modifierFlags];
        if( (flags & NSControlKeyMask) == NSControlKeyMask)
            nFlags |= MK_CONTROL;
        else
            if( (flags & NSCommandKeyMask) == NSCommandKeyMask)
                nFlags |= MK_COMMAND;
            else
                if( (flags & NSShiftKeyMask) == NSShiftKeyMask)
                    nFlags |= MK_SHIFT;
        
        NSPoint pt = [theEvent locationInWindow];
        NSPoint ptView = [self convertPoint:pt toView:self];
        _pMercuryView->OnLButtonDown(nFlags, _Point(ptView.x, [self bounds].size.height - ptView.y));
    }

    
    /*
     NSMenu *theMenu = [[NSMenu alloc] initWithTitle:@"Contextual Menu"];
     SEL sel1 = @selector(testItemClick:);
     [theMenu insertItemWithTitle:@"Beep" action:sel1 keyEquivalent:@"" atIndex:0];
     [theMenu insertItemWithTitle:@"Honk" action:@selector(honk:) keyEquivalent:@"" atIndex:1];
     
     [NSMenu popUpContextMenu:theMenu withEvent:theEvent forView:self];
     */
    
    //[_menu showMenu:theEvent forView:self];
}

-(void)mouseUp:(NSEvent *)theEvent
{
    [super mouseUp:theEvent];
    if(_pMercuryView != NULL)
    {
        NSPoint pt = [theEvent locationInWindow];
        NSPoint ptView = [self convertPoint:pt toView:self];
        _pMercuryView->OnLButtonUp(0, _Point(ptView.x, [self bounds].size.height - ptView.y));
    }
}

-(void)rightMouseUp:(NSEvent *)theEvent
{
    [super rightMouseUp:theEvent];
    if(_pMercuryView != NULL)
    {
        NSPoint pt = [theEvent locationInWindow];
        NSPoint ptView = [self convertPoint:pt toView:self];
        _pMercuryView->OnRButtonUp(0, _Point(ptView.x, [self bounds].size.height - ptView.y));
    }
}

@end
