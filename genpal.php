<?php

$size = 32;
$im = imagecreatetruecolor(16*$size, $size);

for ($i=0; $i < 16; $i++) { 
    imagefilledrectangle($im, $i*$size, 0, $i*$size+($size-1), $size, getColor($i));
}
imagepng($im, "pal.png");

function getColor($i)
{
    $sat = 0.4;

    $Y = 230 - ((round((($i>>2) & 3) * 255 / 3.7)) & 0xFF);
    $Cb = round(cos(($i&7)/4*M_PI)*$sat*127.5+127.5);
    $Cr = round(sin(($i&3)/2*M_PI)*$sat*127.5+127.5);

    $r = (298.082*$Y)/256 + (408.583*$Cr)/256 - 222.921;
    $g = (298.082*$Y)/256 - (100.291*$Cb)/256 - (208.120*$Cr)/256 + 135.576;
    $b = (298.082*$Y)/256 + (516.412*$Cb)/256 - 276.836;

    $r = max(0,min(255,round($r)));
    $g = max(0,min(255,round($g)));
    $b = max(0,min(255,round($b)));

    echo "$Y $Cb $Cr : $r $g $b\n";

    return $r<<16|$g<<8|$b;
}
