# factorial-for-big-numbers


1.0 fact = prev multiplied number
	  num = number to be multiplied with
1.  declare a dynamic string pointer array to the size of the num (in string format.size).
2.  for loop i = from num.size to 0 
	  2.1   for loop j = from fact.size to 0
		          r = int([i] * [j])  + carry
		          if r > 9
		          	  store only r's reminder (in dynamic string)
			            carry = r's quotient
			
			            watch for j = 0 to store r's quotient 
		          else store r 
3.  add each column in dynamic string and store reminder and take carry to nex column addition.
