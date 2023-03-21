/* 
 * File:   song.h
 * Author: Tyler
 *
 * Created on March 1, 2022, 7:38 PM
 */

#ifndef SONG_H
#define	SONG_H

#ifdef	__cplusplus
extern "C" {
#endif

void Playsong(const struct note *song, int N);
void PlaySongUnlock();
void PlaySongLock();
void PlaySongFail();



#ifdef	__cplusplus
}
#endif

#endif	/* SONG_H */

