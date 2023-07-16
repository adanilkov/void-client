# Void Client

The Void Client is a an injectable client that runs off of the popular Minecraft client, Lunar Client, through the JNI (Java Native Interface). Throughout this project I have delved deeply into reverse engineering and thus have deepened my understanding of lower level programming as well as KM/UM interactions—all though not directly present in this particular project due to several revisions. 

## Project Overview

This project serves as a demonstration of my knowledge and skills in reverse engineering, memory manipulation, and interaction with the Java VM via the JNI. By leveraging the JNI, void is able to interact with Lunar Client at a lower level, enabling the implementation of custom features and functionalities.

These functionalities encompass the fundamental desires of the current playerbase, making it an exceptional lightweight client that caters to the majority of players.

This is an internal client, meaning the rendering of the GUI is done within the minecraft client itself. This is done by hooking to a bug/feature within OpenGL's swapbuffer method, which allows for images to be rendered as an overlay when you create two different contexts and switch between them with the swapbuffer call. 

Please be aware that the code in this repository is not complete for compiling and running the client, as it is currently being offered for sale to a beta grou[. However, I intend to make the client accessible for purchase by the general public soon. Once this becomes available, a website will be provided for further information.
