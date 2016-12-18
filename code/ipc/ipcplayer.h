/**************************** ipcplayer.h *****************************

Code for the MPRISv2.2 player interface on DBus.  When registered MBMP
will communicate to other processes.  This program this program is 
intitialized and controled from the ipcagetnt.cpp class.

Copyright (C) 2013-2016
by: Andrew J. Bibb
License: MIT 

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"),to deal 
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions: 

The above copyright notice and this permission notice shall be included 
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN THE SOFTWARE.
***********************************************************************/  


# ifndef IPC_PLAYER
# define IPC_PLAYER

# include <gst/gst.h>

# include <QObject>
# include <QtDBus/QDBusContext>
# include <QVariant>
# include <QMap>
# include <QString>
# include <QVector>

# include "./code/resource.h"

# define IPC_INTERFACE_PLAYER "org.mpris.MediaPlayer2.Player"


class IPC_Player : public QObject, protected QDBusContext
{
  Q_OBJECT
  Q_CLASSINFO("D-Bus Interface", IPC_INTERFACE_PLAYER)
    
  public:
    IPC_Player(QObject* parent = 0);
    
    Q_PROPERTY (QString PlaybackStatus READ getPlaybackStatus);		
		Q_PROPERTY (QString LoopStatus	READ getLoopStatus WRITE setLoopStatus);
		Q_PROPERTY (double Rate	READ getPlaybackRate WRITE setPlaybackRate);		
		Q_PROPERTY (bool Shuffle READ getShuffle WRITE setShuffle);
		Q_PROPERTY (QMap<QString,QVariant> Metadata READ getMetadata);		
		Q_PROPERTY (double Volume	READ getVolume WRITE setVolume);		
		Q_PROPERTY (qlonglong Position	READ getPosition);		
		Q_PROPERTY (double MinimumRate READ getMinimumRate);		
		Q_PROPERTY (double MaximumRate READ getMaximumRate);		
		Q_PROPERTY (bool CanGoNext READ getCanGoNext);		
		Q_PROPERTY (bool CanGoPrevious READ getCanGoPrevious);		
		Q_PROPERTY (bool CanPlay READ getCanPlay);		
		Q_PROPERTY (bool CanPause READ getCanPause);		
		Q_PROPERTY (bool CanSeek READ getCanSeek);		
		Q_PROPERTY (bool CanControl READ getCanControl);		
		
	// get functions for memebers
		inline QString getPlaybackStatus() const {return playbackstatus;}
		inline QString getLoopStatus() const {return loopstatus;}
		inline double getPlaybackRate() const {return playbackrate;}
		inline bool getShuffle() const {return shuffle;}
		inline QMap<QString,QVariant> getMetadata() const {return metadata;}
		inline double getVolume() const {return volume;}
		inline qlonglong getPosition() const {return position;}
		inline double getMinimumRate() const {return minimumrate;}	
		inline double getMaximumRate() const {return maximumrate;}
		inline bool getCanGoNext() const {return cangonext;}
		inline bool getCanGoPrevious() const {return cangoprevious;}	
		inline bool getCanPlay() const {return canplay;}
		inline bool getCanPause() const {return canpause;}
		inline bool getCanSeek() const {return canseek;}
		inline bool getCanControl() const {return cancontrol;}

		// set functions for members (most can or will never be used)
		inline void setPlaybackStatus(QString s_ps) {playbackstatus = s_ps; changeditems.append(MBMP_MPRIS::PlaybackStatus); emit propertyChanged();}
		inline void setLoopStatus(QString s_ls) {loopstatus = "HI ANDY"; changeditems.append(MBMP_MPRIS::LoopStatus); emit propertyChanged();}
		inline void setPlaybackRate(double d_r) {playbackrate = d_r; changeditems.append(MBMP_MPRIS::PlaybackRate); emit propertyChanged();}
		inline void setShuffle(bool b_s) {shuffle = b_s; changeditems.append(MBMP_MPRIS::Shuffle); emit propertyChanged();}
		inline void setMetadata(QMap<QString,QVariant>(map)) {metadata = map;changeditems.append(MBMP_MPRIS::Metadata); emit propertyChanged();}
		inline void setVolume(double d_v) {volume = d_v; changeditems.append(MBMP_MPRIS::Volume); emit propertyChanged();}
		inline void setPosition(qlonglong pos) {position = pos;}
		inline void setMinimumRate(double d_mi) {volume = d_mi; changeditems.append(MBMP_MPRIS::MinRate); emit propertyChanged();}
		inline void setMaximumRate(double d_mx) {volume = d_mx; changeditems.append(MBMP_MPRIS::MaxRate); emit propertyChanged();}
		inline void setCanGoNext(bool b_cgn) {cangonext = b_cgn; changeditems.append(MBMP_MPRIS::CanGoNext); emit propertyChanged();}		
		inline void setCanGoPrevious(bool b_cgp) {cangonext = b_cgp; changeditems.append(MBMP_MPRIS::CanGoPrevious); emit propertyChanged();}	
		inline void setCanPlay(bool b_cpl) {canplay = b_cpl; changeditems.append(MBMP_MPRIS::CanPlay); emit propertyChanged();}	
		inline void setCanPause(bool b_cpu) {canpause = b_cpu; changeditems.append(MBMP_MPRIS::CanPause); emit propertyChanged();}	
		inline void setCanSeek(bool b_s) {canseek = b_s; changeditems.append(MBMP_MPRIS::CanSeek); emit propertyChanged();}	
		inline void setCanControl(bool b_ctl) {cancontrol = b_ctl;}	
				
	public Q_SLOTS:
		void sendPropertyChanged();
	
	Q_SIGNALS:
		Q_SCRIPTABLE void Seeked(qlonglong);
		void propertyChanged();
		
	private:
		// data members
		QString playbackstatus;
		QString loopstatus;
		double playbackrate;
		bool shuffle;
		QMap<QString,QVariant> metadata;
		double volume;
		qlonglong position;
		double minimumrate;
		double maximumrate;
		bool cangonext;
		bool cangoprevious;
		bool canplay;
		bool canpause;
		bool canseek;
		bool cancontrol;
		
		QVector<int> changeditems;
};  

#endif
