# Void Client

The Void Client is a an injectable client that runs off of the popular Minecraft client, Lunar Client, through the JNI (Java Native Interface). Throughout this project I have delved deeply into reverse engineering and thus have deepened my understanding of lower level programming as well as KM/UM interactions—all though not directly present in this particular project due to several revisions. 

## Project Overview

This project serves as a demonstration of my knowledge and skills in reverse engineering, memory manipulation, and native interaction with the JNI. By leveraging the JNI, void is able to interact with Lunar Client at a lower level, enabling the implementation of custom features and functionalities.

These functionalities include most of the base level desires of the current playerbase, and therefore making it a great ligthweight client for the majority of players. 

This is an internal client, meaning the rendering of the GUI is done within the minecraft client itself. This is done by hooking to a bug/feature within OpenGL's swapbuffer method, which allows for images to be rendered as an overlay when you create two different contexts and switch between them with the swapbuffer call. 

Note, this repository does not have all the code necessary to compile and run the client as this is something that I am currently working on and have plans on creating a website and selling subscriptions to this client. Once it is available, the link will be included, and the full client will be pruchaseable. 
