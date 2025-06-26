#ifndef VOLUMEMANAGER_H
#define VOLUMEMANAGER_H

#include <QObject>

class VolumeManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
public:
    static VolumeManager &instance();

    int volume() const { return m_volume; }
    void setVolume(int vol);

signals:
    void volumeChanged(int volume);

private:
    explicit VolumeManager(QObject *parent = nullptr);
    int m_volume = 50;
};

#endif // VOLUMEMANAGER_H
