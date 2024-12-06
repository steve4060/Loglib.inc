<?php
include ('loglib.inc');
$log = new Logtype('file');
Log::initLoging($log);
Log::write($log, 'test', 'info')
?>
