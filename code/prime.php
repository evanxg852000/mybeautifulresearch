<?php
/*
@author evance soumaoro on March 02 2011 at 8:30 pm
@important:
I actually implemeted 2 functions because the question was ambigious for me 
-return prime for 0 to n [is implemeted as get_prime() ]
-return primes from 0 up to n [ is implemeted as get_prime_bis() and uses the first ]
*/

/*
@description return prime numbers in range 0->n
@return array
*/
function get_prime($n){
	$result=array();
	//fill the array with true asuming all elements are prime numbers
	$bitset=array_fill(0,$n,true);
	// 0 is not prime and 1 is prime as we know
	$bitset[0]=false;
	$result[0]=$bitset[1];
	
	//here we performs sieve of erathosthene
	$se=(int)sqrt($n)+1;
	
	//loop to set off the bitsets that don't ..
	for ( $i = 2; $i < $se; $i++ )
	{
      if ( $bitset[$i]===true ) 
      {
         for ( $j = 2 * $i; $j < $n; $j += $i ) 
            $bitset[$j]=false; 
      } 
	} 
	
	//retrieve the result
   for ( $k = 2, $counter = 1; $k <$n ; $k++ )
   {
      if ( $bitset[$k]===true ) {
         $result[]= $k;
      }
   } 
	return $result;
}

/*
@description return n numbers of prime numbers from 0  up to ~n
	this result in a linear growth in term of performence and the algorithm result in : O(n)
	if you have better solution let me know (I am very interested in datastructure & algorithm performence)
@return array
*/
function get_prime_bis($n, $size=100, $factor=1.5){
	if(count(get_prime($size))<$n){
		$s=$size*$factor;
		echo $s;
		return get_prime_bis($n,$s,$factor);
	}
	else if(count(get_prime($size))>$n){
		return array_slice( get_prime($size),0,$n);
	}
	else{
		return get_prime($size);
	}
}

?>


<pre>
<?php 
	echo "1st: call get_prime(56) :";  print_r(get_prime(20));
	echo "\n";
	echo "2nd: call get_prime_bis(6) :" ; print_r(get_prime_bis(6));
?>
</pre>