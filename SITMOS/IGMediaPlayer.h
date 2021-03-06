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

@class IGEpisode;

typedef enum {
    IGMediaPlayerPlaybackStateStopped,
    IGMediaPlayerPlaybackStatePlaying,
    IGMediaPlayerPlaybackStatePaused,
    IGMediaPlayerPlaybackStateSeekingForward,
    IGMediaPlayerPlaybackStateSeekingBackward
} IGMediaPlayerPlaybackState;

/**
 * The IGMediaPlayer class provides a centralized point of control for media playing in SITMOS.
 *
 * You can access this object by invoking the sharedInstance class method.
 *
 *      IGMediaPlayer *player = [IGMediaPlayer sharedInstance];
 */

@interface IGMediaPlayer : NSObject

/**
 * The current episode object that is being played.
 */
@property (strong, nonatomic) IGEpisode *episode;

/**
 * The player’s current item. (read-only)
 */
@property (readonly, nonatomic) Float64 currentTime;

/**
 * The player’s duration. (read-only)
 */
@property (readonly, nonatomic) Float64 duration;

/**
 * The current rate of playback.
 *
 * 0.0 means “stopped”, 1.0 means “play at the natural rate of the current item”.
 */
@property (nonatomic) float playbackRate;

/**
 * 
 *
 */
@property (readonly, nonatomic) IGMediaPlayerPlaybackState playbackState;

#pragma mark - Getting the Media Player Instance

/**
 * @name Getting the Media Player Instance
 */

/**
 * Returns the singleton media player instance.
 *
 * @return The media player instance.
 */
+ (IGMediaPlayer *)sharedInstance;

#pragma mark - Managing Playback

/**
 * @name Managing Playback
 */

/** 
 * Starts playback by creating an asset for inspection of a resource referenced by a given URL.
 * @warning *Important:* This method must be called first when wanting to play a new episode.
 */
- (void)start;

/**
 * Begins playback of current episode.
 */
- (void)play;

/**
 * Pauses playback and saves current position.
 */
- (void)pause;

/** 
 * Stops playback, saves current position and sets the player and episode objects to nil.
 */
- (void)stop;

/**
 * Begins playback of the next episode.
 *
 * The next episode is determined by current episode's pubDate.
 */
- (void)playNextEpisode;

/** 
 * Begins playback of the previous episode.
 *
 * If more than 3 seconds of the episode have elapsed then it will re-start from the beginning, otherwise the previous episode (which is determined by the current episode's pubDate) will begin playing.
 */
- (void)playPreviousEpisode;

/**
 * Starts seeking forward through the audio or video medium.
 */
- (void)beginSeekingForward;

/**
 * Starts seeking backward through the audio or video medium.
 */
- (void)beginSeekingBackward;

/**
 * Ends seeking through the audio or video medium.
 */
- (void)endSeeking;

/**
 * Indicates whether the media player is playing.
 *
 * @return YES is media player is playing, NO otherwise.
 */
- (BOOL)isPlaying;

/**
 * Indicates whether the media player is paused.
 *
 * @return YES if media player is paused, NO otherwise.
 */
- (BOOL)isPaused;

#pragma mark - Managing Time

/**
 * @name Managing Time
 */

/**
 * Moves the playback cursor to a given time.
 *
 * @param time The time to which to move the playback cursor.
 */
- (void)seekToTime:(Float64)time;

/**
 * Indicates the duration that is available to play with out buffering.
 *
 * @return The available duration in seconds. 
 */
- (Float64)availableDuration;

@end
