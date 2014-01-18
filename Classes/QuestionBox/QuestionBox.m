//
//  QuestionBox.m
//  myMiku
//
//  Created by bin on 14-1-18.
//
//

#import "QuestionBox.h"


@implementation QuestionBox
@synthesize status = _status;
- (void) hMessageBox:(NSString*)pszMsg title:(NSString*)pszTitle
{
    _status = 0;
    NSString * title = (pszTitle) ? pszTitle : nil;
    NSString * msg = (pszMsg) ? pszMsg : nil;
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:title
                                                        message:msg
                                                       delegate:self
                                              cancelButtonTitle:@"YES"
                                              otherButtonTitles:@"NO", nil];
    
    [alertView autorelease];
    [alertView show];
    

}
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    //NSLog(@"clickButtonAtIndex:%d",buttonIndex);
    if( buttonIndex == 0)
    {
        _status = 1;
    }
    else
        _status = 2;
}


@end
