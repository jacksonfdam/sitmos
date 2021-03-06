/**
 * Copyright (c) 2012, Tom Diggle
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* */
#define KVO_SET(_key_, _value_) [self willChangeValueForKey:@#_key_]; \
self._key_ = (_value_); \
[self didChangeValueForKey:@#_key_];

/* */
#define kRGBA(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]

/* */
extern NSString * const IGDownloadProgressNotification;

/* */
extern NSString * const IGMediaPlayerPlaybackStatusChangedNotification;
extern NSString * const IGMediaPlayerPlaybackFailedNotification;
extern NSString * const IGMediaPlayerPlaybackEndedNotification;
extern NSString * const IGMediaPlayerPlaybackBufferEmptyNotification;
extern NSString * const IGMediaPlayerPlaybackLikelyToKeepUpNotification;

/* */
extern NSString * const IGSITMOSFeedURL;

/* */
extern NSString * const IGSITMOSErrorDomain;

/* */
extern NSString * const IGDateFormat;

/* Fonts */
extern NSString * const IGFontNameRegular;
extern NSString * const IGFontNameMedium;

/* Settings */
extern NSString * const IGSettingCellularDataStreaming;
extern NSString * const IGSettingCellularDataDownloading;
extern NSString * const IGSettingEpisodesDelete;
extern NSString * const IGSettingUnseenBadge;
