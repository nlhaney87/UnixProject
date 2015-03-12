#!/usr/bin/perl

$radius = 0.5;
$centerX = 0.5;
$centerY = 0.5;
$score = 0;

if ($#ARGV+1 != 1){
	$total = 10000000;
}
else {
	$total = $ARGV[0];
}

$time = time();

for ($i = 0; $i < $total; $i = $i+1){
	$x = rand();
	$y = rand();

	$calcX = $x-$centerX;
	$calcY = $y-$centerY;

	if (($calcX**2+$calcY**2) < $radius**2){
		$score = $score+1;
	} 

}

$pi = 4.0*$score/$total;
$time = time() - $time;

print "Out of $total randomly generated points, $score of them were within the area of the circle.\n";
print "The estimated value of pi is $pi.\n";
print "It took $time seconds to estimate pi.\n";