# Loglib.inc is a small Logging Libary
this is my first public Github Reposetory if ther is any problem please open an Issue or E-Mail me.
For use look at test.php

## Logtype constructor
```code php
    $log = new Logtype (type, filename);
```

### tyes
- file = seperate file
- html = puts it out in an Html formate
- stdout = put it out formated for the terminal
> The standart is file

### filename
> The standart is out.log

## Use of the Libary
You can use this Libary to output to a seberate file or print it out.
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
