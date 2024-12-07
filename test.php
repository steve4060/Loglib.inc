<?php
include ('loglib.inc');
$log = new Logtype('file', false);
$log2 = new Logtype('file');
Log::initLoging($log);
Log::write($log, 'Info test', 'info');
Log::write($log, 'Warning test', 'warning');
Log::write($log, 'Error test', 'error');

Log::initLoging($log2);
Log::write($log2, 'Info test', 'info');
Log::write($log2, 'Warning test', 'warning');
Log::write($log2, 'Error test', 'error');
?>
