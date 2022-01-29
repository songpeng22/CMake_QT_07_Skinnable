//componentCreation.js

var component;
var sprite;

function createStyleObject(item, stylePath)
{
    component = Qt.createComponent(stylePath);
    if( Component.Ready == component.status ){
        sprite = component.createObject(item);
        console.log("[!!!OK!!!]componentCreation.js:" + stylePath + " component ready");
    }
    else if (Component.Error == component.status)
    {
        console.log("[!!!ERR!!!]componentCreation.js:" + stylePath + " component error " + component.errorString());
    }
    else
        console.log("componentCreation.js:" + stylePath + " component not ready");

    if (sprite === null)
        console.log("componentCreation.js: error creating " + stylePath + " object");
    else
        return sprite;
}

