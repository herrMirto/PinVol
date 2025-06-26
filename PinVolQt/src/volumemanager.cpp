#include "volumemanager.h"
#include <QAudio>
#ifdef Q_OS_WIN
#include <windows.h>
#endif

VolumeManager &VolumeManager::instance()
{
    static VolumeManager mgr;
    return mgr;
}

VolumeManager::VolumeManager(QObject *parent)
    : QObject(parent)
{
}

void VolumeManager::setVolume(int vol)
{
    vol = qBound(0, vol, 100);
    if (m_volume == vol)
        return;
    m_volume = vol;
    // TODO: integrate with platform-specific volume APIs or Qt Multimedia
    emit volumeChanged(m_volume);
}
