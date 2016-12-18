/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp org.monkey_business_enterprises.ipcplayer.xml -p ipcplayer_interface
 *
 * qdbusxml2cpp is Copyright (C) 2016 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef IPCPLAYER_INTERFACE_H
#define IPCPLAYER_INTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.mpris.MediaPlayer2.Player
 */
class OrgMprisMediaPlayer2PlayerInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.mpris.MediaPlayer2.Player"; }

public:
    OrgMprisMediaPlayer2PlayerInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgMprisMediaPlayer2PlayerInterface();

    Q_PROPERTY(bool CanControl READ canControl)
    inline bool canControl() const
    { return qvariant_cast< bool >(property("CanControl")); }

    Q_PROPERTY(bool CanGoNext READ canGoNext)
    inline bool canGoNext() const
    { return qvariant_cast< bool >(property("CanGoNext")); }

    Q_PROPERTY(bool CanGoPrevious READ canGoPrevious)
    inline bool canGoPrevious() const
    { return qvariant_cast< bool >(property("CanGoPrevious")); }

    Q_PROPERTY(bool CanPause READ canPause)
    inline bool canPause() const
    { return qvariant_cast< bool >(property("CanPause")); }

    Q_PROPERTY(bool CanPlay READ canPlay)
    inline bool canPlay() const
    { return qvariant_cast< bool >(property("CanPlay")); }

    Q_PROPERTY(bool CanSeek READ canSeek)
    inline bool canSeek() const
    { return qvariant_cast< bool >(property("CanSeek")); }

    Q_PROPERTY(QString LoopStatus READ loopStatus WRITE setLoopStatus)
    inline QString loopStatus() const
    { return qvariant_cast< QString >(property("LoopStatus")); }
    inline void setLoopStatus(const QString &value)
    { setProperty("LoopStatus", QVariant::fromValue(value)); }

    Q_PROPERTY(double MaximumRate READ maximumRate)
    inline double maximumRate() const
    { return qvariant_cast< double >(property("MaximumRate")); }

    Q_PROPERTY(QMap<QString,QVariant> Metadata READ metadata)
    inline QMap<QString,QVariant> metadata() const
    { return qvariant_cast< QMap<QString,QVariant> >(property("Metadata")); }

    Q_PROPERTY(double MinimumRate READ minimumRate)
    inline double minimumRate() const
    { return qvariant_cast< double >(property("MinimumRate")); }

    Q_PROPERTY(QString PlaybackStatus READ playbackStatus)
    inline QString playbackStatus() const
    { return qvariant_cast< QString >(property("PlaybackStatus")); }

    Q_PROPERTY(qlonglong Position READ position)
    inline qlonglong position() const
    { return qvariant_cast< qlonglong >(property("Position")); }

    Q_PROPERTY(double Rate READ rate WRITE setRate)
    inline double rate() const
    { return qvariant_cast< double >(property("Rate")); }
    inline void setRate(double value)
    { setProperty("Rate", QVariant::fromValue(value)); }

    Q_PROPERTY(bool Shuffle READ shuffle WRITE setShuffle)
    inline bool shuffle() const
    { return qvariant_cast< bool >(property("Shuffle")); }
    inline void setShuffle(bool value)
    { setProperty("Shuffle", QVariant::fromValue(value)); }

    Q_PROPERTY(double Volume READ volume WRITE setVolume)
    inline double volume() const
    { return qvariant_cast< double >(property("Volume")); }
    inline void setVolume(double value)
    { setProperty("Volume", QVariant::fromValue(value)); }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
    void Seeked(qlonglong in0);
};

namespace org {
  namespace mpris {
    namespace MediaPlayer2 {
      typedef ::OrgMprisMediaPlayer2PlayerInterface Player;
    }
  }
}
#endif
