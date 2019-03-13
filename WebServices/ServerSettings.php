<?php
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	GOAL : Configure your server information
//
//	This file HAS TO BE protected !!
//	IF SOMEONE CAN READ THIS FILE : YOU PROTECTION IS DEAD !
//	.htaccess forbid all access to the entire folder so be caution not to place it elsewhere !
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Your domain
$_SESSION['Domain'] = 'www.thisisnotanumber.org/rastreadoras';
// The folder (or path) where you put the LoginAccount+ProSecure folder (initially : LoginAccount+ProSecure, if you didn't change it)
$_SESSION['SecureLoginFolder'] = 'LoginPro_Server/Game';

// Your host 
$_SESSION['SERVER_host'] = 'internal-db.s112763.gridserver.com'; // Caution : keep 'localhost' EXCEPT if your database server is not on your server (expert only)
// Your username to connect to the database
$_SESSION['SERVER_user'] = 'db112763';
// Your password to connect to the database 
$_SESSION['SERVER_password'] = '@Marzo1981';
// The name of your database
$_SESSION['DB_name'] = 'db112763_LPTestApp';
// The table where your accounts are saved
$_SESSION['questions'] = 'questions';
// The table where your accounts are saved
$_SESSION['answers'] = 'answers';
// The table where your achievements are saved
$_SESSION['tokens'] = 'tokens';

// Your contact email (in case you want to send email validations), players will receive email from this email address (you could create a contact email address for example)
$_SESSION['SERVER_email'] = 'game.email.address@mail.com';
$_SESSION['SERVER_emailPassword'] = 'gameEmailAddressPassword';

// The maximum number of wrong attempts before IP being blocked for an account
$_SESSION['AvailableAttemptsBeforeBlocking'] = 10;

// Scan clients IP
define('SCAN_IP_ACTIVATED', FALSE, TRUE);

?>