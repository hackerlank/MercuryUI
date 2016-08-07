//
//  NSViewMy.m
//  OSXWindowEvents
//
//  Created by Zaqro Butskhrikidze on 9/12/14.
//  Copyright (c) 2014 Zaqro Butskhrikidze. All rights reserved.
//

#import "NSViewMy.h"
#include <string>
#include "Controls/MercuryBaseWnd.h"
#include "Controls/ESChildControl.h"
#include "_PlatformCompat/PlatformDeviceContext.h"
#include "Utility/GrowableMemory.h"

@interface NSViewMy()
{
@protected
    _DC         memDC;
    CGImageRef  image;
    MercuryBaseView* _pMercuryView;
}

@end

@implementation NSViewMy


-(id)initWithFrame:(NSRect)frameRect
{
    self = [super initWithFrame:frameRect];
    
    // Code here.
    _pMercuryView = new MercuryBaseView();
    
    return self;
}

-(void)initializeMercuryView:(NSRect)rcView wnd:(NSWindow*)wnd
{
    if( _pMercuryView == NULL )
    {
        /*
        ESChildControlInfo* i1 = new ESChildControlInfo();
        i1->m_nId = 10000;
        i1->m_sName = _T("Name");
        
        EnumerableObject<ESChildControlInfo> arrTest;
        arrTest.CreateVariableIndex(_T("Id"), &Serializable::Compare_Int32);
        arrTest.CreateVariableIndex(_T("Name"), &Serializable::Compare_String);
        arrTest.Add(i1);
        
        int idLookup = 10000;
        arrTest.FindOneVariable(_T("Id"), &idLookup);
        */
        
        //FILE* file = fopen(_T("/Volumes/OSX-DATA/Dev/ESPoker_06.01.2014/_bin/ESPokerClient_Debug/design/Lobby.des"), "r+b");
        _Rect rcDraw(rcView.origin.x, rcView.origin.y, (rcView.origin.x + rcView.size.width), (rcView.origin.y + rcView.size.height));
        _pMercuryView = new MercuryBaseView();
        _pMercuryView->SetHWND(wnd);
        
        MercuryBaseView::Gett();
        
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
        }
                
        _string designFile = _T("design/Lobby.des");
        //_string designFile = _T("/Volumes/OSX/Users/ZqrTalent/Desktop/Dev/design/Lobby.des");
        //_string designFile = _T("/Volumes/OSX-DATA/Dev/ESPoker_06.01.2014/_bin/ESPokerClient_Debug/design/LoginDialog.des");
        _pMercuryView->LoadFromDesignFile(designFile);
        
        [self setNeedsDisplay:YES];
    }
}

-(void)resizeEvent:(NSSize)frameSize
{
    if( _pMercuryView != NULL )
    {
        _pMercuryView->OnSize(0, (int)frameSize.width, (int)frameSize.height);
        [self setNeedsDisplay:YES];
    }
}

-(BOOL)isFlipped
{
    return YES;
}


