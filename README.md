# Loglib.inc is a small Logging Libary
this is my first public Github Reposetory if ther is any problem please open an Issue or E-Mail me.
For use look at test.php

## Use of the Libary
You can use this Libary to output to a seberate file or print it out.
You start by making an Logtype Object witch you have to add to all the static Log functions to be able tu  use them.
### make a log file
```code php
include ('loglib.inc');
$log = new Logtype('file', 'out.log');
Log::initLoging($log);
```
### stdout
``` code php
include ('loglib.inc');
$log = new Logtype('stdout');
Log::initLoging($log);
```

## Functions of the class Logs
```code php
Log::initLoging(log Object); #is used to make the Log file if it dos not exist already and prints an seperator with the time it was started
Log::write(log Object, Logtext, Logtype); #is used to write an log masage in format of Time, Type and then the masage
```

### Logtypes
Logtypes are the diverent levels of the loging libary, curently there are he following types:
- info
- warning
- error

## Logtype constructor
```code php
$log = ew Logtype (type, filename);
```

### tyes
- file = seperate file
- html = puts it out in an Html formate
- stdout = put it out formated for the terminal
> The standart is file

### filename
> The standart is out.log
