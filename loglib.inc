<?php
class Logtype{
    private $type;
    private $filename;

    public function __construct ($type = 'file', $filename = 'out.log')
    {
        $this->type = $type;
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
}

class Log {
    public static function initLoging($log)
    {
        global $txt;
        $txt = '---- ' . date('Y/m/d') . ' ' . date('H:i:s') . " ----\r\n";
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
        $out = date('H:i:s'). ' ' . self::makeMasage($string, $type);
        if ($log->getType() == 'file') {
            $file = fopen($log->getFilename(), 'a');
            fwrite ($file, $out . "\r\n");
        } else  if ($log->getType == 'html') {
            print (nl2br($out . "\r\n"));
        } else if ($log->getType() == 'stdout') {
            printf ("%s\r\n", $out);
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
