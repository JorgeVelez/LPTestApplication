# LPTestApplication

Includes a binary for Windows. But can be built copying to the of_v0.9.2_vs_release\apps\myApps\ folder.

WebServices folder includes the php files to run the backend. It is running on my own Apache server with its databases.

The webservices link:

http://thisisnotanumber.org/lp-test/getData.php

Databases:

https://s112763.gridserver.com/.tools/phpMyAdmin/current/

User: db112763_local

pass: @Decoy1234

The current implementation has a very basic UI and implements these functionalities:
* Gets questions from api.
* Displays question by question.
* Starts drawing webcam feed.
* Applyes shader to webcam feed.
* Saves webcam snapshot.

[![Watch the video](http://thisisnotanumber.org/lp-test/screen.PNG)](http://thisisnotanumber.org/lp-test/appstatus.mp4)

To do
* Update database with responses to questions.
* Draw visualization graphics.

## Dependencies

* ofxHttpUtils
* ofxJson

## Compatibility

of_v0.9.2
