import QtQuick 2.15
import QtQuick.Controls 2.15
import PinVolQt 1.0

ApplicationWindow {
    width: 400
    height: 300
    visible: true
    title: qsTr("PinVolQt")

    Column {
        anchors.centerIn: parent
        spacing: 20
        Slider {
            id: volumeSlider
            from: 0
            to: 100
            value: VolumeManager.volume
            onValueChanged: VolumeManager.volume = value
        }
        Text {
            text: qsTr("Volume: %1").arg(Math.round(VolumeManager.volume))
            font.pointSize: 20
        }
    }
}
