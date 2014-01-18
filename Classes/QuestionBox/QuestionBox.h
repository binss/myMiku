//
//  QuestionBox.h
//  myMiku
//
//  Created by bin on 14-1-18.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>



@interface QuestionBox : UIViewController<UIAlertViewDelegate>
@property (nonatomic) int status;
- (void) hMessageBox:(NSString*)pszMsg title:(NSString*)pszTitle;
- (void) alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;

@end