-(void)drawRect:(NSRect)rect
{
    NSLog(@"redraw %f %f %f %f", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
    
    if( _pMercuryView != NULL )
    {
        CGContextRef context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
        _Rect rcDraw(rect.origin.x, rect.origin.y, (rect.origin.x + rect.size.width), (rect.origin.y + rect.size.height));
        _pMercuryView->OnPaint(context, rcDraw);
    }
    
    
    if( memDC.IsNull() )
    {
        _Rect rcFill1(0, 0, 200, 200);
        _Rect rcFill2(25, 25, 75, 75);
        
        memDC.CreateMemoryBitmapDC(32, 200, 200);
        memDC.FillSolidRect(rcFill1, ARGB(0, 255, 255, 255));
        memDC.FillSolidRect(rcFill2, ARGB(200, 200, 100, 255));
        
        LOGFONT lf;
        memset(&lf, 0, sizeof(LOGFONT));
        strcpy(lf.lfFaceName, "Zapfino");
        lf.lfHeight = 14;
        lf.lfItalic = 1;
        
        _Font font;
        font.CreateFontIndirect(&lf);
        memDC.SelectObject(&font);
        memDC.SetTextColor(ARGB(0, 0, 0, 255));
        
        
        NSString* drawStr = @"სუპ ბოი სუპ ბოი სუპ ბოი სუპ ბოი სუპ ბოი სუპ ბოი";
        //memDC.ExtTextOut(0, 0, 0, _Rect(0, 0, 200, 200), [drawStr cStringUsingEncoding:NSUTF8StringEncoding]);
        
        

        
        
        [NSGraphicsContext saveGraphicsState];
        [NSGraphicsContext setCurrentContext:memDC];
        [font setInContext:memDC];
        
        
        NSDictionary* dict22 = [NSDictionary dictionaryWithObjectsAndKeys:font, NSFontAttributeName,
                               [NSColor greenColor], NSForegroundColorAttributeName,
                               nil, NSBackgroundColorAttributeName,
                               [NSShadow alloc], NSShadowAttributeName,
                               
                               nil];
        
        //[drawStr drawInRect:CGRectMake(25.0, 30.0, 250.0, 50.0) withAttributes:memDC._fontAttributes];
        //[drawStr drawInRect:CGRectMake(15.0, 20.0, 250.0, 50.0) withAttributes:dict22];
        [NSGraphicsContext restoreGraphicsState];
        
        
        
        NSFont* nsfont = [NSFont fontWithName:@"Zapfino" size:14.0];
        //NSGraphicsContext* graphContext = [NSGraphicsContext graphicsContextWithGraphicsPort:memBitmap flipped:YES];
        
        [NSGraphicsContext saveGraphicsState];
        [NSGraphicsContext setCurrentContext:memDC];
        //CGContextSetTextDrawingMode(memBitmap, kCGTextFillClip);
        
        NSSize sz = [drawStr sizeWithAttributes:nil];
        
        [font setInContext:memDC];
        
        NSFontDescriptor* desc = [nsfont fontDescriptor];
        NSDictionary* fontAttr = [desc fontAttributes];
        
        //NSSize sz1 = [drawStr sizeWithAttributes:fontAttr];
        
        //[drawStr drawAtPoint:CGPointMake(15.0, 50) withAttributes:nil];
        
        //NSDictionary* dictAttr = [NSDictionary dictionaryWithObject:nsfont forKey:NSFontAttributeName];
        
        NSDictionary* dict2 = [NSDictionary dictionaryWithObjectsAndKeys:nsfont, NSFontAttributeName,
                               [NSColor greenColor], NSForegroundColorAttributeName,
                               nil, NSBackgroundColorAttributeName,
                               [NSShadow alloc], NSShadowAttributeName,
                               
                               nil];
                                  
        
        //[drawStr drawInRect:CGRectMake(15.0, 20.0, 250.0, 50.0) withAttributes:dict2];
        [NSGraphicsContext restoreGraphicsState];
        
        
        /*
        int width = 200;
        int height = 200;
        size_t bytesPerRow = width * (32/8);
        size_t dataBytesCt = bytesPerRow*height;
        CGColorSpaceRef colorSpace = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
        //It does not works I do not know yet!!!
        //void* data = calloc(dataBytesCt, 0);
        
        CGContextRef context = NULL;
        context = CGBitmapContextCreate(NULL, width, height, 8, bytesPerRow, colorSpace, kCGImageAlphaPremultipliedLast);
        CGColorSpaceRelease(colorSpace);
        
        CGContextSetRGBFillColor(context, 1.0, 0.0, 0.0, 0.5);
        CGContextFillRect(context, CGRectMake(0.0, 0.0, 200, 100));
        
        CGContextFillRect(context, CGRectMake(100.0, 0.0, 200, 100));
        image = CGBitmapContextCreateImage(context);
        //_dibImage = [[NSBitmapImageRep alloc] initWithCGImage:refImg];
        //_context = [NSGraphicsContext graphicsContextWithBitmapImageRep:_dibImage];
         */
    }
    
    //CGContextRef context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
    //CGContextSetRGBFillColor(context, 1.0, 0.0, 0.0, 0.5);
    //CGContextFillRect(context, CGRectMake(0.0, 0.0, 200, 300));
    
    
    //CGContextRef context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
    //CGContextDrawImage(context, CGRectMake(0.0, 0.0, 200, 200), image);

    
    //CGContextRef context = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
    //_DC::DrawDC(context, 0, 0, 200, 200, &memDC, 0, 0, 0);
    }

@end
