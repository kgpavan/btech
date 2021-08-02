#===================================================================================================
#Input PDB file
#output model_1.out with the coordinates of the pdb file
#====================================================================================================

$pdbFile = shift; 
open(input,$pdbFile) || die usage();
undef $/;
$fileContent = <input>;
close(input);
$count=0;
@check_model=split(/\n/,$fileContent);
for $check (@check_model)
{
	@line=split(/\s+/,$check);
	if(@line[0] =~ /MODEL/)
	{
		$count++;
	}
}
if($count == 0)
{
	@models=$fileContent;
}
else
{
	@models=split(/MODEL/,$fileContent);
	shift(@models);
	while( $count != @models)
	{
		shift(@models);
	}
}
$count=1;	
for $model (@models)
{
	$outFile="model_$count.out";
	open(output ,">$outFile");
	print output "MODEL $count\n";
	$count++;
	@atoms = split(/\n/,$model); #splits model on the bais of atoms
	shift(@atoms);  # first element of atoms array will be model number, therefore deleting it
	$newBaseNum="";
	$oldBaseNum="";
	$chainNameOld="";
	$chainNameNew="";
	foreach $atom (@atoms)
	{
		@atomDetails = split(//,$atom);
		$newLine = "";
		$atomName = "";
		$newBaseNum="";
		$baseName="";
		$chainNameNew="";
		$baseType="";
		for($i=0;$i<6;$i++)
		{
			$newLine=$newLine.$atomDetails[$i];
		}
		if(not($newLine =~ /ATOM\s+/ || $newLine =~ /HETATM/))
		{
			next;
		}
		for($i=22;$i<30;$i++) #taking out the residue no from the file
		{
			$newBaseNum=$newBaseNum.$atomDetails[$i];
		}
		for($i=17;$i<20;$i++) #taking out the bse type of the residue
		{
			$baseName=$baseName.$atomDetails[$i];
		}
		$baseType=base_category($baseName);
		if($baseType == 2)
		{
			next;
		}
		for($i=12;$i<16;$i++) #taking out the name of the atom
		{
			$atomName=$atomName.$atomDetails[$i];
		}
		$alternatelocation=$atomDetails[16];
		$chainNameNew=$atomDetails[21];
		$val=validAtomName($atomName,$baseType,$alternatelocation);
		if($val) #selecting atom for ewach base type to make a quad
		{
			if($chainNameOld ne $chainNameNew || $newBaseNum ne $oldBaseNum) #if new base comes
			{
				$oldBaseNum=$newBaseNum;
				$chainNameOld=$chainNameNew;
				print output "-----------\n";
				print output "BaseNum: $newBaseNum\nChain: $chainNameNew\nBaseType: $baseType\nBase: $baseName\n"
			}
			$newLine=$newLine.$atomName." ";
			for($i=30;$i<38;$i++) #taking out the coordinates of the atom
			{
				$newLine=$newLine.$atomDetails[$i];
			}
			$newLine=$newLine." ";
			for($i=38;$i<46;$i++)
			{
				$newLine=$newLine.$atomDetails[$i];
			}
			$newLine=$newLine." ";
			for($i=46;$i<54;$i++)
			{
				$newLine=$newLine.$atomDetails[$i];
			}
			print output "$newLine\n"; #printing the details of selected atom for each base in the output file.		
		}
	}
	print output "-----------\n";
	print output "===========================================================================\n"; #to end atoms for single model
	close(output);
}
sub base_category # function to determine which atom to take for which base to form the quad
{
	my $base=shift; #the base type
		if($base =~/\s+A/||$base=~/ADE/||$base=~/1MA/||$base=~/MIA/||$base=~/\s\+A/||$base=~/AMP/||$base=~/AMO/||$base=~/12A/||$base=~/ATP/||$base=~/AET/||$base=~/PSD/||$base=~/AVC/||$base=~/APC/||$base=~/GOM/||$base=~/MAD/||$base=~/\s+DA/) 
		{
			return 'A';
		}
	elsif($base =~/\s+G/||$base=~/GUA/||$base=~/2MG/||$base=~/M2G/||$base=~/OMG/||$base=~/G7M/||$base=~/GNP/||$base=~/QUO/||$base=~/7MG/||$base=~/1MG/||$base=~/5CG/||$base=~/\s+DG/)
	{
		return 'G';
	}
	elsif($base =~ /\s+C/||$base=~/CYT/||$base=~/5MC/||$base=~/OMC/||$base=~/\s\+C/||$base=~/\s+DC/)
	{
		return 'C';
	}
	elsif($base =~ /\s+U/||$base=~/URA/||$base=~/PSU/||$base=~/H2U/||$base=~/5MU/||$base=~/2MU/||$base=~/4SU/|| $base=~/OMU/||$base=~/7OU/||$base=~/\s\+U/||$base=~/DHU/||$base=~/UR3/||$base=~/\sRT/)
	{
		return 'U';
	}
	elsif($base =~/\s+T/||$base=~/\s+DT/)
	{
		return 'T';
	}	
	else 
	{
		return 2;
	}
}
sub validAtomName # function to determine which atom to take for which base to form the quad
{
	$_=shift; # the atom name
	my $base=shift; #the base type
	my $location=shift;
	if(not($location =~/A/ || $location =~/\s+/) )
	{
		return 0;
	}
	if($base =~/A/) 
	{
		if(/\sC2\s/ || /\sN6\s/ || /\sN7\s/ || /\sN9\s/ || /\sC1\*/ || /\sC1'/ || /\sP\s+/ || /\sC4\*/ || /\sC4'/|| /\sO4\*/ || /\sO4'/ || /\sC4\s/ || /\sO1P/ || /\sO2P/ || /\sO5\*/ || /\sO5'/ || /\sC3\*/ || /\sC3'/ || /\sC2\*/ || /\sC2'/)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	elsif($base =~/G/)
	{
		if(/\sN2\s/ || /\sO6\s/ || /\sN7\s/ || /\sN9\s/ || /\sC1\*/ || /\sC1'/ || /\sP\s+/ || /\sC4\*/ || /\sC4'/ || /\sO4\*/ || /\sO4'/ || /\sC4\s/ || /\sO1P/ || /\sO2P/ || /\sO5\*/ || /\sO5'/ || /\sC3\*/ || /\sC3'/ || /\sC2\*/ || /\sC2'/ ) 
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	elsif($base =~/C/)
	{
		if(/\sO2\s/ || /\sN4\s/ || /\sC6\s/ || /\sN1\s/ || /\sC1\*/ || /\sC1'/ || /\sP\s+/ || /\sC4\*/ || /\sC4'/ || /\sO4\*/ || /\sO4'/ || /\sC2\s/ || /\sO1P/ || /\sO2P/ || /\sO5\*/ || /\sO5'/ || /\sC3\*/ || /\sC3'/ || /\sC2\*/ || /\sC2'/)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	elsif($base=~/U/)
	{
		if(/\sO2\s/ || /\sO4\s/ || /\sC6\s/ || /\sN1\s/ || /\sC1\*/ || /\sC1'/ || /\sP\s+/ || /\sC4\*/ || /\sC4'/ || /\sO4\*/ || /\sO4'/ || /\sC2\s/ || /\sO1P/ || /\sO2P/ || /\sO5\*/ || /\sO5'/ || /\sC3\*/ || /\sC3'/ || /\sC2\*/ || /\sC2'/)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	elsif($base=~/T/)
	{
		if(/\sO2\s/ || /\sO4\s/ || /\sC6\s/ || /\sN1\s/ || /\sC1\*/ || /\sC1'/ || /\sP\s+/ || /\sC4\*/ || /\sC4'/ || /\sO4\*/ || /\sO4'/ || /\sC2\s/ || /\sO1P/ || /\sO2P/ || /\sO5\*/ || /\sO5'/ || /\sC3\*/ || /\sC3'/ || /\sC2\*/ || /\sC2'/)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
}
sub usage
{
	print "[Usage] : extract_coord_new.pl\n";
	print "          perl extract_coord_new.pl <input pdb file>\n";
	print "          Filenames can have relative paths\n";
	print "          Line below gives you information on where the code broke\n";
}
