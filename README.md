This prototype is based on two communication technique: QLocalSocket/QLocalServer and QtRemoteObject.

The first technique is used to update the visibility of the inner window. The external window (server) changes the visibility property of the inner one (client) based on events on itself.

The second techinque is used to share a component (a window). The external window share it setting its size and coordinates. From that shared object the inner process can inherit the properties.
The QtRO tecnique used is static and you can notice it moving/resizing the external window.
