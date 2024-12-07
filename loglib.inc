<?php
class Logtype{
    private $type;
    private $filename;
    private $time;

    public function __construct ($type = 'file', $time = true, $filename = 'out.log')
    {
        $this->type = $type;
        $this->time = $time;
        $this->filename = $filename;
    }

    public function setType($type): void
    {
        $this->type = $type;
        return;
    }

    public function getType(): String
    {
        return $this->type;
    }
    
    function setFilename($filename): void
    {
        $this->filename = $filename;
        return;
    }

    public function getFilename(): String
    {
        return $this->filename;
    }

    function setTime($time): void
    {
        $this->time = $time;
        return;
    }

    public function getTime(): bool
    {
        return $this->time;
    }
}

class Log {
    public static function initLoging($log)
    {
        global $txt;
        if ($log->getTime ()) {
            $txt = '---- ' . date('Y/m/d') . ' ' . date('H:i:s') . " ----\r\n";
        } else {
            $txt = '---- ' . date('Y/m/d') . " ----\r\n";
        }
        if ($log->getType() == 'file') {
            global $filename;
            $filename  = $log->getFilename();
            if (!file_exists($filename)) {
                $file = fopen($filename, 'w');
                fclose($file);
            }
            global $file;
            $file  = fopen($filename, 'a');
            fwrite($file, $txt);
            fclose($file);
        } else if ($log->getType() == 'html') {
            echo (nl2br($txt));
        } else if ($log->getType() == 'stdout') {
            print ($txt);
        } else {
            printf ("[ERROR]: %s is an unknown type", $log->getType());
        }
    }

    public static function write ($log, $string, $type)
    {
        global $out;
        if ($log->getTime()) {
            $out = date('H:i:s'). ' ' . self::makeMasage($string, $type) . "\r\n";
        } else {
            $out = self::makeMasage($string, $type) . "\r\n";
        }
        if ($log->getType() == 'file') {
            $file = fopen($log->getFilename(), 'a');
            fwrite ($file, $out);
        } else  if ($log->getType() == 'html') {
            print (nl2br($out));
        } else if ($log->getType() == 'stdout') {
            printf ("%s", $out);
        }  else {
            printf ("[ERROR]: %s is an unknown type", $log->getType());
        }
    }

    private static function makeMasage($string, $type)
    {
        switch ($type) {
        case 'info':
            return '[INFO]: ' . $string;
            break;
        case 'warning':
            return '[WARNING]: ' . $string;
            break;
        case 'error':
            return '[ERROR]: ' . $string;
            break;
        default:
            printf ('[ERROR]: Unknown Masage type: %s', $type);
        }
        return null;
    }
}
