import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.4
import "qrc:/styles/componentCreation.js" as Style

Item {
	id : base
    visible: true
    width: 600
    height: 400

    property QtObject currentStyle : Style.createStyleObject(base, "qrc:/StyleA.qml");
    property bool bStyle : false;

	Rectangle{
		id:idRect1
		objectName : "objRect1"
		color: "teal"
		height: idButton1.height
		anchors.left : parent.left
		anchors.right : parent.right

		Button {
			id: idButton1
			objectName: "objButton1"
			width: 173
			height: 88
			anchors.right : parent.right
			text: qsTr("txtButton1")
			onClicked:
			{
                if( !bStyle ){
                    currentStyle = Style.createStyleObject(base, "qrc:/StyleB.qml");
                    bStyle = true;
                    console.log("StyleB");
                }
                else{
                    currentStyle = Style.createStyleObject(base, "qrc:/StyleA.qml");
                    bStyle = false;
                    console.log("StyleA");
                }
			}
		}

		Text {
			x: 100
			y: 0
			font.pixelSize: currentStyle.textSize
			color: currentStyle.textColor
			text: "Hello World"
		}
	}
    Rectangle{
        id:idRect2
		objectName : "objRect2"
        color: "plum"
        height:parent.height * 2 / 3
        anchors.left : parent.left
        anchors.right : parent.right
        anchors.top:idRect1.bottom

    }
}