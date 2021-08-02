$inputfile = shift;
$outputfile = shift;
open(input,$inputfile);
undef $/;
$filecontent = <input>;
close(input);
$outfile="B$outputfile";
@basepairs = split(/Base1:/,$filecontent);
open(output,">$outfile");
shift(@basepairs);
$count=0;
foreach $pair (@basepairs)
{
	@details = split(/\s+/,$pair);
	print output "@details[6] @details[19] @details[8]@details[21] @details[27] @details[4]: @details[2] - @details[15] :@details[17] @details[30] @details[33] @details[36] @details[39] @details[42]\n";	
	
}

